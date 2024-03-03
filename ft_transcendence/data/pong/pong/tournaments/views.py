from django.conf import settings
from django.core import management
from django.utils import timezone

from rest_framework.decorators import api_view
from rest_framework.response import Response
from rest_framework.generics import ListAPIView, RetrieveAPIView, CreateAPIView
from rest_framework import filters
from rest_framework import pagination

from tournaments.models import Tournament, ParticipantTournament, StatsTournament
from tournaments.filters import MyFilterBackend
from tournaments.serializers import (
    TournamentSerializer,
    ParticipantTournamentSerializer,
    serialize_tournament_matches
)

from users.models import PongUser, Game
from users.utils import Results

from pong.producers import NotificationProducer

from operator import attrgetter

import logging
import json
import math
import time
import threading

logger = logging.getLogger(__name__)


class MyPageNumberPagination(pagination.PageNumberPagination):
    page_size = 10
    page_size_query_param = 'size'
    max_page_size = 10


class ListTournament(ListAPIView):
    queryset = Tournament.objects.all()
    serializer_class = TournamentSerializer
    pagination_class = MyPageNumberPagination
    permission_classes = []
    filter_backends = [MyFilterBackend, filters.OrderingFilter]
    search_fields = ["finished", "title", "participants"]
    ordering_filters = ["title"]


class RetrieveTournament(RetrieveAPIView):
    queryset = Tournament.objects.all()
    permission_classes = []
    serializer_class = TournamentSerializer
    lookup_field = "id"


class CreateTournament(CreateAPIView):
    queryset = Tournament.objects.all()
    permission_classes = []
    serializer_class = TournamentSerializer

    def create(self, request, *args, **kwargs):
        player = request.pong_user
        if player is None:
            return Response({"message": "User not found"}, status=404)

        # call the create method and return error if needed
        response = super().create(request, *args, **kwargs)
        if response.status_code != 201:
            return response

        # register user to tournament
        tournament = Tournament.objects.get(pk=response.data["id"])
        game = Game.objects.create()
        display_name = request.data.get("display_name", "player")
        participant_tournament = ParticipantTournament.objects.create(1, player, tournament, game, display_name=display_name)
        ParticipantTournament.objects.update_column(participant_tournament, 1)
        
        # update the subscribed field in the response
        tour = Tournament.objects.get(pk=response.data["id"])
        response.data["subscribed"] = tour.get_subscribed()
        return response


@api_view(["GET"])
def check_tournaments(request):
    tournaments = Tournament.objects.filter(start_date__lte=timezone.now(), started=False)
    for tournament in tournaments:
        if tournament.is_full():
            # start tournament
            Tournament.objects.start_tournament(tournament)
            # logger.warning("STARTING TOURNAMENT {tournament.name}")
            thread = threading.Thread(target=tournament_loop, kwargs={"tournament": tournament})
            thread.start()

        else:
            # send a message to subscribed users that the tournament will be deleted
            # logger.warning("DELETING TOURNAMENT {tournament.name}")
            participants = tournament.participant.all()
            games = []
            for participant in participants:
                body = {"receiver": participant.player_id, "body": f"Tournament: {tournament.name} has been deleted"}
                NotificationProducer().publish(method="info_ntf", body=json.dumps(body))
                if participant.game_id not in games:
                    games.append(participant.game)
            # TODO: delete all games
            for game in games:
                game.delete()
            tournament.delete()
    return Response(status=200)


@api_view(["GET"])
def get_tournament_matches(request):
    player = request.pong_user
    if player is None:
        return Response({"message": "User not found"}, status = 404)

    # get participants entities
    parts = player.participant_tournament.all()
    # get all games and sort
    games = [part.game for part in parts]
    games = sorted(games, key=attrgetter("created"), reverse=True)
    # get sorted parts
    parts = [game.participant_tournament.filter(player_id = player.username).first() for game in games]
    # get sorted opponents
    opponents = [game.participant_tournament.exclude(player_id = player.username).first() for game in games]

    # serialize data
    data = serialize_tournament_matches(parts, opponents, games)

    return Response(data, status=200)


@api_view(['GET'])
def get_tournament(request, tournament_id):
    try:
        tournament = Tournament.objects.get(pk=tournament_id)
    except Tournament.DoesNotExist:
        return Response({"message": "Tournament not found"}, status=404)
    participants_num = tournament.participants_num
    data = []
    level = 1
    while 2 ** (level - 1) <= participants_num:
        layer = tournament.participant.filter(level=level).order_by("column")
        data.append(ParticipantTournamentSerializer(layer, many=True).data)
        #fill_empty
        for i in range(1, participants_num // (2 ** (level - 1)) + 1):
            try:
                if data[level - 1][i - 1]["column"] == i:
                    continue
                data[level - 1].insert(i - 1, {"empty": True})
            except IndexError:
                data[level - 1].insert(i - 1, {"empty": True})
        level += 1
    data[-1][0]["winner"] = True
    return Response(data, status=200)



@api_view(['POST'])
def unregister_tournament(request):
    player = request.pong_user
    if player is None:
        return Response({"message": "User not found"}, status=404)

    # retrieve tournament from db
    tournament_id = request.data.get('tournament_id', -1)
    try:
        tournament = Tournament.objects.get(pk=tournament_id)
    except Tournament.DoesNotExist:
        return Response({"message": "Tournament  not found"}, status=404)

    # check if player is subscribed
    if player.username not in tournament.get_participants():
        return Response({"message": "You're already not registered"}, status=400)

    # check if tournament is full
    if tournament.is_full():
        return Response({"message": "Tournament is full, cannot unregister now"}, status=400)
    
    # get participants and the one that will be deleted
    participant_to_del = tournament.participant.get(level=1, player=player)
    participants = tournament.participant.filter(level=1).order_by("column")

    # delete participant from tournament
    delete_participant_from_list(participant_to_del, participants)

    return Response({"message": "Successfully unregistered"}, status=200)


@api_view(['POST'])
def register_tournament(request):
    player = request.pong_user
    if player is None:
        return Response({"message": "User not found"}, status=404)

    # retrieve tournament from db
    tournament_id = request.data.get('tournament_id', -1)
    try:
        tournament = Tournament.objects.get(pk=tournament_id)
    except Tournament.DoesNotExist:
        return Response({"message": "Tournament  not found"}, status=404)

    # check if player is subscribed
    if player.username in tournament.get_participants():
        return Response({"message": "You're already registered"}, status=400)

    # check if tournament is full
    if tournament.is_full():
        return Response({"message": "Tournament is full"}, status=400)

    # get or create a new game
    num_participants = tournament.get_subscribed()
    if num_participants % 2 == 0:
        game = Game.objects.create()
    else:
        try:
            game = tournament.participant.get(level=1, column=num_participants).game
        except ParticipantTournament.DoesNotExist:
            Response({"message": "This message doesn't should be seen"}, status=500)
            

    # create participant and add to tournament
    display_name = request.data.get("display_name", "player")
    participant_tournament = ParticipantTournament.objects.create(1, player, tournament, game, display_name=display_name)
    ParticipantTournament.objects.update_column(participant_tournament, num_participants + 1)

    return Response(TournamentSerializer(tournament).data, status=200)


def tournament_loop(tournament):
    level = 0
    while tournament.participants_num != (2 ** level):
        level += 1
        Tournament.objects.start_tournament_level(tournament, level)
        participants = tournament.participant.filter(level=level).order_by("column")
        # wait that everyone is connected
        time.sleep(settings.TOURNAMENT_INTERVAL)
        # delete all tickets from database
        delete_tournament_tickets(participants)
        # wait that everyone played
        time.sleep(settings.TOURNAMENT_GAME_TIME + 10)
        #logger.warning(f"PARTICIPANTS BEFORE CHECK: {participants}")
        # get info about games and create the new participants
        for i in range(math.ceil(participants.count() / 2)):
            # get users
            user_1, user_2 = get_adjancent_users(participants, (i * 2 + 1))

            if user_1 is None and user_2 is None:
                #logger.warning("PARTICIPANTS NOT FOUND")
                continue

            elif user_1 is None or user_2 is None:
                #logger.warning("ONLY ONE PARTICIPANT NOT FOUND")
                user = user_1 or user_2
                # create stats for this user
                stats = StatsTournament.objects.create(user, 0, Results.WIN)
                # create a new participant for the next level
                create_new_participant(tournament, user, level + 1, i + 1)

            else:
                # check the stats
                #logger.warning("PARTICIPANTS FOUND")
                user = check_stats(user_1, user_2)
                if user is None:
                    continue
                # create a new participant for the next level
                create_new_participant(tournament, user, level + 1, i + 1)
        #participants = tournament.participant.filter(level=level + 1).order_by("column")
        #logger.warning(f"PARTICIPANTS IN THREAD {participants}")

    logger.warning(f"LEVEL: {level}")
    winner = ParticipantTournament.objects.filter(level=level + 1, tournament_id=tournament.id)
    logger.warning(f"WINNER: {winner}")
    if winner:
        ParticipantTournament.objects.update_winner(winner.first(), True)

    # end tournament
    Tournament.objects.end_tournament(tournament, level + 1)


def get_adjancent_users(participants, column: int) -> tuple[ParticipantTournament, ParticipantTournament]:
    try:
        user_1 = participants.get(column=column)
    except ParticipantTournament.DoesNotExist:
        user_1 = None
    try:
        user_2 = participants.get(column=(column + 1))
    except ParticipantTournament.DoesNotExist:
        user_2 = None
    return user_1, user_2


def create_new_participant(tournament: Tournament, user: ParticipantTournament, level: int, column: int) -> ParticipantTournament:
    # get game from the previous participant or create a new one
    if column % 2 == 1:
        game = Game.objects.create()
    else:
        try:
            game = tournament.participant.get(level=level, column=(column - 1)).game
        except ParticipantTournament.DoesNotExist:
            game = Game.objects.create()
    # create a new participant for the next level
    participant = ParticipantTournament.objects.create(level, user.player, tournament, game, display_name=user.display_name)
    ParticipantTournament.objects.update_column(participant, column)
    return participant


def check_stats(user_1: ParticipantTournament, user_2: ParticipantTournament) -> ParticipantTournament:
    # check the stats
    try:
        stats = StatsTournament.objects.get(participant=user_1)
    except StatsTournament.DoesNotExist:
        stats = None

    if stats is None:
        # someone didn't connect, check who
        logger.warning("STATS NOT FOUND")
        if not user_1.entered and not user_2.entered:
            user = None
        else:
            user = user_1 if user_1.entered else user_2
            # create stats for this user
            stats = StatsTournament.objects.create(user, 0, Results.WIN)

    elif stats.result == Results.DRAW:
        logger.warning("DRAW NOBODY WON")
        user = None

    else:
        # check who won the game
        logger.warning("SOMEONE WON")
        user = user_1 if stats.result == Results.WIN else user_2
        logger.warning(f"WINNER: {user.player.username}")

    return user


def delete_tournament_tickets(participants):
    for participant in participants:
        PongUser.objects.delete_tournament_ticket(participant.player)
        logger.warning(f"PARTICIPANT: {participant.player_id}, TOKEN: {participant.player.tournament_ticket}")


def delete_participant_from_list(participant_to_del, participants):
    column = participant_to_del.column

    # if the participant is the last one and his game is not shared, delete the game 
    if participant_to_del.player.username == participants.last().player.username and column % 2 == 1:
        participant_to_del.game.delete()

    # if the participant is the last one and his game is shared, delete the participant
    elif participant_to_del.player.username == participants.last().player.username:
        participant_to_del.delete()

    # else traslate and delete the participant
    else:
        game = participant_to_del.game
        for participant in participants[column:]:
            if game.id == participant.game.id:
                ParticipantTournament.objects.update_column(participant, participant.column - 1)
                continue
            next_game = participant.game
            ParticipantTournament.objects.update_game(participant, game)
            ParticipantTournament.objects.update_column(participant, participant.column - 1)
            game = next_game
        if participants.count() % 2 == 1:
            game.delete()
        participant_to_del.delete()

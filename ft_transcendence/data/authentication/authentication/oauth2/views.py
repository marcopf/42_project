
from django.core.exceptions import ValidationError
from django.conf import settings

from rest_framework import status
from rest_framework.decorators import APIView, api_view, permission_classes
from rest_framework.response import Response

from authorization.views import get_exp
from .models import IntraUser, GoogleUser

from users.models import User

from authorization.serializers import TokenPairSerializer

from secrets import token_urlsafe
from datetime import datetime
from urllib.parse import quote
from jwt import decode
import requests
import logging


logger = logging.getLogger(__name__)


@api_view(['GET'])
def is_user_linked(request) -> Response:
    user: User = request.user
    return Response(data={
        'intra': user.has_intra(),
        'google': user.has_google()
    }, status=200)


@api_view(['GET'])
@permission_classes([])
def v2_intra_get_url(request) -> Response:
    state = token_urlsafe(32)
    url = (
        f"{settings.OAUTH2['INTRA']['AUTH']}?"
        f"client_id={quote(settings.OAUTH2['INTRA']['ID'])}&"
        f"redirect_uri={quote(settings.OAUTH2['INTRA_REDIRECT_URI'])}&"
        f"response_type={quote(settings.OAUTH2['response_type'])}&"
        f"state={state}"
    )
    return Response(data={'url': url, 'intra_state': state}, status=200)


@api_view(['POST'])
@permission_classes([])
def v2_intra_login(request) -> Response:
    request_body = settings.OAUTH2['INTRA_REQUEST_BODY'].copy()
    request_body['code'] = request.data['code']
    request_body['state'] = request.data['state']
    api_response = requests.post(settings.OAUTH2['INTRA']['TOKEN'], data=request_body)
    if api_response.status_code != 200:
        return Response(data=api_response.json(), status=502)
    data = api_response.json()
    headers = {'Authorization': f"Bearer {data['access_token']}"}
    api_response = requests.get(settings.OAUTH2['INTRA']['INFO'], headers=headers)
    if api_response.status_code != 200:
        return Response(data=api_response.json(), status=502)
    email = api_response.json()['email']
    del api_response
    try:
        user = IntraUser.objects.get(email=email).user
    except IntraUser.DoesNotExist:
        return Response(data={'message': 'user not found'}, status=404)
    refresh_token = TokenPairSerializer.get_token(user)
    return Response(data={
        'access_token': str(refresh_token.access_token),
        'refresh_token': str(refresh_token),
        'exp': get_exp(refresh_token).seconds,
        'username': user.username,
    }, status=200)


@api_view(['POST'])
def v2_intra_link(request) -> Response:
    user: User = request.user
    if user.has_intra():
        return Response(data={'message': 'user already linked'}, status=400)
    request_body = settings.OAUTH2['INTRA_REQUEST_BODY'].copy()
    request_body['code'] = request.data['code']
    request_body['state'] = request.data['state']
    api_response = requests.post(settings.OAUTH2['INTRA']['TOKEN'], data=request_body)
    if api_response.status_code != 200:
        return Response(data=api_response.text, status=502)
    data = api_response.json()
    headers = {'Authorization': f"Bearer {data['access_token']}"}
    api_response = requests.get(settings.OAUTH2['INTRA']['INFO'], headers=headers)
    if api_response.status_code != 200:
        return Response(data=api_response.text, status=502)
    email = api_response.json()['email']
    del api_response
    try:
        user = IntraUser.objects.create(user=user, email=email).user
    except ValidationError:
        return Response(data={'message': 'intra account already linked to another user'}, status=400)
    except ValueError as e:
        return Response(data={'message': str(e)}, status=404)
    if user.email == email:
        User.objects.update_verified(user, True)
    return Response(status=200)


class IntraLink(APIView):
    def delete(self, request) -> Response:
        user = request.user
        if not user.has_intra():
            return Response(data={'message': 'account not linked'}, status=400)
        try:
            user.user_intra.delete()
        except Exception as e:
            # logger.warning(f"\nexception: {str(e)}\n")
            return Response(data={'message': str(e)}, status=400)
        return Response(status=200)


@api_view(['GET'])
@permission_classes([])
def get_google_url(request) -> Response:
    state = token_urlsafe(32)
    url = (
        f"{settings.OAUTH2['GOOGLE']['AUTH']}?"
        f"client_id={quote(settings.OAUTH2['GOOGLE']['ID'])}&"
        f"response_type={quote(settings.OAUTH2['response_type'])}&"
        f"scope={quote(settings.OAUTH2['google_scope'])}&"
        f"redirect_uri={quote(settings.OAUTH2['GOOGLE_REDIRECT_URI'])}&"
        f"state={state}"
    )
    response = Response(data={'url': url, 'state': state}, status=200)
    return response


class GoogleLink(APIView):
    def post(self, request) -> Response:
        request_body = settings.OAUTH2['GOOGLE_REQUEST_BODY'].copy()
        request_body['code'] = request.data.get('code')
        if request.data.get('state') != request.COOKIES.get('google_state'):
            return Response(data={'message': 'csrf suspected'}, status=403)
        user: User = request.user
        if user.has_google():
            return Response(data={'message': 'user already linked'}, status=400)
        api_response = requests.post(settings.OAUTH2['GOOGLE']['TOKEN'], data=request_body)
        if api_response.status_code != 200:
            return Response(data={
                'status': api_response.status_code,
                'error': f"{api_response.json()}",
            }, status=status.HTTP_503_SERVICE_UNAVAILABLE)
        payload = decode(api_response.json()['id_token'], options={"verify_signature": False})
        try:
            user = GoogleUser.objects.create(user=user, email=payload['email']).user
        except ValidationError:
            return Response(data={'message': 'google account already linked to another user'}, status=400)
        except Exception as e:
            logger.warning(f"\nexception: {str(e)}\n")
            return Response(data={'message': 'server error'}, status=500)
        if user.email == payload['email']:
            User.objects.update_verified(user, True)
        return Response(status=200)

    def delete(self, request) -> Response:
        user: User = request.user
        if not user.has_google():
            return Response(data={'message': 'user not linked'}, status=400)
        user.user_google.delete()
        return Response(status=200)


@api_view(['POST'])
@permission_classes([])
def google_login(request) -> Response:
    request_body = settings.OAUTH2['GOOGLE_REQUEST_BODY'].copy()
    request_body['code'] = request.data.get('code')
    if request.data.get('state') != request.COOKIES.get('google_state'):
        response = Response(data={'message': 'csrf suspected'}, status=403)
        response.set_cookie(key='google_state', value='deleted', max_age=0)
        return response
    api_response = requests.post(settings.OAUTH2['GOOGLE']['TOKEN'], data=request_body)
    if api_response.status_code != 200:
        response = Response(data={
            'status': api_response.status_code,
            'error': f"{api_response.json()}",
        }, status=503)
        response.set_cookie(key='google_state', value='deleted', max_age=0)
        return response
    payload = decode(api_response.json()['id_token'], options={"verify_signature": False})
    try:
        user_intra = GoogleUser.objects.get(email=payload['email'])
    except GoogleUser.DoesNotExist:
        response = Response(data={'user not found'}, status=404)
        response.set_cookie(key='google_state', value='deleted', max_age=0)
        return response
    refresh_token = TokenPairSerializer.get_token(user_intra.user)
    exp = datetime.fromtimestamp(refresh_token['exp'], tz=settings.TZ) - datetime.now(tz=settings.TZ)
    response = Response(data={
        'access_token': str(refresh_token.access_token),
        'refresh_token': str(refresh_token),
        'exp': get_exp(refresh_token).seconds,
        'username': user_intra.user.username,
    }, status=200)
    return response


from rest_framework.decorators import APIView, api_view, permission_classes, throttle_classes
from rest_framework.response import Response

from django.core.exceptions import ValidationError

from authorization.views import get_exp
from two_factor_auth.models import UserTFA, OtpCode, TFATypes

from authorization.serializers import TokenPairSerializer

import logging


logger = logging.getLogger(__name__)


class ManageView(APIView):
    def get(self, request) -> Response:
        user_tfa = request.user.user_tfa
        return Response(data=user_tfa.to_data(), status=200)

    def post(self, request) -> Response:
        tfa_type = request.data.get('type', '').upper()
        if tfa_type == '':
            return Response(data={'message': 'invalid type'}, status=400)
        user_tfa = request.user.user_tfa
        if user_tfa.active:
            return Response(data={'message': 'tfa already active'}, status=400)
        if not user_tfa.user.verified and tfa_type == TFATypes.EMAIL:
            return Response(data={'message': 'user\'s email not verified'}, status=400)
        try:
            user_tfa = UserTFA.objects.activate(user_tfa, otp_type=tfa_type)
        except ValidationError as e:
            return Response(data={'message': str(e)}, status=400)
        if user_tfa.is_email():
            return Response(status=204)
        return Response({
            'uri': user_tfa.get_uri(),
            'token': user_tfa.otp_token
        }, status=200)

    def put(self, request) -> Response:
        """
        json: {'code': <code>}
        """
        user_tfa = request.user.user_tfa
        if not user_tfa.active:
            return Response(data={'message': '2fa not active'}, status=400)
        code = request.data.get('code', '')
        if code == '':
            return Response(data={'message': 'missing code'}, status=400)
        if not user_tfa.verify_otp_code(code):
            return Response(data={'message': 'invalid code'}, status=400)
        user_tfa = UserTFA.objects.deactivate(user_tfa)
        OtpCode.objects.delete_codes(user_tfa)
        return Response(status=200)


@api_view(['POST'])
@permission_classes([])
def validate_login(request) -> Response:
    """
    json: {'token': <token>, 'code': <code>}
    """
    url_token = request.data.get('token', '')
    code = request.data.get('code', '')
    if url_token == '' or code == '':
        return Response(data={'message': 'missing token or code'}, status=400)
    try:
        user_tfa = UserTFA.objects.get(url_token=url_token)
    except UserTFA.DoesNotExist:
        return Response(data={'message': 'user not found'}, status=404)
    if user_tfa.user.has_password_token():
        return Response(data={'message': 'user is trying to reset password'}, status=403)
    user_tfa = UserTFA.objects.delete_url_token(user_tfa)
    if not user_tfa.verify_otp_code(code):
        if not OtpCode.objects.validate_code(user_tfa, code):
            user_tfa = UserTFA.objects.generate_url_token(user_tfa)
            return Response(data={
                'message': 'invalid code',
                'token': user_tfa.url_token
            }, status=400)
        OtpCode.objects.delete_codes(user_tfa)
        user_tfa = UserTFA.objects.deactivate(user_tfa)
    refresh_token = TokenPairSerializer.get_token(user_tfa.user)
    response = Response(data={
        'access_token': str(refresh_token.access_token),
        'refresh_token': str(refresh_token),
        'exp': get_exp(refresh_token).seconds
    }, status=200)
    return response


@api_view(['POST'])
@permission_classes([])
def validate_recover(request) -> Response:
    """
    json: {'token': <token>, 'code': <code>}
    """
    url_token = request.data.get('token', '')
    code = request.data.get('code', '')
    if url_token == '' or code == '':
        return Response(data={'message': 'missing token or code'}, status=400)
    try:
        user_tfa = UserTFA.objects.get(url_token=url_token)
    except UserTFA.DoesNotExist:
        return Response(data={'message': 'user not found'}, status=404)
    user_tfa = UserTFA.objects.delete_url_token(user_tfa)
    user = user_tfa.user
    if not user.has_password_token():
        return Response(data={'message': 'user is not recovering password'}, status=403)
    if not user_tfa.verify_otp_code(code):
        if not OtpCode.objects.validate_code(user_tfa, code):
            user_tfa = UserTFA.objects.generate_url_token(user_tfa)
            return Response(data={
                'message': 'invalid code',
                'token': user_tfa.url_token}, status=400)
    token = user_tfa.user.password_token
    return Response(data={'token': token.token}, status=200)


@api_view(['POST'])
def validate_activate(request) -> Response:
    """
    header: 'Authorization: Bearer <access_token>'
    json: {'code': <code>}
    """
    code = request.data.get('code', '')
    if code == '':
        return Response(data={'message': 'missing code'}, status=400)
    user_tfa = request.user.user_tfa
    if not user_tfa.is_activating():
        return Response(data={
            'message': "2fa activation process not started yet",
        }, status=403)
    user_tfa = UserTFA.objects.delete_url_token(user_tfa)
    if not user_tfa.verify_otp_code(code):
        return Response(data={'message': 'invalid code'}, status=400)
    codes = OtpCode.objects.generate_codes(user_tfa=user_tfa)
    UserTFA.objects.update_active(user_tfa)
    return Response(data={'codes': codes}, status=200)


@api_view(['GET'])
@permission_classes([])
def get_email_code(request) -> Response:
    if request.user.is_authenticated:
        user_tfa = request.user.user_tfa
    else:
        try:
            user_tfa = UserTFA.objects.get(url_token=request.data['token'])
        except UserTFA.DoesNotExist:
            return Response(data={'message': 'user not found'}, status=404)
    if not user_tfa.active and not user_tfa.is_activating():
        return Response(data={'message': '2fa not active'}, status=403)
    if not user_tfa.is_email():
        return Response(data={'message': '2fa type is not email'}, status=400)
    return Response(data={
        'username': user_tfa.user.username,
        'email': user_tfa.user.email,
        'code': user_tfa.get_code(),
    }, status=200)

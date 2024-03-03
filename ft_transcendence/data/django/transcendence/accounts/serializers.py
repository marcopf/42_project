import logging

from django.core.validators import RegexValidator, EmailValidator
from rest_framework import serializers

from accounts.models import User, UserInfo
from accounts.validators import image_validator

logger = logging.getLogger(__name__)


class UploadImageSerializer(serializers.Serializer):
    image = serializers.FileField(max_length=50, validators=[image_validator])

    def save_image(self, user, validated_data):
        image = validated_data["image"]
        user_info = user.user_info
        user_info = UserInfo.objects.update_picture(user_info, picture=image)
        return user_info


class UserInfoSerializer(serializers.ModelSerializer):
    class Meta:
        model = UserInfo
        fields = ["first_name", "last_name", "birthdate", "picture", "date_joined"]
        read_only_fields = ["date_joined", "picture"]


class UserSerializer(serializers.ModelSerializer):

    class Meta:
        model = User
        fields = ["username", "email"]
        extra_kwargs = {
            "username": {"validators": [RegexValidator("^[A-Za-z0-9!?*$~_-]{5,32}$")]},
            "email": {"required": False, "validators": [EmailValidator()]},
        }


class RegisterUserSerializer(serializers.Serializer):
    username = serializers.CharField(validators=[RegexValidator("^[A-Za-z0-9!?*$~_-]{5,32}$")])
    email = serializers.EmailField(required=False, validators=[EmailValidator()])
    user_info = UserInfoSerializer(required=False)


class CompleteUserSerializer(serializers.ModelSerializer):
    user_info = UserInfoSerializer(required=False)
    banned = serializers.BooleanField(required=False)

    class Meta:
        model = User
        fields = ["username", "email", "role", "banned", "user_info"]
        extra_kwargs = {
            "username": {"validators": [RegexValidator("^[A-Za-z0-9!?*$~_-]{5,32}$")]},
            "email": {"required": False, "validators": [EmailValidator()]},
            "role": {"write_only": True, "required": False},
        }

    def create(self, validated_data):
        validated_data.pop("role", "")
        user_info = validated_data.pop("user_info", {})
        user = User.objects.create_user(**validated_data)
        user.user_info = UserInfo.objects.create(user, **user_info)
        return user

    def update_email(self, validated_data):
        validated_data.pop("user_info", {})
        user = User.objects.get(pk=validated_data.get("username"))
        updated_user = User.objects.update_user_email(user, **validated_data)
        return updated_user

    def update_user_info(self, validated_data):
        user_info_dic = validated_data.pop("user_info", {})
        username = validated_data.get("username")
        try:
            user_info = UserInfo.objects.get(pk=username)
            updated_user_info = UserInfo.objects.update_info(user_info, **user_info_dic)
        except UserInfo.DoesNotExist:
            user = User.objects.get(pk=username)
            updated_user_info = UserInfo.objects.create(user, **user_info_dic)
        return updated_user_info

    def update_role(self, validated_data):
        user_role = validated_data.pop("role", "")
        username = validated_data.pop("username")
        user = User.objects.get(pk=username)
        updated_user = User.objects.update_user_role(user, user_role)
        return updated_user

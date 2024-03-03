
from django.core.validators import RegexValidator, EmailValidator

from rest_framework import serializers

from .models import User


class UserSerializer(serializers.ModelSerializer):

    new_password = serializers.CharField(max_length=128, required=False, write_only=True)

    class Meta:
        model = User
        fields = ["username", "email", "password", "new_password", "active", "verified"]
        extra_kwargs = {
            "username": {"validators": [RegexValidator("^[A-Za-z0-9!?*$~_-]{5,32}$")]},
            "email": {"required": False, "validators": [EmailValidator()]},
            "password": {"write_only": True, "required": False},
            "active": {"required": False, "read_only": True},
            "verified": {"required": False, "read_only": True},
        }

    def create(self, validated_data):
        return User.objects.create_user(**validated_data)


class ListUserSerializer(serializers.ModelSerializer):
    class Meta:
        model = User
        fields = ["username", "active", "role"]
        extra_kwargs = {
            "username": {"validators": [RegexValidator("^[A-Za-z0-9!?*$~_-]{5,32}$")]},
        }

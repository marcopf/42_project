from rest_framework import filters

class MyFilterBackend(filters.BaseFilterBackend):
    def filter_queryset(self, request, queryset, view):
        search_fields = self.get_map(view)
        bool_fields = self.get_map_bool(view)
        fields = {}
        for ser_field, model_field in search_fields.items():
            value = request.query_params.get(ser_field, "")
            if value == "":
                continue
            fields[model_field] = value
        for ser_field, model_field in bool_fields.items():
            value = request.query_params.get(ser_field, "")
            if value == "":
                continue
            if value == "true":
                fields[model_field] = True
            else:
                fields[model_field] = False
        return queryset.filter(**fields)

    def get_map(self, view) -> dict:
        serializer_class = getattr(view, "serializer_class", None)
        if serializer_class is None:
            raise ValueError("serializer_class is not defined")
        search_fields = getattr(view, "search_fields", None)
        if search_fields is None:
            raise ValueError("search_fields is not defined")
        fields = serializer_class().fields
        fields_map = {}
        for field_name, field in fields.items():
            if field_name in search_fields:
                fields_map[field_name] = field.source
        return fields_map

    def get_map_bool(self, view) -> dict:
        serializer_class = getattr(view, "serializer_class", None)
        if serializer_class is None:
            raise ValueError("serializer_class is not defined")
        search_fields = getattr(view, "bool_fields", None)
        if search_fields is None:
            raise ValueError("search_fields is not defined")
        fields = serializer_class().fields
        fields_map = {}
        for field_name, field in fields.items():
            if field_name in search_fields:
                fields_map[field_name] = field.source
        return fields_map

NAME=inception

all: install
	docker-compose -f ./srcs/docker-compose.yml build --no-cache;
	docker-compose -f ./srcs/docker-compose.yml up -d

install:
	bash ./srcs/requirements/tools/setup.sh

clean:
	bash ./srcs/requirements/tools/clean.sh

fclean: clean
	bash ./srcs/requirements/tools/fclean.sh

re: fclean all


.PHONY: install run clean fclean re

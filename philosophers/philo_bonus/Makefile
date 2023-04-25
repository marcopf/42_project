NAME	= philo_bonus
HEADER	= ${NAME:.a=.h}
SRCS	=	${wildcard *.c}
OBJS	= ${SRCS:.c=.o}
OBJS_B	= ${SRCS_B:.c=.o}
FLAGS	= -Wall -Werror -Wextra
OPTIONS	= -c
CC		= gcc
RM		= rm -f

.o:.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

all: ${NAME} ${NAME_BONUS}

${NAME}: ${OBJS}
	$(CC) $(OBJS) -pthread -o $(NAME)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re libft

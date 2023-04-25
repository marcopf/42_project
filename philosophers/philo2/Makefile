NAME	= philo
NAME_BONUS	= philo_bonus
HEADER	= ${NAME:.a=.h}
SRCS	=	${wildcard philo_m2/*.c}
SRCS_B	=	${wildcard philo_b/*.c}
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

${NAME_BONUS}: ${OBJS_B}
	$(CC) $(OBJS_B) -pthread -o ${NAME_BONUS}

clean:
	${RM} ${OBJS}
	${RM} ${OBJS_B}

fclean: clean
	${RM} ${NAME}
	${RM} ${NAME_BONUS}

re: fclean all

.PHONY: all clean fclean re libft
NAME	= philo
HEADER	= ${NAME:.a=.h}
SRCS	=	philosophers.c mini_libft/ft_atoi.c mini_libft/ft_itoa.c philosopher_life.c thread_func.c check.c
OBJS	= ${SRCS:.c=.o}
BOBJS	= ${BSRCS:.c=.o}
FLAGS	= -Wall -Werror -Wextra
OPTIONS	= -c
CC		= gcc
RM		= rm -f

.o:.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	$(CC) $(OBJS) -pthread -o $(NAME)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re libft
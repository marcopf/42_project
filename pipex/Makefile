NAME	= pipex
HEADER	= ${NAME:.a=.h}
SRCS	=	pipex.c free.c path_n_command.c
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
	make -C ./ft_printf
	make -C ./libft
	$(CC) $(OBJS) -L./libft -lft -L./ft_printf -lftprintf -o $(NAME)

clean:
	make -C ./ft_printf clean
	make -C ./libft clean
	${RM} ${OBJS}

fclean: clean
	make -C ./ft_printf fclean
	make -C ./libft fclean
	${RM} ${NAME}

re: fclean all

libft:
	make -C ./libft
	cp ./libft/libft.a .


.PHONY: all clean fclean re libft

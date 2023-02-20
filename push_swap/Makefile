NAME	= push_swap
HEADER	= ${NAME:.a=.h}
SRCS	= all_possible_move/greedy.c all_possible_move/move_calculator.c stacks/fill_stack.c \
			moves/pa_pb.c moves/ra_rb.c moves/rra_rrb.c main.c mini_libft/ft_split.c mini_libft/ft_atoi.c \
			check/check_duplicate.c check/str_check.c moves/sa_sb.c all_possible_move/small_sort.c
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
	$(CC) $(OBJS) -o $(NAME)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all


.PHONY: all clean fclean re

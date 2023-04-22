NAME	= push_swap
HEADER	= ${NAME:.a=.h}
SRCS	= sorting/greedy.c sorting/move_calculator.c stacks/fill_stack.c \
			stacks/pa_pb.c stacks/ra_rb.c stacks/rra_rrb.c mini_libft/ft_split.c mini_libft/ft_atoi.c \
			input_control/check_duplicate.c input_control/str_check.c stacks/sa_sb.c sorting/small_sort.c \
			checker/gnl/get_next_line_utils.c checker/gnl/get_next_line.c
OBJS	= ${SRCS:.c=.o}
BOBJS	= ${BSRCS:.c=.o}
FLAGS	= -Wall -Werror -Wextra
OPTIONS	= -c
CC		= gcc
RM		= rm -f

.o:.c
	$(CC) -Wall -Wextra -Werror main.c -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	$(CC) $(OBJS) main.c -o $(NAME)

bonus: ${OBJS}
	$(CC) $(OBJS) main.c -o $(NAME)
	$(CC) $(OBJS) checker/checker.c -o checker_mac

clean:
	${RM} ${OBJS}
	${RM} checker/checker.o
	${RM} main.o

fclean: clean
	${RM} ${NAME}
	${RM} checker_mac

re: fclean all


.PHONY: all clean fclean re

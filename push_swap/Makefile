NAME	= push_swap
BNAME	= checker
HEADER	= ${NAME:.a=.h}
SRCS	= sorting/greedy.c sorting/move_calculator.c stacks/fill_stack.c \
			stacks/pa_pb.c stacks/ra_rb.c stacks/rra_rrb.c mini_libft/ft_split.c mini_libft/ft_atoi.c \
			input_control/check_duplicate.c input_control/str_check.c stacks/sa_sb.c sorting/small_sort.c \
			checker_bonus/gnl/get_next_line_utils.c checker_bonus/gnl/get_next_line.c main.c
BSRCS	= sorting/greedy.c sorting/move_calculator.c stacks/fill_stack.c \
			stacks/pa_pb.c stacks/ra_rb.c stacks/rra_rrb.c mini_libft/ft_split.c mini_libft/ft_atoi.c \
			input_control/check_duplicate.c input_control/str_check.c stacks/sa_sb.c sorting/small_sort.c \
			checker_bonus/gnl/get_next_line_utils.c checker_bonus/gnl/get_next_line.c checker_bonus/checker.c
OBJS	= ${SRCS:.c=.o}
BOBJS	= ${BSRCS:.c=.o}
FLAGS	= -Wall -Werror -Wextra
OPTIONS	= -c
CC		= gcc
RM		= rm -f

%.o:%.c
	$(CC) -Wall -Wextra -Werror -c $< -o $(<:.c=.o)

all: ${NAME}

${NAME}: ${OBJS}
	$(CC) $(OBJS) -o $(NAME)

${BNAME}: $(BOBJS)
	$(CC) $(BOBJS) -o ${BNAME}

bonus: ${BNAME}

clean:
	${RM} ${OBJS}
	${RM} ${BOBJS}

fclean: clean
	${RM} ${NAME}
	${RM} ${BNAME}

re: fclean all


.PHONY: all clean fclean re bonus

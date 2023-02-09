NAME	= so_long
HEADER	= ${NAME:.a=.h}
SRCS	= main.c map_parser.c map_check.c get_next_line.c get_next_line_utils.c draw_map.c player_func.c player_move.c game_func.c charizard_move.c print_moves.c \
			ft_printf.c ft_hex.c ft_writeptr.c printf_utils.c ft_itoa.c ft_strdup.c ft_calloc.c ft_bzero.c ft_putstr.c ft_strlen.c charizard_attack.c draw_exit.c charizard_line.c
OBJS	= ${SRCS:.c=.o}
BOBJS	= ${BSRCS:.c=.o}
FLAGS	= -Wall -Werror -Wextra
OPTIONS	= -c
CC		= gcc
RM		= rm -f

.o:.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all: ${NAME}
	@make -C ./mlx
	@cp ./mlx/libmlx.dylib .

${NAME}: ${OBJS}
	$(CC) $(OBJS) -L . -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@make -C ./mlx clean
	${RM} ${OBJS}

fclean: clean
	rm -rf libmlx.dylib
	${RM} ${NAME}

re: fclean all

game:
	leaks -atExit -- ./so_long maps/minifun.ber
	leaks -atExit -- ./so_long maps/new_minifun.ber
	leaks -atExit -- ./so_long maps/penultimo.ber
	leaks -atExit -- ./so_long maps/fun.ber

test:
	leaks -atExit -- ./so_long maps/missing_collectibles.ber
	leaks -atExit -- ./so_long maps/missing_exit.ber
	leaks -atExit -- ./so_long maps/missing_player.ber
	leaks -atExit -- ./so_long maps/invalid_rect.ber
	leaks -atExit -- ./so_long maps/invalid_rect_oversize.ber
	leaks -atExit -- ./so_long maps/open_wall.ber

.PHONY: all clean fclean re

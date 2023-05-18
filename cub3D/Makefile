# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/06 14:12:38 by marco             #+#    #+#              #
#    Updated: 2023/05/18 09:42:20 by mpaterno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D

SRC			= $(wildcard get_next_line/*.c) $(wildcard parser/*.c) $(wildcard mlx_func/*.c) $(wildcard *.c) $(wildcard moves/*.c) $(wildcard ray/*.c) $(wildcard init/*.c)

OBJ		= $(SRC:%.c=%.o)

CC		= gcc
FLAGS	= -Wall -Wextra -Werror
MLX		= -L ./mlx_mac -lmlx
RM		= rm -f

RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
RESET	= \033[0;0m

$(NAME): $(OBJ)
	@make -C libft
ifeq ($(shell uname), Linux)
	@make -C mlx_linux
	$(CC) $(FLAGS) $(OBJ) -L ./libft -lft -L ./mlx_linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)
else
	@make -C mlx_mac
	@cp mlx_mac/libmlx.dylib .
	@$(CC) $(FLAGS) $(OBJ) $(MLX) -L ./libft -lft -o $(NAME)
endif
	@printf "\r\033[KCUBE3D  CREATED  SUCCESSUFULLY\n$(RESET)"
	@printf "$(BLUE)-------------------------------------------------------------------------\n$(RESET)"
	@printf "  ██████╗██╗   ██╗██████╗ ██████╗ ██████╗ \n"
	@printf " ██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗\n"
	@printf " ██║     ██║   ██║██████╔╝ █████╔╝██║  ██║\n"
	@printf " ██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║\n"
	@printf " ╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝\n"
	@printf "  ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ \n"
	@printf "\n$(BLUE)-------------------------------------------------------------------------\n$(RESET)"
	@printf "$(YELLOW)Made with love and bestemmie by Afraccal e Mpaterno.\n$(RESET)"
	@printf "$(BLUE)-------------------------------------------------------------------------\n$(RESET)"

%.o : %.c
ifeq ($(shell uname),Linux)
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imxl_linux -O3 -c $< -o $@
else
	@$(CC) $(FLAGS) -Imlx_mac -c $< -o $@
endif
		

all: $(NAME)

linux: $(OBJ)
	$(CC) -fsanitize=address $(OBJ) $(RDLN_L) -o $(NAME)

clean:
ifeq ($(shell uname), Linux)
	@make -C mlx_linux clean
else
	@make -C mlx_mac clean
	@rm -rf libmlx.dylib
endif
	@make -C libft clean
	@printf "$(RED)\nRemoving Object files...\n$(RESET)"
	@printf "$(BLUE)-------------------------------------------------------------------------\n$(RESET)"
	@$(RM) $(OBJ)
	@printf "$(RED)Object files removed\n$(RESET)"
	
fclean: clean
	@make -C libft fclean
	@printf "$(RED)\nRemoving program executable...\n$(RESET)"
	@printf "$(BLUE)-------------------------------------------------------------------------\n$(RESET)"
	@$(RM) $(NAME)
	@printf "$(RED)CUDE3D REMOVED\n$(RESET)"

	
re: fclean all

test:
	./cub3D ./maps/test.cub

.PHONY: all clean fclean re

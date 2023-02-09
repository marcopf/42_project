/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:55:55 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/09 19:26:40 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_exit(t_game *game)
{
	locate_door(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs.floor,
		game->imgs.offset_x, game->imgs.offset_y);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs.open_door,
		(game->door_x) * 61, ((game->door_y) * 61) + 30);
	game->done = 1;
}

void	char_animation_file(t_game *game)
{
	game->charizard.c1 = mlx_xpm_file_to_image(game->mlx, "imgs/c1.xpm",
			&game->imgs.img_width, &game->imgs.img_height);
	game->charizard.c2 = mlx_xpm_file_to_image(game->mlx, "imgs/c2.xpm",
			&game->imgs.img_width, &game->imgs.img_height);
	game->charizard.c3 = mlx_xpm_file_to_image(game->mlx, "imgs/c3.xpm",
			&game->imgs.img_width, &game->imgs.img_height);
	game->charizard.c4 = mlx_xpm_file_to_image(game->mlx, "imgs/c4.xpm",
			&game->imgs.img_width, &game->imgs.img_height);
	game->charizard.c5 = mlx_xpm_file_to_image(game->mlx, "imgs/c5.xpm",
			&game->imgs.img_width, &game->imgs.img_height);
	game->charizard.c6 = mlx_xpm_file_to_image(game->mlx, "imgs/c6.xpm",
			&game->imgs.img_width, &game->imgs.img_height);
	game->charizard.a1 = mlx_xpm_file_to_image(game->mlx, "imgs/a1.xpm",
			&game->imgs.img_width, &game->imgs.img_height);
	game->charizard.a2 = mlx_xpm_file_to_image(game->mlx, "imgs/left.xpm",
			&game->imgs.img_width, &game->imgs.img_height);
	game->charizard.a3 = mlx_xpm_file_to_image(game->mlx, "imgs/up.xpm",
			&game->imgs.img_width, &game->imgs.img_height);
	game->charizard.a4 = mlx_xpm_file_to_image(game->mlx, "imgs/down.xpm",
			&game->imgs.img_width, &game->imgs.img_height);
}

void	poke_replace(t_game *game, int i, int j)
{
	game->map[i][j] = 'C';
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->imgs.floor, (j) * 61, ((i) * 61) + 30);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->imgs.item, (j) * 61, ((i) * 61) + 30);
}

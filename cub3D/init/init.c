/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:39:41 by afraccal          #+#    #+#             */
/*   Updated: 2023/05/15 20:57:38 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

void	textures(t_game *game)
{
	game->walls[0].img = mlx_xpm_file_to_image(game->mlx,
			game->tex.nord, &(game->wall_heights[0]), &(game->wall_widths[0]));
	game->walls[1].img = mlx_xpm_file_to_image(game->mlx,
			game->tex.sud, &(game->wall_heights[1]), &(game->wall_widths[1]));
	game->walls[2].img = mlx_xpm_file_to_image(game->mlx,
			game->tex.ovest, &(game->wall_heights[2]), &(game->wall_widths[2]));
	game->walls[3].img = mlx_xpm_file_to_image(game->mlx,
			game->tex.est, &(game->wall_heights[3]), &(game->wall_widths[3]));
	game->walls[0].addr = mlx_get_data_addr(game->walls[0].img,
			&game->walls[0].bits_per_pixel, &game->walls[0].line_length,
			&game->walls[0].endian);
	game->walls[1].addr = mlx_get_data_addr(game->walls[1].img,
			&game->walls[1].bits_per_pixel, &game->walls[1].line_length,
			&game->walls[1].endian);
	game->walls[2].addr = mlx_get_data_addr(game->walls[2].img,
			&game->walls[2].bits_per_pixel, &game->walls[2].line_length,
			&game->walls[2].endian);
	game->walls[3].addr = mlx_get_data_addr(game->walls[3].img,
			&game->walls[3].bits_per_pixel, &game->walls[3].line_length,
			&game->walls[3].endian);
}

/*
void	init_game(t_game *game)

init most of the game struct variable
*/
void	init_game(t_game *game)
{	
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window (game->mlx, WIDTH, HEIGHT, NAME);
	game->data.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	textures(game);
	game->minimap.map.img = mlx_new_image(game->mlx, game->map.width * 11,
			game->map.height * 11);
	game->data.addr = mlx_get_data_addr(game->data.img,
			&game->data.bits_per_pixel, &game->data.line_length,
			&game->data.endian);
	game->minimap.map.addr = mlx_get_data_addr(game->minimap.map.img,
			&game->minimap.map.bits_per_pixel, &game->minimap.map.line_length,
			&game->minimap.map.endian);
}

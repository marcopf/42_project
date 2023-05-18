/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:30:32 by marco             #+#    #+#             */
/*   Updated: 2023/05/18 09:06:06 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

/*
void	draw_background(t_game *game)

draw the ceilling and floor accordingly to the .cub specified value
*/
void	draw_background(t_game *game)
{
	t_vector	begin;
	t_vector	end;
	int			y;

	begin.x = 0;
	end.x = WIDTH;
	y = -1;
	while (++y < (HEIGHT / 2))
	{
		begin.y = y;
		end.y = y;
		draw_line_on(&game->data, begin, end, create_trgb(0,
				game->tex.ceilling[0], game->tex.ceilling[1],
				game->tex.ceilling[2]));
	}
	y -= 1;
	while (++y < HEIGHT)
	{
		begin.y = y;
		end.y = y;
		draw_line_on(&game->data, begin, end, create_trgb(0,
				game->tex.floor[0], game->tex.floor[1], game->tex.floor[2]));
	}
}

/*
void	draw_minimap(t_game *game)

function that given a char ** map covert it to a minimap
where each box is converted to a 10x10(pixel) block and
then using game->player.pos.x/y the playes is drawn
*/
void	draw_minimap(t_game *game)
{
	int			x;
	int			y;
	t_vector	start;

	y = -1;
	while (game->map.map[++y])
	{
		x = -1;
		while (game->map.map[y][++x])
		{
			start.x = x * 11;
			start.y = y * 11;
			if (game->map.map[y][x] == '1')
				draw_square(&game->minimap.map, start, 11, 0x00FFFFFF);
			else
				draw_square(&game->minimap.map, start, 11, 0x004A474E);
		}
	}
	start.x = (game->player.pos.x * 11) - 2.5;
	start.y = (game->player.pos.y * 11) - 2.5;
	draw_square(&game->minimap.map, start, 5, 0x00FF0000);
}

/*
int	draw_frame(t_game *game)

draw each frame of the game using different function to draw different
part of the view then a usleep is placed to limit the fps
*/
int	draw_frame(t_game *game)
{
	draw_minimap(game);
	draw_background(game);
	raycaster_flat(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->data.img, 0, 0);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->minimap.map.img, 0, 0);
	update_inputs(game);
	return (0);
}

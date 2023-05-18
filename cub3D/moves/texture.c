/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:30:21 by marco             #+#    #+#             */
/*   Updated: 2023/05/18 10:54:05 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

int	get_texture_x(t_game *game)
{
	double	wall_x;
	int		tex_x;

	if (game->ray.side == 0)
		wall_x = game->player.pos.y + game->ray.perp_wall_dist
			* game->ray.ray_dir.y;
	else
		wall_x = game->player.pos.x + game->ray.perp_wall_dist
			* game->ray.ray_dir.x;
	wall_x -= (int)(wall_x);
	tex_x = (int)(wall_x * (double)(TEXTURE_SIZE));
	if (game->ray.side == 0 && game->ray.ray_dir.x > 0)
		tex_x = TEXTURE_SIZE - tex_x - 1;
	if (game->ray.side == 1 && game->ray.ray_dir.y < 0)
		tex_x = TEXTURE_SIZE - tex_x - 1;
	return (tex_x);
}

/*
void	render_texture(t_game *game, int x)

draw the texture on the mlx_image minding the distance from the
player position to porperly scale the image
*/
void	render_texture(t_game *game, int x)
{
	t_vector		tex;
	double			step;
	double			tex_pos;
	int				y;
	unsigned int	color;

	step = 1.0 * TEXTURE_SIZE / game->ray.line_height;
	tex.x = get_texture_x(game);
	tex_pos = (game->ray.draw_start.y - HEIGHT / 2 + game->ray.line_height / 2)
		* step;
	y = game->ray.draw_start.y - 1;
	while (++y < game->ray.draw_end.y)
	{
		tex.y = (int)tex_pos & (TEXTURE_SIZE - 1);
		tex_pos += step;
		color = *(unsigned int *)(game->walls[game->ray.color].addr
				+ 4 * (TEXTURE_SIZE * (int)tex.y + (int)tex.x));
		my_mlx_pixel_put(&game->data, x, y, color);
	}
}

/*
void	select_texture(t_game *game)

prepare the value of game->ray.color depending on the player position
to be later used from render_texture or in texture-less version
*/
void	select_texture(t_game *game)
{
	if (game->ray.side == 1 && game->player.pos.y <= game->ray.map_y)
		game->ray.color = 1;
	else if (game->ray.side == 1)
		game->ray.color = 0;
	else if (game->ray.side == 0 && game->player.pos.x <= game->ray.map_x)
		game->ray.color = 2;
	else if (game->ray.side == 0)
		game->ray.color = 3;
	else
		game->ray.color = 0;
}

/*
void	draw_texture(t_game *game, int x)

choose to render the game with or without texture depending on
the WITH_TEXTURE value
*/
void	draw_texture(t_game *game, int x)
{
	int	colors[4];

	select_texture(game);
	if (WITH_TEXTURE)
		render_texture(game, x);
	else
	{
		colors[0] = RGB_BLUE;
		colors[1] = RGB_GREEN;
		colors[2] = RGB_RED;
		colors[3] = RGB_YELLOW;
		game->ray.color %= 4;
		draw_line_on(&game->data, game->ray.draw_start,
			game->ray.draw_end, colors[game->ray.color]);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_collide.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:23:38 by marco             #+#    #+#             */
/*   Updated: 2023/05/15 20:47:54 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

/*
int	is_colliding(t_game *game, double y, double x)

the actual func that check if the collision is happening
*/
int	is_colliding(t_game *game, double y, double x)
{
	if (game->map.map[(int)y][(int)x] == '0')
		return (0);
	if (game->map.map[(int)y][(int)x] == 'O')
		return (0);
	return (1);
}

/*
void	update_dir_x(t_game *game)

this func is constantly checking if the move that the player is about to do
will collide with a wall and if that is not the case it will update the position
special for x axes
*/
void	update_dir_x(t_game *game)
{
	if (game->player.mov_dir.x == -1)
	{
		if (!is_colliding(game, game->player.pos.y, game->player.pos.x
				+ game->player.dir.x * game->player.mov_speed.x))
			game->player.pos.x += game->player.dir.x * game->player.mov_speed.x;
		if (!is_colliding(game, game->player.pos.y + game->player.dir.y
				* game->player.mov_speed.x, game->player.pos.x))
			game->player.pos.y += game->player.dir.y * game->player.mov_speed.x;
	}
	else if (game->player.mov_dir.x == 1)
	{
		if (!is_colliding(game, game->player.pos.y, game->player.pos.x
				- game->player.dir.x * game->player.mov_speed.x))
			game->player.pos.x -= game->player.dir.x * game->player.mov_speed.x;
		if (!is_colliding(game, game->player.pos.y - game->player.dir.y
				* game->player.mov_speed.x, game->player.pos.x))
			game->player.pos.y -= game->player.dir.y * game->player.mov_speed.x;
	}
}

/*
void	update_dir_y(t_game *game)

this func is constantly checking if the move that the player is about to do
will collide with a wall and if that is not the case it will update the position
special for y axes
*/
void	update_dir_y(t_game *game)
{
	if (game->player.mov_dir.y == 1)
	{
		if (!is_colliding(game, game->player.pos.y, game->player.pos.x
				- game->player.dir.y * game->player.mov_speed.y))
			game->player.pos.x -= game->player.dir.y * game->player.mov_speed.y;
		if (!is_colliding(game, game->player.pos.y + game->player.dir.x
				* game->player.mov_speed.y, game->player.pos.x))
			game->player.pos.y += game->player.dir.x * game->player.mov_speed.y;
	}
	else if (game->player.mov_dir.y == -1)
	{
		if (!is_colliding(game, game->player.pos.y, game->player.pos.x
				+ game->player.dir.y * game->player.mov_speed.y))
			game->player.pos.x += game->player.dir.y * game->player.mov_speed.y;
		if (!is_colliding(game, game->player.pos.y - game->player.dir.x
				* game->player.mov_speed.y, game->player.pos.x))
			game->player.pos.y -= game->player.dir.x * game->player.mov_speed.y;
	}
}

/*
void	update_rot(t_game *game)

this func is constantly checking if the move that the player is about to do
will collide with a wall and if that is not the case it will update the position
special for rotation
*/
void	update_rot(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_speed;

	old_dir_x = game->player.dir.x;
	old_plane_x = game->player.plane.x;
	rot_speed = 0;
	if (game->player.rot_dir == 1)
		rot_speed = game->player.rot_speed;
	else if (game->player.rot_dir == -1)
		rot_speed = -game->player.rot_speed;
	if (rot_speed)
	{
		game->player.dir.x = game->player.dir.x * cos(rot_speed)
			- game->player.dir.y * sin(rot_speed);
		game->player.dir.y = old_dir_x * sin(rot_speed)
			+ game->player.dir.y * cos(rot_speed);
		game->player.plane.x = game->player.plane.x * cos(
				rot_speed) - game->player.plane.y
			* sin(rot_speed);
		game->player.plane.y = old_plane_x * sin(rot_speed)
			+ game->player.plane.y * cos(rot_speed);
	}
}

/*
void	update_inputs(t_game *game)

this func is constantly checking if the move that the player is about to do
will collide with a wall and if that is not the case it will update the position
or rotation if necessary
*/
void	update_inputs(t_game *game)
{
	game->player.mov_speed.x = 0.02 * SPEED;
	game->player.mov_speed.y = 0.02 * SPEED;
	game->player.rot_speed = 0.02 * ROT_SPEED;
	update_dir_x(game);
	update_dir_y(game);
	update_rot(game);
}

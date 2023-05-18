/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:18:59 by marco             #+#    #+#             */
/*   Updated: 2023/05/15 20:41:23 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

/*
int	input_on_press(int key, t_game *game)

just elaborates the input as soon as the key is pressed
if the esc key is pressed the game is closed
*/
int	input_on_press(int key, t_game *game)
{
	if (key == 0 || key == 'a')
		game->player.mov_dir.y = -1;
	else if (key == 1 || key == 's')
		game->player.mov_dir.x = 1;
	else if (key == 2 || key == 'd')
		game->player.mov_dir.y = 1;
	else if (key == 13 || key == 'w')
		game->player.mov_dir.x = -1;
	else if (key == 123 || key == 65361)
		game->player.rot_dir = -1;
	else if (key == 124 || key == 65363)
		game->player.rot_dir = 1;
	else if (key == 53 || key == 65307)
		free_game(game);
	return (0);
}

/*
int	input_on_release(int key, t_game *game)

just elaborated the input as soon the key is released 
*/
int	input_on_release(int key, t_game *game)
{
	if (key == 13 || key == 1 || key == 'w' || key == 's')
		game->player.mov_dir.x = 0;
	else if (key == 0 || key == 2 || key == 'a' || key == 'd')
		game->player.mov_dir.y = 0;
	else if (key == 123 || key == 124 || key == 65363 || key == 65361)
		game->player.rot_dir = 0;
	return (0);
}

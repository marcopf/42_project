/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:23:50 by mpaterno          #+#    #+#             */
/*   Updated: 2023/05/14 23:02:30 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

/*
int	check_side(t_game *game, int x, int y)

given a box in map this func check top-left top-right bottom-left bottom-right
corner looking for 0 if found 0 is returned
*/
int	check_side(t_game *game, int x, int y)
{
	if (x + 1 < game->map.width
		&& (game->map.map[y][x + 1] != '1' && game->map.map[y][x + 1] != ' '))
		return (0);
	if (x - 1 >= 0
		&& (game->map.map[y][x - 1] != '1' && game->map.map[y][x - 1] != ' '))
		return (0);
	if (y + 1 < game->map.height
		&& (game->map.map[y + 1][x] != '1' && game->map.map[y + 1][x] != ' '))
		return (0);
	if (y - 1 >= 0
		&& (game->map.map[y - 1][x] != '1' && game->map.map[y - 1][x] != ' '))
		return (0);
	return (1);
}

/*
int	check_diag(t_game *game, int x, int y)

given a box in map this func check one up one left one right one bottom
looking for 0 if found 0 is returned
*/
int	check_diag(t_game *game, int x, int y)
{
	if ((x + 1 < game->map.width && y + 1 < game->map.height)
		&& (game->map.map[y + 1][x + 1] != '1'
		&& game->map.map[y + 1][x + 1] != ' '))
		return (0);
	if ((x - 1 >= 0 && y - 1 >= 0)
		&& (game->map.map[y - 1][x - 1] != '1'
		&& game->map.map[y - 1][x - 1] != ' '))
		return (0);
	if ((y + 1 < game->map.height && x - 1 >= 0)
		&& (game->map.map[y + 1][x - 1] != '1'
		&& game->map.map[y + 1][x - 1] != ' '))
		return (0);
	if ((y - 1 >= 0 && x + 1 < game->map.width)
		&& (game->map.map[y - 1][x + 1] != '1'
		&& game->map.map[y - 1][x + 1] != ' '))
		return (0);
	return (1);
}

/*
int	space_check(t_game *game)

looping trough each box of the map if a space is found
this func call check_side and check_diag to check 
the relative sorrounding boxes and if there is at least one 0
return (-1)
*/
int	space_check(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map.map[++y])
	{
		x = -1;
		while (game->map.map[y][++x])
		{
			if (game->map.map[y][x] == ' ' && !check_side(game, x, y))
				return (-1);
			if (game->map.map[y][x] == ' ' && !check_diag(game, x, y))
				return (-1);
		}
	}
	return (1);
}

/*
int	border_check(t_game *game)

this func check the first and last row plus the first and last
column available to controll if there is a 1 or a 0
*/
int	border_check(t_game *game)
{
	int	y;

	y = -1;
	while (game->map.map[++y])
	{
		if (game->map.map[y][0] != '1' && game->map.map[y][0] != ' ')
			return (-1);
		if (game->map.map[y][game->map.width - 1] != '1'
			&& game->map.map[y][game->map.width - 1] != ' ')
			return (-1);
	}
	y = -1;
	while (game->map.map[0][++y])
	{
		if (game->map.map[0][y] != '1' && game->map.map[0][y] != ' ')
			return (-1);
		else if (game->map.map[game->map.height - 1][y] != '1'
			&& game->map.map[game->map.height - 1][y] != ' ')
			return (-1);
	}
	if (space_check(game) == -1)
		return (-1);
	return (0);
}

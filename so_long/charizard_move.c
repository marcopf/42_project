/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charizard_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:36:38 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/08 09:52:16 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_char_up(t_game *game)
{
	int	x;
	int	y;

	locate_charizard(game);
	x = game->charizard.x;
	y = game->charizard.y;
	if (game->map[y - 1][x] != '1')
	{
		if (game->map[y - 1][x] == 'C')
			return (0);
		else if (game->map[y - 1][x] == 'E' && game->done == 0)
			return (0);
		else if (game->map[y - 1][x] == 'E')
			return (0);
		else if (game->map[y - 1][x] == 'P')
			game_over(game);
		game->map[y][x] = '0';
		game->map[y - 1][x] = 'G';
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->charizard.patrol_b, (x) * 61, ((y - 1) * 61) + 30);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs.floor,
			(x) * 61, ((y) * 61) + 30);
		return (1);
	}
	return (0);
}

int	move_char_down(t_game *game)
{
	int	x;
	int	y;

	locate_charizard(game);
	x = game->charizard.x;
	y = game->charizard.y;
	if (game->map[y + 1][x] != '1')
	{
		if (game->map[y + 1][x] == 'C')
			return (0);
		else if (game->map[y + 1][x] == 'E' && game->done == 0)
			return (0);
		else if (game->map[y + 1][x] == 'E')
			return (0);
		else if (game->map[y + 1][x] == 'P')
			game_over(game);
		game->map[y][x] = '0';
		game->map[y + 1][x] = 'G';
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->charizard.patrol_a, (x) * 61, ((y + 1) * 61) + 30);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs.floor,
			(x) * 61, ((y) * 61) + 30);
		return (1);
	}
	return (0);
}

int	move_char_left(t_game *game)
{
	int	x;
	int	y;

	locate_charizard(game);
	x = game->charizard.x;
	y = game->charizard.y;
	if (game->map[y][x - 1] != '1')
	{
		if (game->map[y][x - 1] == 'C')
			return (0);
		else if (game->map[y][x - 1] == 'E' && game->done == 0)
			return (0);
		else if (game->map[y][x - 1] == 'E')
			return (0);
		else if (game->map[y][x - 1] == 'P')
			game_over(game);
		game->map[y][x] = '0';
		game->map[y][x - 1] = 'G';
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->charizard.patrol_b, (x - 1) * 61, ((y) * 61) + 30);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs.floor,
			(x) * 61, ((y) * 61) + 30);
		return (1);
	}
	return (0);
}

int	move_char_right(t_game *game)
{
	int	x;
	int	y;

	locate_charizard(game);
	x = game->charizard.x;
	y = game->charizard.y;
	if (game->map[y][x + 1] != '1')
	{
		if (game->map[y][x + 1] == 'C')
			return (0);
		else if (game->map[y][x + 1] == 'E' && game->done == 0)
			return (0);
		else if (game->map[y][x + 1] == 'E')
			return (0);
		else if (game->map[y][x + 1] == 'P')
			game_over(game);
		game->map[y][x] = '0';
		game->map[y][x + 1] = 'G';
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->charizard.patrol_a, (x + 1) * 61, ((y) * 61) + 30);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs.floor,
			(x) * 61, ((y) * 61) + 30);
		return (1);
	}
	return (0);
}

int	move_charizard(t_game *game)
{
	int	random;

	if (!locate_charizard(game))
		return (0);
	if (game->frame != 15)
		return (0);
	random = rand() % 4;
	smart_move(game);
	smart_move(game);
	if (random == 0)
		move_char_right(game);
	else if (random == 1)
		move_char_up(game);
	if (random == 2)
		move_char_left(game);
	else if (random == 3)
		move_char_down(game);
	return (0);
}

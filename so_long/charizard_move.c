/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charizard_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:36:38 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/09 21:47:05 by mpaterno         ###   ########.fr       */
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
		else if (game->map[y - 1][x] == 'E' || game->map[y - 1][x] == 'U')
			return (0);
		else if (game->map[y - 1][x] == 'P')
			game_over(game);
		game->map[y][x] = '0';
		game->map[y - 1][x] = 'G';
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->charizard.c1, (x) * 61, ((y - 1) * 61) + 30);
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
		else if (game->map[y + 1][x] == 'E' || game->map[y + 1][x] == 'U')
			return (0);
		else if (game->map[y + 1][x] == 'P')
			game_over(game);
		game->map[y][x] = '0';
		game->map[y + 1][x] = 'G';
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->charizard.c1, (x) * 61, ((y + 1) * 61) + 30);
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
		else if (game->map[y][x - 1] == 'E' || game->map[y][x - 1] == 'U')
			return (0);
		else if (game->map[y][x - 1] == 'P')
			game_over(game);
		game->map[y][x] = '0';
		game->map[y][x - 1] = 'G';
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->charizard.c1, (x - 1) * 61, ((y) * 61) + 30);
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
		else if (game->map[y][x + 1] == 'E' || game->map[y][x + 1] == 'U')
			return (0);
		else if (game->map[y][x + 1] == 'P')
			game_over(game);
		game->map[y][x] = '0';
		game->map[y][x + 1] = 'G';
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->charizard.c1, (x + 1) * 61, ((y) * 61) + 30);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs.floor,
			(x) * 61, ((y) * 61) + 30);
		return (1);
	}
	return (0);
}

int	move_charizard(t_game *game)
{
	if (!locate_charizard(game))
		return (0);
	smart_move(game);
	return (0);
}

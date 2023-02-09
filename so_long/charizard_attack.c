/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charizard_attack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:00:37 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/09 22:25:49 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	attack_up(t_game *game)
{
	int	x;
	int	y;

	locate_charizard(game);
	x = game->charizard.x;
	y = game->charizard.y;
	if (game->map[y - 1][x] != '1')
	{
		if (game->map[y - 1][x] == 'C' || game->map[y - 1][x] == 'E'
			|| game->map[y][x] == 'U')
			return (0);
		else if (game->map[y - 1][x] == 'P')
			game_over(game);
		game->map[y - 1][x] = 'A';
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs.floor,
			(x) * 61, ((y) * 61) + 30);
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->charizard.a3, (x) * 61, ((y - 1) * 61) + 30);
		return (1);
	}
	return (0);
}

int	attack_down(t_game *game)
{
	int	x;
	int	y;

	locate_charizard(game);
	x = game->charizard.x;
	y = game->charizard.y;
	if (game->map[y + 1][x] != '1')
	{
		if (game->map[y + 1][x] == 'C' || game->map[y + 1][x] == 'E'
			|| game->map[y][x] == 'U')
			return (0);
		else if (game->map[y + 1][x] == 'P')
			game_over(game);
		game->map[y + 1][x] = 'A';
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->charizard.a4, (x) * 61, ((y + 1) * 61) + 30);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs.floor,
			(x) * 61, ((y) * 61) + 30);
		return (1);
	}
	return (0);
}

int	attack_left(t_game *game)
{
	int	x;
	int	y;

	locate_charizard(game);
	x = game->charizard.x;
	y = game->charizard.y;
	if (game->map[y][--x] != '1')
	{
		if (game->map[y][x] == 'C' || game->map[y][x] == 'E'
			|| game->map[y][x] == 'U')
			return (0);
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->charizard.a2, (x) * 61, ((y) * 61) + 30);
		if (game->map[y][x] == 'P')
			game_over(game);
		game->map[y][x] = 'A';
	}
	return (0);
}

int	attack_right(t_game *game)
{
	int	x;
	int	y;

	locate_charizard(game);
	x = game->charizard.x;
	y = game->charizard.y;
	if (game->map[y][++x] != '1')
	{
		if (game->map[y][x] == 'C' || game->map[y][x] == 'E' ||
			game->map[y][x] == 'U')
			return (0);
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->charizard.a1, (x) * 61, ((y) * 61) + 30);
		if (game->map[y][x] == 'P')
			game_over(game);
		game->map[y][x] = 'A';
	}
	return (0);
}

void	make_attack(t_game *game)
{
	int	(*functions[8])(t_game *);
	int	n1;

	n1 = rand() % 8;
	functions[0] = &attack_right;
	functions[1] = &attack_left;
	functions[2] = &attack_up;
	functions[3] = &attack_down;
	functions[4] = &l_attack_left;
	functions[5] = &l_attack_right;
	functions[6] = &l_attack_up;
	functions[7] = &l_attack_down;
	attack_clean(game);
	usleep(500);
	functions[n1](game);
}

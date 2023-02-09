/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charizard_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:59:41 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/09 19:26:26 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	l_attack_left(t_game *game)
{
	int	x;
	int	y;

	locate_charizard(game);
	x = game->charizard.x;
	y = game->charizard.y;
	while (game->map[y][--x] != '1')
	{
		if (game->map[y][x] == 'P')
			game_over(game);
		if (game->map[y][x] == 'E')
			break ;
		if (game->map[y][x] == 'C')
			game->map[y][x] = 'U';
		else
			game->map[y][x] = 'A';
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->charizard.a2, (x) * 61, ((y) * 61) + 30);
	}
	return (0);
}

int	l_attack_right(t_game *game)
{
	int	x;
	int	y;

	locate_charizard(game);
	x = game->charizard.x;
	y = game->charizard.y;
	while (game->map[y][++x] != '1')
	{
		if (game->map[y][x] == 'P')
			game_over(game);
		if (game->map[y][x] == 'E')
			break ;
		if (game->map[y][x] == 'C')
			game->map[y][x] = 'U';
		else
			game->map[y][x] = 'A';
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->charizard.a1, (x) * 61, ((y) * 61) + 30);
	}
	return (0);
}

int	l_attack_up(t_game *game)
{
	int	x;
	int	y;

	locate_charizard(game);
	x = game->charizard.x;
	y = game->charizard.y;
	while (game->map[--y][x] != '1')
	{
		if (game->map[y][x] == 'P')
			game_over(game);
		if (game->map[y][x] == 'E')
			break ;
		if (game->map[y][x] == 'C')
			game->map[y][x] = 'U';
		else
			game->map[y][x] = 'A';
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->charizard.a3, (x) * 61, ((y) * 61) + 30);
	}
	return (0);
}

int	l_attack_down(t_game *game)
{
	int	x;
	int	y;

	locate_charizard(game);
	x = game->charizard.x;
	y = game->charizard.y;
	while (game->map[++y][x] != '1')
	{
		if (game->map[y][x] == 'P')
			game_over(game);
		if (game->map[y][x] == 'E')
			break ;
		if (game->map[y][x] == 'C')
			game->map[y][x] = 'U';
		else
			game->map[y][x] = 'A';
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->charizard.a4, (x) * 61, ((y) * 61) + 30);
	}
	return (0);
}

void	attack_clean(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\n')
		{
			if (game->map[i][j] == 'A')
			{
				game->map[i][j] = '0';
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->imgs.floor, (j) * 61, ((i) * 61) + 30);
			}
			if (game->map[i][j] == 'U')
				poke_replace(game, i, j);
			j++;
		}
		i++;
	}
}

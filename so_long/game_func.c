/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:40:31 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/07 15:25:43 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_game(t_game *game)
{
	game->player.moves++;
	free_map(game->map);
	mlx_destroy_window(game->mlx, game->mlx_win);
	ft_printf("Hai Vinto !!! con %d mosse\n", game->player.moves);
	exit(0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	game_over(t_game *game)
{
	free_map(game->map);
	mlx_destroy_window(game->mlx, game->mlx_win);
	ft_printf("Hai perso !!! hai fatto %d mosse\n", game->player.moves);
	exit(0);
}

int	locate_charizard(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\n')
		{
			if (game->map[i][j] == 'G')
			{
				game->charizard.y = i;
				game->charizard.x = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	locate_door(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\n')
		{
			if (game->map[i][j] == 'E')
			{
				game->door_y = i;
				game->door_x = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

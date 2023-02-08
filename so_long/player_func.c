/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:38:07 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/05 20:35:47 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	locate_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\n')
		{
			if (game->map[i][j] == 'P')
			{
				game->player.y = i;
				game->player.x = j;
			}
			j++;
		}
		i++;
	}
}

void	collectibles_setter(t_game *game)
{
	int	i;
	int	j;
	int	counter;

	counter = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\n')
		{
			if (game->map[i][j] == 'C')
			{
				counter++;
			}
			j++;
		}
		i++;
	}
	game->player.collectibles = counter;
}

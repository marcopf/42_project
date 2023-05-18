/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:46:51 by marco             #+#    #+#             */
/*   Updated: 2023/05/12 11:36:14 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

void	set_player_view(t_game *game)
{
	char	dir;

	dir = game->map.map[(int)game->map.player_pos.y][
		(int)game->map.player_pos.x];
	if (dir == PLAYER_CHARACTERS[0])
	{
		game->player.dir.y = -1.0;
		game->player.plane.x = 0.66;
	}
	else if (dir == PLAYER_CHARACTERS[1])
	{
		game->player.dir.y = 1.0;
		game->player.plane.x = -0.66;
	}
	else if (dir == PLAYER_CHARACTERS[2])
	{
		game->player.dir.x = -1.0;
		game->player.plane.y = -0.66;
	}
	else if (dir == PLAYER_CHARACTERS[3])
	{
		game->player.dir.x = 1.0;
		game->player.plane.y = 0.66;
	}
}

int	fix_player_pos(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map.map[++y])
	{
		x = -1;
		while (game->map.map[y][++x])
		{
			if (ft_strchr("NWES", game->map.map[y][x]))
			{
				return (1);
			}
		}
	}
	return (0);
}

int	find_player_pos(t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (ft_strchr("NSWE", map->map[y][x]))
			{
				map->player_pos.x = x;
				map->player_pos.y = y;
				return (1);
			}
		}
	}
	return (0);
}

int	start_player(t_game *game)
{
	find_player_pos(&game->map);
	game->player.pos.x = (int)game->map.player_pos.x;
	game->player.pos.y = (int)game->map.player_pos.y;
	game->player.dir.x = 0.0;
	game->player.dir.y = 0.0;
	game->player.plane.x = 0.0;
	game->player.plane.y = 0.0;
	game->player.mov_dir.x = 0;
	game->player.mov_dir.y = 0;
	game->player.rot_dir = 0;
	set_player_view(game);
	game->map.map[(int)game->map.player_pos.y][
		(int)game->map.player_pos.x] = '0';
	if (fix_player_pos(game))
		return (printf("Error\nToo Many Players\n"));
	return (0);
}

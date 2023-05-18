/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:35:17 by afraccal          #+#    #+#             */
/*   Updated: 2023/05/12 21:31:58 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

int	free_matrix(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free (map[i]);
	free (map);
	return (1);
}

int	free_texture(t_game *game)
{
	if (game->tex.nord)
		free(game->tex.nord);
	if (game->tex.sud)
		free(game->tex.sud);
	if (game->tex.est)
		free(game->tex.est);
	if (game->tex.ovest)
		free(game->tex.ovest);
	return (1);
}

int	free_map(t_map map)
{
	if (!map.map)
		return (1);
	free_matrix (map.map);
	return (1);
}

int	free_game(t_game *game)
{
	free_texture(game);
	free_map(game->map);
	exit(0);
}

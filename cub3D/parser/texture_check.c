/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:20:19 by marco             #+#    #+#             */
/*   Updated: 2023/05/18 10:53:44 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

/*
int	ft_access(char *path)

a simple replace for acces unc that check if the file specified in path
is valid and it exist
*/
int	ft_access(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

/*
int	check_path(t_game *game)

this func check that all "NO || SO || WE || EA" path's
are properly setted and is a valid and existing file
*/
int	check_path(t_game *game)
{
	if (!game->tex.nord || !ft_access(game->tex.nord))
		return (0);
	if (!game->tex.sud || !ft_access(game->tex.sud))
		return (0);
	if (!game->tex.est || !ft_access(game->tex.est))
		return (0);
	if (!game->tex.ovest || !ft_access(game->tex.ovest))
		return (0);
	return (1);
}

/*
int	find_texture(t_game *game, int fd)

this func open a file and goes trough it's lines until it find
the 2 specifiers characters "NO || SO || WE || EA" if so set
the relative struct variable with the path of the disired file
*/
int	find_texture(t_game *game, int fd)
{
	char	*str;
	int		counter;

	counter = 0;
	str = get_next_line(fd);
	if (!str)
		return (0);
	while (counter < 4 && str)
	{
		if (ft_strncmp(str, "NO", 2) == 0 && ++counter)
			game->tex.nord = ft_strtrim(str + 2, "\n ");
		else if (ft_strncmp(str, "SO", 2) == 0 && ++counter)
			game->tex.sud = ft_strtrim(str + 2, "\n ");
		else if (ft_strncmp(str, "WE", 2) == 0 && ++counter)
			game->tex.ovest = ft_strtrim(str + 2, "\n ");
		else if (ft_strncmp(str, "EA", 2) == 0 && ++counter)
			game->tex.est = ft_strtrim(str + 2, "\n ");
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	if (counter < 4 || !check_path(game))
		return (-1);
	return (0);
}

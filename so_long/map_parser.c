/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:13:40 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/08 14:12:49 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
}

int	get_y(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

int	counter(char *path)
{
	char	*str;
	int		fd;
	int		i;

	fd = open(path, O_RDONLY);
	i = 0;
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	free(str);
	close(fd);
	return (i);
}

char	**map_maker(char *path)
{
	char	**strs;
	int		line;
	int		i;
	int		fd;

	i = -1;
	line = counter(path);
	fd = open(path, O_RDONLY);
	if (fd <= 0)
		exit(0);
	strs = (char **) malloc((line + 1) * sizeof(char *));
	while (++i < line)
		strs[i] = get_next_line(fd);
	strs[line] = 0;
	if (!is_valid_map(strs))
	{
		free_map(strs);
		exit(0);
	}
	close(fd);
	return (strs);
}

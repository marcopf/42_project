/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:51:03 by mpaterno          #+#    #+#             */
/*   Updated: 2023/05/18 09:58:48 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

int	free_colors(char **colors)
{
	int	i;

	i = -1;
	while (colors[++i])
		free(colors[i]);
	free(colors);
	return (-1);
}

int	col_cycle(int *col, char **colors)
{
	int	val;
	int	i;

	i = -1;
	while (++i < 3)
	{
		val = ft_atoi(colors[i]);
		if (val > 255 || (val == 0 && colors[i][0] != '0'))
			return (-1);
		col[i] = val;
	}
	return (0);
}

int	assign_color(t_game *game, char c, char *color)
{
	int		i;
	char	*str;
	char	**colors;

	str = ft_strtrim(color, " ");
	colors = ft_split(str, ',');
	free(str);
	i = -1;
	if (c == 'C')
	{
		if (col_cycle(game->tex.ceilling, colors) == -1)
			return (free_colors(colors));
	}
	else if (c == 'F')
	{
		if (col_cycle(game->tex.floor, colors) == -1)
			return (free_colors(colors));
	}
	i = -1;
	while (colors[++i])
		free(colors[i]);
	free(colors);
	return (0);
}

int	find_colors(t_game *game, int fd)
{
	char	*str;
	int		counter;

	counter = 0;
	str = get_next_line(fd);
	while (counter < 2 && str)
	{
		if (ft_strncmp(str, "F", 1) == 0 && ++counter)
		{
			if (assign_color(game, 'F', str + 1))
				return (free(str), -1);
		}
		else if (ft_strncmp(str, "C", 1) == 0 && ++counter)
		{
			if (assign_color(game, 'C', str + 1))
				return (free(str), -1);
		}
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	if (counter < 2)
		return (-1);
	return (0);
}

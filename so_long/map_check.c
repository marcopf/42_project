/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:13:30 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/08 10:14:39 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_in_set(char c)
{
	char	*set;
	int		i;

	set = "01CEPG";
	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	is_rect(char **map)
{
	size_t	i;
	size_t	x;
	size_t	y;

	y = get_y(map);
	x = ft_strlen(map[0]);
	i = 0;
	if (x - 1 == y)
	{
		ft_printf("Error\nMappa quadrata !!!\n");
		return (0);
	}
	while (i < y)
	{
		if (!(ft_strlen(map[i]) == x))
			break ;
		i++;
	}
	if (i == y)
		return (1);
	ft_printf("Error\nMappa quadrata o non rettangolare !!!\n");
	return (0);
}

int	border_wall(char **map)
{
	int	i;
	int	k;

	i = 0;
	k = ft_strlen(map[0]);
	while (map[0][i] != '\n')
	{
		if (map[0][i++] != '1')
			return (0);
	}
	i = 0;
	while ((map[get_y(map) - 1][i] != '\n'))
	{
		if (map[get_y(map) - 1][i++] != '1')
			return (0);
	}
	i = 0;
	while (map[i])
	{
		if ((map[i][0] != '1') || (map[i][k - 2] != '1'))
			return (0);
		i++;
	}
	return (1);
}

int	can_we_get_out(char **map)
{
	int	i;
	int	j;
	int	counter[3];

	i = -1;
	counter[0] = 0;
	counter[1] = 0;
	counter[2] = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j] != '\n')
		{
			if (map[i][j] == 'E')
				counter[0] = 1;
			if (map[i][j] == 'C')
				counter[1] = 1;
			if (map[i][j] == 'P')
				counter[2] = 1;
		}
	}
	if (counter[0] && counter[1] && counter[2])
		return (1);
	ft_printf("Error\ninserisci almeno 1 player / uscita / collectibles !!!\n");
	return (0);
}

int	is_valid_map(char **map)
{
	int	j;
	int	i;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j] != '\n')
		{
			if (!is_in_set(map[i][j]))
			{
				ft_printf("Error\nInvalid char in map !!!\n");
				return (0);
			}
		}
	}
	if (!is_rect(map) || !can_we_get_out(map))
		return (0);
	if (!border_wall(map))
	{
		ft_printf("Error\nIl muro è aperto !!!\n");
		return (0);
	}
	else
		return (1);
}

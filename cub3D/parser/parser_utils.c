/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:26:29 by marco             #+#    #+#             */
/*   Updated: 2023/05/14 22:51:14 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

/*
int	get_map_line(char *path)

auxiliar func for go_to_map return the line number where
the map part begin
*/
int	get_map_line(char *path)
{
	char	*str;
	int		i;
	int		fd;

	fd = open(path, O_RDONLY);
	i = 0;
	str = get_next_line(fd);
	while (str)
	{
		i++;
		if (str[0] == ' ' || ft_isdigit(str[0]))
		{
			free(str);
			close(fd);
			return (i);
		}
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (i);
}

/*
int	go_to_map(char *path)

simple func that open the path specified file and move it's index
to the begining of the map
*/
int	go_to_map(char *path)
{
	int		line;
	int		i;
	int		fd;
	char	*str;

	fd = open(path, O_RDONLY);
	i = -1;
	line = get_map_line(path);
	while (++i < line - 1)
	{
		str = get_next_line(fd);
		free(str);
	}
	return (fd);
}

/*
int	arg_check(int argc, char **argv)

this func check the arguments passed to the program and
ensure that is no more than one and also that the extension is correct
*/
int	arg_check(int argc, char **argv)
{
	int	i;

	if (argc < 2 || argc > 2)
		return (printf ("Error: argument\n") * 0);
	i = open(argv[1], O_RDONLY);
	if (i == -1)
		return (printf("Error: invalid file\n") * 0);
	i = ft_strlen (argv[1]) - 4;
	if (i < 0)
		return (printf ("Error: invalid extension\n") * 0);
	if (ft_strncmp(argv[1] + i, ".cub", 4))
		return (printf ("Error: invalid extension\n") * 0);
	return (1);
}

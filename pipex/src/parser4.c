/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 10:26:07 by marco             #+#    #+#             */
/*   Updated: 2023/04/22 22:11:56 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pipex.h"

/*
char	**line_filter(char **strs)
char **strs:	double pointer that rapresent the preparsed line coming from shell
				prompt that is already splitted on metacharacter.

this function return a new allocated null terminated array that is a copy of strs
but without '|' or ' ' as single string
*/
char	**line_filter(char **strs)
{
	char	**ret;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (strs[++i])
		if (ft_strncmp(strs[i], "|", 1) || (ft_strncmp(strs[i], " ", 1)))
			j++;
	ret = (char **)malloc(sizeof(char *) * (j + 1));
	if (!ret)
		return (0);
	i = -1;
	j = -1;
	while (strs[++i])
	{
		if (!ft_strncmp(strs[i], "|", 1) || (!ft_strncmp(strs[i], " ", 1)))
			continue ;
		ret[++j] = ft_strdup(strs[i]);
		if (!ret[j])
			return (0);
	}
	ret[++j] = 0;
	return (ret);
}

/*
int	prepare_strs(char **strs)
char	**strs: already properly setted variable that contain the complete
				command retrived from the shell formatted as follow
				{"path/command", "other option or flag", ...}

this function loop trought all the string contained in strs and trim
the starting and trailing blank space
*/
int	prepare_strs(char **strs)
{
	int		i;
	char	*temp;

	i = -1;
	while (strs[++i])
	{
		temp = ft_strtrim(strs[i], " ");
		if (!temp)
			exit(1);
		ft_free((void **) &strs[i]);
		strs[i] = ft_strdup(temp);
		if (!strs[i])
			exit(1);
		ft_free((void **) &temp);
	}
	return (i);
}

char	**final_parser(char *str)
{
	char	**strs;
	char	**temp;

	strs = ft_parser(str, " ");
	temp = line_filter(strs);
	ft_free_mat((void ***) &strs);
	return (temp);
}

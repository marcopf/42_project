/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:34:06 by mpaterno          #+#    #+#             */
/*   Updated: 2023/05/14 20:49:17 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*new_str;

	if (!s1 || !s2)
		return (0);
	new_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_str)
		return (0);
	i = -1;
	j = 0;
	while (s1[++i])
		new_str[j++] = s1[i];
	i = -1;
	while (s2[++i])
		new_str[j++] = s2[i];
	new_str[j] = 0;
	free((void *)s1);
	return (new_str);
}

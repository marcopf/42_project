/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:34:06 by mpaterno          #+#    #+#             */
/*   Updated: 2023/01/26 17:03:43 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == (unsigned char) c)
			return ((char *) s + i);
	}
	if (s[i] == (unsigned char)c)
		return ((char *) s + i);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
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

char	*ft_strdup(const char *str)
{
	char	*to_return;
	int		i;

	i = -1;
	to_return = (char *) malloc((sizeof(char) * ft_strlen(str)) + 1);
	if (!to_return)
		return (0);
	while (str[++i])
	{
		to_return[i] = str[i];
	}
	to_return[i] = 0;
	return (to_return);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!src || !dst || size == 0)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}

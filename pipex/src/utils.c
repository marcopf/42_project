/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 09:28:14 by marco             #+#    #+#             */
/*   Updated: 2023/04/22 22:11:53 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pipex.h"

int	ft_strlen_until(char *str, char *set)
{
	int	i;

	i = 0;
	while (str[i] && !ft_in(str[i], set))
		i++;
	return (i);
}

void	*ft_realloc(void *p, size_t size, int dim, int new_dim)
{
	char		*new_p;
	size_t		i;

	new_p = (char *)malloc(size * new_dim);
	if (!new_p)
		return (NULL);
	i = 0;
	while (i < size * new_dim)
	{
		if (i < size * dim)
			new_p[i] = ((char *) p)[i];
		else
			new_p[i] = 0;
		i++;
	}
	free(p);
	return ((void *) new_p);
}

char	*gnl_join(const char *s1, const char *s2)
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

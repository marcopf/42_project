/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:11:25 by mpaterno          #+#    #+#             */
/*   Updated: 2023/01/24 12:11:39 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:35:29 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/08 11:11:54 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putstr(const char *str)
{
	int	i;

	if (!str)
		return (write(1, "(null)", 6));
	else
	{
		i = 0;
		while (str[i])
			write(1, &str[i++], 1);
	}
	return (ft_strlen(str));
}

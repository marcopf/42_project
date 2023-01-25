/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:25:17 by mpaterno          #+#    #+#             */
/*   Updated: 2023/01/25 11:36:25 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_calloc(size_t n, size_t dim)
{
	void	*val;

	val = (void *) malloc(n * dim);
	if (!val)
		return (0);
	ft_bzero(val, n * dim);
	return (val);
}

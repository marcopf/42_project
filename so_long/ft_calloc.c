/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:25:17 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/08 11:12:13 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t n, size_t dim)
{
	void	*val;

	val = (void *) malloc(n * dim);
	if (!val)
		return (0);
	ft_bzero(val, n * dim);
	return (val);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writeptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:49:40 by mpaterno          #+#    #+#             */
/*   Updated: 2023/04/26 15:32:40 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ptr_hex(unsigned long long n)
{
	char					*set;
	unsigned long long		temp;

	set = "0123456789abcdef";
	if (n < 16)
	{
		temp = n % 16;
		write(1, &set[temp], 1);
	}
	else
	{
		temp = n % 16;
		n /= 16;
		ptr_hex(n);
		write(1, &set[temp], 1);
	}
}

int	write_ptr(unsigned long long n)
{
	write(1, "0x", 2);
	ptr_hex(n);
	return (ft_hex_len(n) + 2);
}

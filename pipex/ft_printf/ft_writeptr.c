/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:49:40 by mpaterno          #+#    #+#             */
/*   Updated: 2023/01/25 10:46:05 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ptr_hex(unsigned long long n)
{
	char					*set;
	unsigned long long		temp;

	set = "0123456789abcdef";
	if (n < 16 && n >= 0)
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

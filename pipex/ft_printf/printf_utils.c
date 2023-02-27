/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:23:14 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/24 09:23:51 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(int n)
{
	int		len;
	char	*str;

	str = ft_itoa_printf(n);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

void	write_u_putnbr(unsigned int n)
{
	unsigned int		temp;
	char				c;

	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	if (n <= 9)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		temp = (n % 10) + '0';
		n = n / 10;
		write_u_putnbr(n);
		write(1, &temp, 1);
	}
}

int	ft_u_putnbr(unsigned int n)
{
	write_u_putnbr(n);
	return (ft_num_len(n));
}

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

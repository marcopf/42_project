/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:40:14 by mpaterno          #+#    #+#             */
/*   Updated: 2023/01/24 13:29:12 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	router(va_list *args, char c)
{
	int	counter;

	counter = 0;
	if (c == 'd')
		counter = ft_putnbr(va_arg(*args, int));
	else if (c == 's')
		counter = ft_putstr(va_arg(*args, const char *));
	else if (c == 'c')
		counter = ft_putchar(va_arg(*args, int));
	else if (c == '%')
		counter = ft_putchar('%');
	else if (c == 'i')
		counter = ft_putnbr(va_arg(*args, int));
	else if (c == 'u')
		counter = ft_u_putnbr(va_arg(*args, unsigned int));
	else if (c == 'x')
		counter = hex(va_arg(*args, int), 0);
	else if (c == 'X')
		counter = hex(va_arg(*args, int), 1);
	else if (c == 'p')
		counter = write_ptr(va_arg(*args, unsigned long long));
	else
		counter = ft_putchar(c);
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		data_written;

	i = 0;
	data_written = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			data_written += router(&args, (char)str[i]);
		}
		else
			data_written += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (data_written);
}

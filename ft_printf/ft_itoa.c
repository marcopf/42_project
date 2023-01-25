/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:25:57 by mpaterno          #+#    #+#             */
/*   Updated: 2023/01/25 11:31:40 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	num_len(int n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*init(long *n, long *j, long *k, char *str)
{
	*n = *n * -1;
	*j = num_len(*n) + 1;
	str = (char *)ft_calloc((*j + 1), 1);
	if (!str)
		return (0);
	str[0] = '-';
	*k = 1;
	return (str);
}

void	init_var(long *i, long *k, char **str)
{
	*k = 0;
	*i = -1;
	*str = 0;
}

void	cycle(long *i, long *j, long *n, char *str)
{
	str[*j - *i - 1] = (*n % 10) + '0';
	*n = *n / 10;
}

char	*ft_itoa(long n)
{
	char	*str;
	long	i;
	long	j;
	long	k;

	j = num_len(n);
	init_var(&i, &k, &str);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		str = init(&n, &j, &k, str);
		if (!str)
			return (0);
	}
	else
	{
		str = (char *) ft_calloc(j + 1, 1);
		if (!str)
			return (0);
	}
	while (++i < j - k)
		cycle(&i, &j, &n, str);
	str[j] = 0;
	return (str);
}

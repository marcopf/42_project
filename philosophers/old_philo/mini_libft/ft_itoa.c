/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:22:51 by marco             #+#    #+#             */
/*   Updated: 2023/03/06 09:44:15 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../philosophers.h"

// static unsigned long	ft_dim(unsigned long n)
// {
// 	double	dim;

// 	if (!n)
// 		return (1);
// 	dim = 0;
// 	if (n < 0)
// 		dim++;
// 	while (n)
// 	{
// 		n /= 10;
// 		dim++;
// 	}
// 	return (dim);
// }

// static unsigned long	ft_abs(unsigned long n)
// {
// 	if (n < 0)
// 		return (-n);
// 	return (n);
// }

// char	*ft_itoa(unsigned long n)
// {
// 	char			*num;
// 	size_t			dim;
// 	unsigned long	m;

// 	dim = ft_dim(n);
// 	num = (char *) malloc((dim + 1) * sizeof (char));
// 	if (!num)
// 		return (0);
// 	num[dim] = 0;
// 	m = n;
// 	while (dim--)
// 	{
// 		num[dim] = ft_abs(n % 10) + 48;
// 		n /= 10;
// 	}
// 	if (m < 0)
// 		num[0] = '-';
// 	return (num);
// }

unsigned long	num_len(unsigned long n)
{
	unsigned long	i;

	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*init(unsigned long *n, unsigned long *j, unsigned long *k, char *str)
{
	*n = *n * -1;
	*j = num_len(*n) + 1;
	str = (char *) malloc(sizeof(char) * (*j + 1));
	if (!str)
		return (0);
	str[0] = '-';
	*k = 1;
	return (str);
}

void	init_var(unsigned long *i, unsigned long *k, char **str)
{
	*k = 0;
	*i = -1;
	*str = 0;
}

void	cycle(unsigned long *i, unsigned long *j, unsigned long *n, char *str)
{
	str[*j - *i - 1] = (*n % 10) + '0';
	*n = *n / 10;
}

char	*ft_itoa(unsigned long n)
{
	char				*str;
	unsigned long		i;
	unsigned long		j;
	unsigned long		k;

	j = num_len(n);
	init_var(&i, &k, &str);
	if (n < 0)
	{
		str = init(&n, &j, &k, str);
		if (!str)
			return (0);
	}
	else
	{
		str = (char *) malloc((sizeof(char) * j) + 1);
		if (!str)
			return (0);
	}
	while (++i < j - k)
		cycle(&i, &j, &n, str);
	str[j] = 0;
	return (str);
}

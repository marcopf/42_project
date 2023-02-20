/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_calculator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:31:51 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/18 15:18:16 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

int	is_min(int *list, int len)
{
	int	i;
	int	val;

	i = -1;
	val = list[0];
	while (++i < len)
	{
		if (list[i] < val)
			val = list[i];
	}
	return (val);
}

int	is_max(t_stacks *stacks, int n)
{
	int	i;

	i = -1;
	while (++i < stacks->stack_a.placed_number)
	{
		if (n < stacks->stack_a.list[i])
			return (0);
	}
	return (1);
}

int	is_min_greed(t_stacks *stacks, int n)
{
	int	i;

	i = -1;
	while (++i < stacks->stack_a.placed_number)
	{
		if (n > stacks->stack_a.list[i])
			return (0);
	}
	return (1);
}

int	is_in_between_max(t_stacks *stacks, int *i, int *index)
{
	if (is_max(stacks, stacks->stack_b.list[0]))
	{
		if (is_min_greed(stacks, stacks->stack_a.list[0]))
		{
			*index = *i;
			return (0);
		}
		while (stacks->stack_a.list[*i] < stacks->stack_a.list[(*i) + 1])
			(*i)++;
		*index = (*i) + 1;
		return (0);
	}
	else if (is_min_greed(stacks, stacks->stack_b.list[0]))
	{
		while (stacks->stack_a.list[*i] < stacks->stack_a.list[(*i) + 1])
			(*i)++;
		*index = (*i) + 1;
		return (0);
	}
	return (1);
}

int	is_in_between(t_stacks *stacks)
{
	int	i;
	int	index;

	i = -1;
	index = 0;
	while (++i < stacks->stack_a.placed_number - 1)
	{
		if (!is_in_between_max(stacks, &i, &index))
			break ;
		else if (stacks->stack_b.list[0] > stacks->stack_a.list[i]
			&& stacks->stack_b.list[0] < stacks->stack_a.list[i + 1])
		{
			index = i + 1;
			break ;
		}
	}
	if (index > (stacks->stack_a.placed_number / 2))
		index = (stacks->stack_a.placed_number - index) + 1000;
	return (index);
}

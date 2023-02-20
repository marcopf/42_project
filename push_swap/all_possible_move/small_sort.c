/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:29:20 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/18 20:31:00 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

int	is_sorted(t_stacks *stacks)
{
	int	i;

	i = -1;
	while (++i < stacks->stack_a.placed_number - 1)
	{
		if (stacks->stack_a.list[i] > stacks->stack_a.list[i + 1])
			return (0);
	}
	return (1);
}

void	small_sort_2(t_stacks *stacks)
{
	if (stacks->stack_a.list[0] > stacks->stack_a.list[1]
		&& stacks->stack_a.list[1] < stacks->stack_a.list[2]
		&& stacks->stack_a.list[0] < stacks->stack_a.list[2])
		sa(stacks, 1);
	else if (stacks->stack_a.list[0] > stacks->stack_a.list[1]
		&& stacks->stack_a.list[1] > stacks->stack_a.list[2])
	{
		sa(stacks, 1);
		rra(stacks, 1);
	}
	else if (stacks->stack_a.list[0] > stacks->stack_a.list[1]
		&& stacks->stack_a.list[1] < stacks->stack_a.list[2]
		&& stacks->stack_a.list[0] > stacks->stack_a.list[2])
		ra(stacks, 1);
	else if (stacks->stack_a.list[0] < stacks->stack_a.list[1]
		&& stacks->stack_a.list[1] > stacks->stack_a.list[2]
		&& stacks->stack_a.list[0] > stacks->stack_a.list[2])
		rra(stacks, 1);
	else if (stacks->stack_a.list[0] < stacks->stack_a.list[1]
		&& stacks->stack_a.list[1] > stacks->stack_a.list[2]
		&& stacks->stack_a.list[0] < stacks->stack_a.list[2])
	{
		sa(stacks, 1);
		ra(stacks, 1);
	}
}

void	small_sort(t_stacks *stacks)
{
	if (stacks->stack_a.placed_number == 2)
	{
		if (stacks->stack_a.list[0] > stacks->stack_a.list[1])
			ra(stacks, 1);
	}
	if (stacks->stack_a.placed_number == 3)
		small_sort_2(stacks);
	free(stacks->stack_a.list);
	free(stacks->stack_b.list);
	exit(0);
}

void	small_sort_for_medium(t_stacks *stacks)
{
	if (stacks->stack_a.placed_number == 2)
	{
		if (stacks->stack_a.list[0] > stacks->stack_a.list[1])
			ra(stacks, 1);
	}
	if (stacks->stack_a.placed_number == 3)
		small_sort_2(stacks);
}

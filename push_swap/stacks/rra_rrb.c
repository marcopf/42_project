/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:10:18 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/16 14:55:47 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	rra(t_stacks *stacks, int flag)
{
	int	i;
	int	*new_arr;

	i = -1;
	new_arr = 0;
	if (stacks->stack_a.placed_number > 1)
	{
		new_arr = (int *) malloc(sizeof(int) * stacks->list_len);
		while (++i < stacks->stack_a.placed_number - 1)
			new_arr[i + 1] = stacks->stack_a.list[i];
		new_arr[0] = stacks->stack_a.list[stacks->stack_a.placed_number - 1];
		free(stacks->stack_a.list);
		stacks->stack_a.list = new_arr;
	}
	if (flag)
		write(1, "rra\n", 4);
}

void	rrb(t_stacks *stacks, int flag)
{
	int	i;
	int	*new_arr;

	i = -1;
	new_arr = 0;
	if (stacks->stack_b.placed_number > 1)
	{
		new_arr = (int *) malloc(sizeof(int) * stacks->list_len);
		while (++i < stacks->stack_b.placed_number - 1)
			new_arr[i + 1] = stacks->stack_b.list[i];
		new_arr[0] = stacks->stack_b.list[stacks->stack_b.placed_number - 1];
		free(stacks->stack_b.list);
		stacks->stack_b.list = new_arr;
	}
	if (flag)
		write(1, "rrb\n", 4);
}

int	counter(void)
{
	static int	i;

	return (i++);
}

void	rrr(t_stacks *stacks, int flag)
{
	rra(stacks, 0);
	rrb(stacks, 0);
	if (flag)
		write(1, "rrr\n", 4);
}

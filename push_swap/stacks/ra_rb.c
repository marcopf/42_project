/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:59:19 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/18 09:25:54 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	ra(t_stacks *stacks, int flag)
{
	int	i;
	int	*new_arr;

	i = 0;
	new_arr = 0;
	if (stacks->stack_a.placed_number > 1)
	{
		new_arr = (int *) malloc(sizeof(int) * stacks->list_len);
		while (++i < stacks->stack_a.placed_number)
			new_arr[i - 1] = stacks->stack_a.list[i];
		new_arr[i - 1] = stacks->stack_a.list[0];
		free(stacks->stack_a.list);
		stacks->stack_a.list = new_arr;
	}
	if (flag)
		write(1, "ra\n", 3);
}

void	rb(t_stacks *stacks, int flag)
{
	int	i;
	int	*new_arr;

	i = 0;
	new_arr = 0;
	if (stacks->stack_b.placed_number > 1)
	{
		new_arr = (int *) malloc(sizeof(int) * stacks->list_len);
		while (++i < stacks->stack_b.placed_number)
			new_arr[i - 1] = stacks->stack_b.list[i];
		new_arr[i - 1] = stacks->stack_b.list[0];
		free(stacks->stack_b.list);
		stacks->stack_b.list = new_arr;
	}
	if (flag)
		write(1, "rb\n", 3);
}

void	rr(t_stacks *stacks, int flag)
{
	ra(stacks, 0);
	rb(stacks, 0);
	if (flag)
		write(1, "rr\n", 3);
}

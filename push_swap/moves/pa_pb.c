/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:29:05 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/18 10:10:36 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	pa(t_stacks *stacks, int k, int flag)
{
	int	*new_arr;
	int	*new;
	int	i;

	i = 0;
	if (stacks->stack_b.placed_number < 1)
		return ;
	if (stacks->stack_b.placed_number >= 1)
		k = 1;
	new_arr = (int *) malloc(sizeof(int) * stacks->stack_a.placed_number + 1);
	new = (int *) malloc(sizeof(int) * stacks->stack_b.placed_number - 1 + k);
	new_arr[0] = stacks->stack_b.list[0];
	while ((++i) <= stacks->stack_a.placed_number)
		new_arr[i] = stacks->stack_a.list[i - 1];
	free(stacks->stack_a.list);
	stacks->stack_a.list = new_arr;
	stacks->stack_a.placed_number += 1;
	i = 0;
	while (++i < stacks->stack_b.placed_number)
		new[i - 1] = stacks->stack_b.list[i];
	free(stacks->stack_b.list);
	stacks->stack_b.list = new;
	stacks->stack_b.placed_number -= 1;
	if (flag)
		write(1, "pa\n", 3);
}

void	pb(t_stacks *stacks, int k, int flag)
{
	int	*new_arr;
	int	*new;
	int	i;

	i = 0;
	if (stacks->stack_a.placed_number < 1)
		return ;
	if (stacks->stack_a.placed_number >= 0)
		k = 1;
	new_arr = (int *) malloc(sizeof(int) * stacks->stack_b.placed_number + 1);
	new = (int *) malloc(sizeof(int) * stacks->stack_a.placed_number - 1 + k);
	new_arr[0] = stacks->stack_a.list[0];
	while ((++i) <= stacks->stack_b.placed_number)
		new_arr[i] = stacks->stack_b.list[i - 1];
	free(stacks->stack_b.list);
	stacks->stack_b.list = new_arr;
	stacks->stack_b.placed_number += 1;
	i = 0;
	while (++i < stacks->stack_a.placed_number)
		new[i - 1] = stacks->stack_a.list[i];
	free(stacks->stack_a.list);
	stacks->stack_a.list = new;
	stacks->stack_a.placed_number -= 1;
	if (flag)
		write(1, "pb\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:37:49 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/16 22:48:53 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	sa(t_stacks *stacks, int flag)
{
	int	temp;

	if (stacks->stack_a.placed_number > 2)
	{
		temp = stacks->stack_a.list[0];
		stacks->stack_a.list[0] = stacks->stack_a.list[1];
		stacks->stack_a.list[1] = temp;
	}
	if (flag)
		write(1, "sa\n", 3);
}

void	sb(t_stacks *stacks, int flag)
{
	int	temp;

	if (stacks->stack_b.placed_number > 2)
	{
		temp = stacks->stack_b.list[0];
		stacks->stack_b.list[0] = stacks->stack_b.list[1];
		stacks->stack_b.list[1] = temp;
	}
	if (flag)
		write(1, "sb\n", 3);
}

void	ss(t_stacks *stacks, int flag)
{
	sa(stacks, 0);
	sb(stacks, 0);
	if (flag)
		write(1, "ss\n", 3);
}

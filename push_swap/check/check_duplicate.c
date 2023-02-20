/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:46:10 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/20 11:08:18 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	finish(t_stacks *stacks)
{
	if (stacks->stack_a.list)
		free(stacks->stack_a.list);
	if (stacks->stack_b.list)
		free(stacks->stack_b.list);
	write(2, "Error\n", 6);
	exit(0);
}

void	finish_no_e(t_stacks *stacks)
{
	if (stacks->stack_a.list)
		free(stacks->stack_a.list);
	if (stacks->stack_b.list)
		free(stacks->stack_b.list);
	exit(0);
}

int	duplicate_check(t_stacks *stacks)
{
	int	i;
	int	j;

	i = -1;
	while (++i < stacks->stack_a.placed_number)
	{
		j = -1;
		while (++j < stacks->stack_a.placed_number)
		{
			if (i != j && stacks->stack_a.list[i] == stacks->stack_a.list[j])
				finish(stacks);
		}
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:41:37 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/18 18:03:03 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	decision_maker(t_stacks *stacks, int *arr, int *temp, int *i)
{
	if (*i > stacks->stack_b.placed_number / 2)
		*temp = is_in_between(stacks)
			+ (stacks->stack_b.placed_number - *i);
	else
		*temp = is_in_between(stacks) + *i;
	if (*temp >= 1000)
	{
		if (arr[0] >= (*temp - 1000))
		{
			arr[0] = *temp - 1000;
			arr[1] = *i;
			arr[2] = 1;
		}
	}
	else
	{
		if (arr[0] > *temp)
		{
			arr[0] = *temp;
			arr[1] = *i;
			arr[2] = 0;
		}
	}
	rb(stacks, 0);
}

void	loop(t_stacks *stacks, int *arr, int *temp, int *i)
{
	while (++(*i) < stacks->stack_b.placed_number)
	{
		decision_maker(stacks, arr, temp, i);
	}
	if (arr[1] > stacks->stack_b.placed_number / 2)
		arr[0] -= stacks->stack_b.placed_number - arr[1];
	else
		arr[0] -= arr[1];
}

int	*move_selector(t_stacks *stacks)
{
	int	*arr;
	int	i;
	int	temp;

	i = -1;
	temp = 0;
	arr = (int *)malloc(sizeof(int) * 4);
	arr[0] = is_in_between(stacks);
	arr[1] = 0;
	arr[2] = 0;
	arr[3] = 0;
	if (arr[0] >= 1000)
	{
		arr[0] -= 1000;
		arr[2] = 1;
	}
	loop(stacks, arr, &temp, &i);
	if (arr[1] > (stacks->stack_b.placed_number / 2))
	{
		arr[1] = stacks->stack_b.placed_number - arr[1];
		arr[3] = 1;
	}
	return (arr);
}

void	move_combine(t_stacks *stacks, int *move)
{
	while ((move[0]) > 0 && (move[1]) > 0)
	{
		if (move[2] == 0 && move[3] == 0)
		{
			rr(stacks, 1);
			move[0]--;
			move[1]--;
		}
		else if (move[2] == 1 && move[3] == 1)
		{
			rrr(stacks, 1);
			move[0]--;
			move[1]--;
		}
		else
			break ;
	}
}

void	sort(t_stacks *stacks)
{
	int	*move;

	move = 0;
	while (stacks->stack_b.placed_number > 0)
	{
		move = move_selector(stacks);
		move_combine(stacks, move);
		if (move[2] == 1 && move[0] > 0)
			while (move[0]-- > 0)
				rra(stacks, 1);
		else
			while (move[0]-- > 0)
				ra(stacks, 1);
		if (move[3] == 1 && move[1] > 0)
			while (move[1]-- > 0)
				rrb(stacks, 1);
		else
			while (move[1]-- > 0)
				rb(stacks, 1);
		pa(stacks, 0, 1);
		free(move);
	}
}

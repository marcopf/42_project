/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:57:41 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/20 11:44:05 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc < 2)
		return (0);
	else if (argc > 2)
		fill_stack_double(&stacks, argv, argc);
	else
		fill_stack(&stacks, argv[1]);
	duplicate_check(&stacks);
	if (is_sorted(&stacks))
		finish_no_e(&stacks);
	if (stacks.stack_a.placed_number <= 3)
		small_sort(&stacks);
	push_all_b(&stacks);
	sort(&stacks);
	ascend(&stacks);
	finish_no_e(&stacks);
	return (0);
}

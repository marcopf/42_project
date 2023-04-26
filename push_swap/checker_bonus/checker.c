/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 22:31:02 by marco             #+#    #+#             */
/*   Updated: 2023/04/22 08:29:24 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	free_stacks(t_stacks *stacks)
{
	if (stacks->stack_a.list)
		free(stacks->stack_a.list);
	if (stacks->stack_b.list)
		free(stacks->stack_b.list);
}

int	ft_strncmp(const char *s1, const char *s2)
{
	int		i;
	int		n;

	n = ft_strlen(s2);
	i = -1;
	while (++i < n)
	{
		if (s1[i] != s2[i] || (!s1[i] || !s2[i]))
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
	}
	return (0);
}

int	do_move(t_stacks *stacks, char	*str)
{
	if (!ft_strncmp(str, "ra\n"))
		ra(stacks, 0);
	else if (!ft_strncmp(str, "rra\n"))
		rra(stacks, 0);
	else if (!ft_strncmp(str, "rb\n"))
		rb(stacks, 0);
	else if (!ft_strncmp(str, "rrb\n"))
		rrb(stacks, 0);
	else if (!ft_strncmp(str, "sa\n"))
		sa(stacks, 0);
	else if (!ft_strncmp(str, "sb\n"))
		sb(stacks, 0);
	else if (!ft_strncmp(str, "pb\n"))
		pb(stacks, 0, 0);
	else if (!ft_strncmp(str, "pa\n"))
		pa(stacks, 0, 0);
	else if (!ft_strncmp(str, "rr\n"))
		rr(stacks, 0);
	else if (!ft_strncmp(str, "ss\n"))
		ss(stacks, 0);
	else if (!ft_strncmp(str, "rrr\n"))
		rrr(stacks, 0);
	else
		return (1);
	return (0);
}

int	get_input(t_stacks *stacks)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		if (do_move(stacks, str) != 0)
		{
			free(str);
			free_stacks(stacks);
			write(2, "Error\n", 6);
			exit(1);
		}
		free(str);
		str = get_next_line(0);
	}
	free(str);
	return (0);
}

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
	get_input(&stacks);
	if (is_sorted(&stacks) && stacks.stack_b.placed_number == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stacks(&stacks);
	return (0);
}

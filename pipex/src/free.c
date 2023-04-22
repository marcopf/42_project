/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 09:15:33 by marco             #+#    #+#             */
/*   Updated: 2023/04/22 22:12:19 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pipex.h"

/*
 * Descritpion: enanced free (see stdlib.h) in order to set at NULL the freed
 * 		pointer.
 * input:	the address of the pointer that will be freed casted as (void **).
 * Output:	na.
*/
void	ft_free(void **ptr_addr)
{
	if (!ptr_addr)
		return ;
	free(*ptr_addr);
	*ptr_addr = 0;
}

/*
 * Description:	free an array of pointers and set NULL each pointer in the array
 * 		and the array pointer itself.
 * Input:	the array of pointer address casted as (void ***).
 * Output:	na.
*/
void	ft_free_mat(void ***mat_addr)
{
	int	i;

	i = 0;
	if (!mat_addr || !(*mat_addr))
		return ;
	while ((*mat_addr)[i])
	{
		ft_free(&(*mat_addr)[i]);
		i++;
	}
	ft_free((void **)mat_addr);
}

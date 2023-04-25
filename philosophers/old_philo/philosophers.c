/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:46:56 by mpaterno          #+#    #+#             */
/*   Updated: 2023/03/06 11:46:57 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc < 5)
	{
		printf("too few arguments!\n");
		return (0);
	}
	if (argc > 6)
	{
		printf("too many arguments!\n");
		return (0);
	}
	pthread_mutex_init(&env.writing, NULL);
	if (!env_setter(argv, argc, &env))
	{
		printf("invalid input!\n");
		return (0);
	}
	if (thread_start(&env) == -1)
		return (0);
	thread_wait(&env);
	free(env.philo_arr);
	destroy_all_mutex(&env);
	pthread_mutex_destroy(&env.writing);
}

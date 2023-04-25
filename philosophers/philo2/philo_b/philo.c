/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 09:42:51 by marco             #+#    #+#             */
/*   Updated: 2023/04/24 18:00:03 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_env	env;

	sem_unlink("/sem");
	if (argc < 5)
		return (write(2, "to few arguments\n", 18));
	if (argc > 6)
		return (write(2, "to many arguments\n", 19));
	if (!env_init(&env, argc, argv))
		return (write(2, "Error: check your input\n", 25));
	make_philos(&env);
	while (waitpid(-1, 0, 0) != -1)
		;
	sem_close(env.sem);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:07:51 by marco             #+#    #+#             */
/*   Updated: 2023/04/25 23:04:34 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

double	get_ts2(struct timeval ts)
{
	gettimeofday(&ts, 0);
	return (((ts.tv_sec * 1000) + ts.tv_usec / 1000));
}

void	my_sleep(int ms)
{
	double			origin;
	struct timeval	ts;

	origin = get_ts2(ts);
	while (get_ts2(ts) - origin <= (double) ms)
		usleep(600);
}

void	launch_thread(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->philo_count)
		pthread_create(&env->philo[i].philo_t, 0, &philo_routine,
			(void *)&env->philo[i]);
}

void	wait_trhead(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->philo_count)
		pthread_join(env->philo[i].philo_t, 0);
	free(env->philo);
	env->philo = 0;
}

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc < 5)
		return (write(2, "to few arguments\n", 18));
	if (argc > 6)
		return (write(2, "to many arguments\n", 19));
	if (!env_init(&env, argc, argv))
		return (printf("Error\n"));
	launch_thread(&env);
	wait_trhead(&env);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:07:51 by marco             #+#    #+#             */
/*   Updated: 2023/04/24 22:52:56 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static double	get_ts2(struct timeval ts)
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

void	philo_say(t_env *env, int mode, int n)
{
	double	ts;
	int		id;

	id = n + 1;
	ts = get_ts2(env->philo[n].ts) - env->origin_time;
	if (mode == 0)
		printf("%.0f %d has taken a fork\n", ts, id);
	else if (mode == 1)
		printf("%.0f %d is eating\n", ts, id);
	else if (mode == 2)
		printf("%.0f %d is sleeping\n", ts, id);
	else if (mode == 3)
		printf("%.0f %d is thinking\n", ts, id);
	else if (mode == 4)
		printf("%.0f %d is died\n", ts, id);
}

void	die_all(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->philo_count)
		env->philo[i].is_alive = 0;
}

void	*death_timer(void *temp)
{
	t_philo	*philo;

	philo = (t_philo *)temp;
	philo->origin_time = get_ts2(philo->ts);
	while (get_ts2(philo->ts) - philo->origin_time
		< philo->back->time_to_die && (philo->back->meal_needed == -1
			|| philo->meal_count < philo->back->meal_needed))
		usleep(100);
	if (philo->meal_count == philo->back->meal_needed)
		philo->is_alive = 0;
	else
	{
		die_all(philo->back);
		usleep(1000);
		philo_say(philo->back, 4, philo->id);
	}
	return (0);
}

void	*philo_routine(void	*temp)
{
	t_philo	*philo;

	philo = (t_philo *)temp;
	if (philo->id % 2 != 0)
		my_sleep(10);
	if (pthread_create(&philo->clock, 0, &death_timer, temp) != 0)
		return (0);
	pthread_detach(philo->clock);
	while (philo->is_alive)
	{
		if (philo->back->philo_count == 1)
		{
			philo_say(philo->back, 0, philo->id);
			while (philo->is_alive)
				usleep(500);
			philo_say(philo->back, 4, philo->id);
			return (0);
		}
		pthread_mutex_lock(&philo->fork);
		philo_say(philo->back, 0, philo->id);
		pthread_mutex_lock(&philo->back->philo[philo->fork_index].fork);
		philo_say(philo->back, 0, philo->id);
		philo_say(philo->back, 1, philo->id);
		philo->origin_time = get_ts2(philo->ts);
		philo->meal_count++;
		my_sleep(philo->back->time_to_eat);
		pthread_mutex_unlock(&philo->back->philo[philo->fork_index].fork);
		pthread_mutex_unlock(&philo->fork);
		philo_say(philo->back, 2, philo->id);
		my_sleep(philo->back->time_to_sleep);
		philo_say(philo->back, 3, philo->id);
	}
	return (0);
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

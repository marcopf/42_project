/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:39:16 by marco             #+#    #+#             */
/*   Updated: 2023/04/24 21:37:42 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static double	get_ts(struct timeval ts)
{
	gettimeofday(&ts, 0);
	return (((ts.tv_sec * 1000) + ts.tv_usec / 1000));
}

static void	philo_routine(t_env *env, int id)
{
	sem_wait(env->sem);
	philo_say(env, 0, id);
	sem_wait(env->sem);
	env->death_init = get_ts(env->time);
	philo_say(env, 0, id);
	philo_say(env, 1, id);
	env->meal_count++;
	my_sleep(env->time_to_eat);
	sem_post(env->sem);
	sem_post(env->sem);
	philo_say(env, 2, id);
	my_sleep(env->time_to_sleep);
	philo_say(env, 3, id);
}

void	*death_timer(void *temp)
{
	t_env	*env;
	double	delta;

	env = (t_env *)temp;
	env->death_init = get_ts(env->time);
	while (get_ts(env->time) - env->death_init < env->time_to_die
		&& (env->meal_needed == -1 || env->meal_count < env->meal_needed))
		usleep(100);
	if (env->meal_count == env->meal_needed)
		env->counter++;
	else
		philo_say(env, 4, env->id);
	sem_post(env->sem);
	sem_post(env->sem);
	sem_close(env->sem);
	env->is_alive = 0;
	kill(0, SIGKILL);
	return (0);
}

void	philo_proc(t_env *env, int id)
{
	int			pid;
	pthread_t	t1;

	pid = fork();
	if (!pid)
	{
		env->id = id;
		if (id % 2 == 0 && env->philo_count > 1)
			my_sleep(10);
		pthread_create(&t1, 0, &death_timer, (void *)env);
		pthread_detach(t1);
		while (env->is_alive)
			philo_routine(env, id);
		exit(0);
	}
}

void	make_philos(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->philo_count)
	{
		philo_proc(env, i);
		i++;
	}
}

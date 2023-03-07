/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_life.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 08:44:31 by marco             #+#    #+#             */
/*   Updated: 2023/03/06 11:30:00 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static double	get_ts(struct timeval ts)
{
	gettimeofday(&ts, 0);
	return (((ts.tv_sec * 1000) + ts.tv_usec / 1000));
}

static void	philo_say(const char *str, t_philo *philo)
{
	char	*ts;

	ts = ft_itoa(get_ts(philo->ts) - philo->back->origin_time);
	pthread_mutex_lock(&philo->back->writing);
	if (philo->back->is_alive)
		printf("%s %s %s\n", ts, philo->id_str, str);
	pthread_mutex_unlock(&philo->back->writing);
	free(ts);
}

static void	try_to_eat(t_env *env, int i)
{
	if (env->arr_len == 1)
	{
		philo_say("has taken a fork", &env->philo_arr[i]);
		while (env->is_alive)
			usleep(100);
		return ;
	}
	pthread_mutex_lock(&env->philo_arr[env->philo_arr[i].fork_index].fork);
	philo_say("has taken a fork", &env->philo_arr[i]);
	pthread_mutex_lock(&env->philo_arr[i].fork);
	env->philo_arr[i].init_ts = get_ts(env->philo_arr[i].ts);
	philo_say("has taken a fork", &env->philo_arr[i]);
	philo_say("is eating", &env->philo_arr[i]);
	usleep(env->time_to_eat * 1000);
	env->philo_arr[i].eat_count++;
	pthread_mutex_unlock(&env->philo_arr[env->philo_arr[i].fork_index].fork);
	pthread_mutex_unlock(&env->philo_arr[i].fork);
}

void	*timer(void *void_philo)
{
	t_philo			*philo;

	philo = (t_philo *)void_philo;
	philo->init_ts = get_ts(philo->ts);
	while (((get_ts(philo->ts) - philo->init_ts) <= philo->back->time_to_die)
		&& (philo->back->philosopher_n))
		usleep(100);
	if ((!philo->back->philosopher_n))
		philo->back->is_alive = 0;
	philo_say("died", philo);
	philo->back->is_alive = 0;
	return (0);
}

void	*philo_routine(void *void_philo)
{
	t_philo			*philo;

	philo = (t_philo *)void_philo;
	if (philo->id % 2 == 0)
		usleep(50 * 1000);
	if (pthread_create(&philo->clock, 0, &timer, void_philo) != 0)
		return (0);
	pthread_detach(philo->clock);
	usleep(100);
	while (philo->back->is_alive && philo->back->how_many_eat != 0)
	{
		try_to_eat(philo->back, philo->id);
		if (philo->eat_count == philo->back->how_many_eat)
		{
			pthread_mutex_lock(&philo->back->eating);
			philo->back->philosopher_n--;
			pthread_mutex_unlock(&philo->back->eating);
			break ;
		}	
		philo_say("is sleeping", philo);
		usleep(philo->back->time_to_sleep * 1000);
		philo_say("is thinking", philo);
	}
	return (0);
}

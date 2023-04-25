/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:42:34 by marco             #+#    #+#             */
/*   Updated: 2023/04/24 22:51:01 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		usleep(400);
}

void	philo_say(t_env *env, int mode, int n)
{
	double	ts;
	int		id;

	id = n + 1;
	ts = get_ts2(env->time) - env->origin_time;
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

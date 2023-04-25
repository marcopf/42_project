/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:37:36 by marco             #+#    #+#             */
/*   Updated: 2023/04/24 22:50:50 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static double	get_ts1(struct timeval ts)
{
	gettimeofday(&ts, 0);
	return (((ts.tv_sec * 1000) + ts.tv_usec / 1000));
}

static int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32)
		i++;
	if (str[i] == 45)
		sign = -1;
	if (str[i] == 43 || str[i] == 45)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
		res = (res * 10) + (str[i++] - 48);
	if (str[i] != 0)
		return (0);
	return (res * sign);
}

static int	input_check(t_env *env, char *str)
{
	int	temp;

	temp = ft_atoi(str);
	if (temp == 0 && str[0] != '0' || temp < 0)
		env->error = 1;
	return (temp);
}

int	env_init(t_env *env, int argc, char **argv)
{
	env->error = 0;
	env->counter = 0;
	env->is_alive = 1;
	env->meal_count = 0;
	env->origin_time = get_ts1(env->time);
	env->philo_count = input_check(env, argv[1]);
	env->time_to_die = input_check(env, argv[2]);
	env->time_to_sleep = input_check(env, argv[4]);
	env->time_to_eat = input_check(env, argv[3]);
	if (argc > 5)
		env->meal_needed = input_check(env, argv[5]);
	else
		env->meal_needed = -1;
	env->sem = sem_open("/sem", O_CREAT, 0660, env->philo_count);
	if (env->error)
		return (0);
	return (1);
}

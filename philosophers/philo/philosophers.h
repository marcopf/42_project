/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:08:12 by marco             #+#    #+#             */
/*   Updated: 2023/04/25 23:05:28 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <semaphore.h>
# include <string.h>
# include <signal.h>
# include <time.h>
# include <sys/time.h>
# include <fcntl.h>
# include <sys/stat.h> 
# include <pthread.h>

struct	s_env;

typedef struct s_philo
{
	int				id;
	int				fork_index;
	int				meal_count;
	int				is_alive;
	struct timeval	ts;
	double			origin_time;
	pthread_t		philo_t;
	pthread_t		clock;
	pthread_mutex_t	fork;
	struct s_env	*back;
}	t_philo;

typedef struct s_env
{
	int				meal_needed;
	int				counter;
	int				error;
	int				philo_count;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	double			origin_time;
	struct timeval	ts;
	t_philo			*philo;
}	t_env;

double	get_ts2(struct timeval ts);
void	my_sleep(int ms);
void	philo_init(t_env *env, int id);
int		env_init(t_env *env, int argc, char **argv);
void	*philo_routine(void	*temp);

#endif
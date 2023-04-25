/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 09:43:02 by marco             #+#    #+#             */
/*   Updated: 2023/04/24 17:58:33 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

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

// typedef struct s_philo
// {
// 	int		id;
// 	sem_t	fork;
// 	t_env	*back;
// }	t_philo;

typedef struct env
{
	sem_t			*sem;
	struct timeval	time;
	double			origin_time;
	int				is_alive;
	double			death_init;
	int				id;
	int				meal_count;
	int				meal_needed;
	int				counter;
	int				error;
	int				philo_count;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
}	t_env;

void		philo_say(t_env *env, int mode, int id);
void		my_sleep(int ms);
int			env_init(t_env *env, int argc, char **argv);
void		make_philos(t_env *env);


#endif
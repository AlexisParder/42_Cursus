/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 09:18:08 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/08 16:32:11 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	long			id;
	long			meals_eaten;
	long			last_meal_time;
	pthread_t		tid;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	meal_mutex;
	t_data			*data;
}	t_philo;

struct s_data
{
	long			nb_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			max_meals;
	long			start_time;
	int				dead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	t_philo			*philos;
	pthread_t		monitor_tid;
};

int		init_data(t_data *data, int ac, char **av);
int		manage_threads(t_data *data);
int		is_dead(t_data *data);

long	philo_atol(const char *nptr);
long	get_time_ms(void);

void	write_fd(int fd, char *err);
void	clean_all(t_data *data);
void	clean_err(t_data *data);
void	clean_mutex_forks(pthread_mutex_t *forks, long last);
void	clean_mutex_philos(t_data *data, long last);
void	ft_usleep(long time_ms);
void	print_action(t_philo *philo, char *msg);
void	set_dead(t_data *data);

void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);

void	*monitor(void *arg);

#endif
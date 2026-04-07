/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 09:17:30 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/07 09:25:22 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static int	init_mutex(t_data *data)
{
	long	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (!data->forks)
		return (1);
	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			clean_mutex_forks(data->forks, i);
			return (1);
		}
		i++;
	}
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->death_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&data->print_mutex);
		return (1);
	}
	return (0);
}

static void	fill_philo(t_data *data, long i)
{
	data->philos[i].id = i + 1;
	data->philos[i].meals_eaten = 0;
	data->philos[i].last_meal_time = data->start_time;
	data->philos[i].left_fork = &data->forks[i];
	data->philos[i].right_fork = &data->forks[(i + 1) % data->nb_philos];
	data->philos[i].data = data;
}

static int	init_philos(t_data *data)
{
	long	i;

	data->philos = malloc(sizeof(t_philo) * data->nb_philos);
	if (!data->philos)
	{
		pthread_mutex_destroy(&data->print_mutex);
		pthread_mutex_destroy(&data->death_mutex);
		clean_mutex_forks(data->forks, data->nb_philos);
		return (1);
	}
	i = 0;
	while (i < data->nb_philos)
	{
		fill_philo(data, i);
		if (pthread_mutex_init(&data->philos[i].meal_mutex, NULL) != 0)
		{
			pthread_mutex_destroy(&data->print_mutex);
			pthread_mutex_destroy(&data->death_mutex);
			clean_mutex_forks(data->forks, data->nb_philos);
			clean_mutex_philos(data, i);
			return (1);
		}
		i++;
	}
	return (0);
}

int	init_data(t_data *data, int ac, char **av)
{
	data->nb_philos = philo_atol(av[1]);
	data->time_to_die = philo_atol(av[2]);
	data->time_to_eat = philo_atol(av[3]);
	data->time_to_sleep = philo_atol(av[4]);
	if (ac == 6)
		data->max_meals = philo_atol(av[5]);
	else
		data->max_meals = -1;
	data->start_time = get_time_ms();
	data->dead = 0;
	data->forks = NULL;
	data->philos = NULL;
	if (init_mutex(data))
		return (1);
	if (init_philos(data))
		return (1);
	return (0);
}

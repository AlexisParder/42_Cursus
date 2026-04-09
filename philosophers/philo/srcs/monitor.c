/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:54:26 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/09 10:51:39 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static int	check_time(t_data *data, long i, long last_meal)
{
	t_philo	*philo;
	long	time;

	philo = &data->philos[i];
	time = get_time_ms();
	if (time - last_meal > data->time_to_die)
	{
		set_dead(data);
		pthread_mutex_lock(&data->print_mutex);
		printf("%ld %ld died\n", time - data->start_time, philo->id);
		pthread_mutex_unlock(&data->print_mutex);
		return (1);
	}
	return (0);
}

static int	check_philos(t_data *data, long *meals_done)
{
	long	i;
	long	last_meal;
	long	eaten;

	i = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_lock(&data->philos[i].meal_mutex);
		last_meal = data->philos[i].last_meal_time;
		eaten = data->philos[i].meals_eaten;
		pthread_mutex_unlock(&data->philos[i].meal_mutex);
		if (check_time(data, i, last_meal))
			return (1);
		if (data->max_meals != -1 && eaten >= data->max_meals)
			(*meals_done)++;
		i++;
	}
	return (0);
}

void	*monitor(void *arg)
{
	t_data	*data;
	long	meals_done;

	data = (t_data *)arg;
	while (!is_dead(data))
	{
		meals_done = 0;
		if (check_philos(data, &meals_done))
			return (NULL);
		if (data->max_meals != -1 && meals_done >= data->nb_philos)
		{
			set_dead(data);
			return (NULL);
		}
		usleep(100);
	}
	return (NULL);
}

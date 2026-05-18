/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:54:26 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/10 09:09:00 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static int	check_time(t_data *data, long i)
{
	t_philo	*philo;
	long	time;
	long	last_meal;

	philo = &data->philos[i];
	time = get_time_ms();
	pthread_mutex_lock(&philo->meal_mutex);
	last_meal = philo->last_meal_time;
	pthread_mutex_unlock(&philo->meal_mutex);
	if (time - last_meal >= data->time_to_die)
	{
		set_dead(data);
		pthread_mutex_lock(&data->print_mutex);
		printf("%ld %ld died\n", time - data->start_time, philo->id);
		pthread_mutex_unlock(&data->print_mutex);
		return (1);
	}
	return (0);
}

static int	check_philos(t_data *data)
{
	long	i;
	long	eaten;
	long	meals_done;

	if (data->max_meals == -1)
		return (0);
	i = 0;
	meals_done = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_lock(&data->philos[i].meal_mutex);
		eaten = data->philos[i].meals_eaten;
		pthread_mutex_unlock(&data->philos[i].meal_mutex);
		if (eaten >= data->max_meals)
			meals_done++;
		if (meals_done >= data->nb_philos)
			break ;
		i++;
	}
	if (meals_done >= data->nb_philos)
	{
		set_dead(data);
		return (1);
	}
	return (0);
}

void	*monitor(void *arg)
{
	t_data	*data;
	long	i;

	data = (t_data *)arg;
	while (!is_dead(data))
	{
		i = 0;
		while (i < data->nb_philos)
		{
			if (check_time(data, i))
				return (NULL);
			i++;
		}
		if (check_philos(data))
			return (NULL);
		usleep(100);
	}
	return (NULL);
}

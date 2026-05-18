/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:15:42 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/10 09:07:52 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	set_last_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = get_time_ms();
	pthread_mutex_unlock(&philo->meal_mutex);
}

static void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	set_last_meal_time(philo);
	if (data->nb_philos == 1)
	{
		philo_eat(philo);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		ft_usleep(data->time_to_eat / 2);
	while (!is_dead(data))
	{
		if (data->max_meals != -1 && philo->meals_eaten >= data->max_meals)
			break ;
		philo_eat(philo);
		if (is_dead(data))
			break ;
		print_action(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep);
		philo_think(philo);
	}
	return (NULL);
}

static long	create_threads(t_data *data)
{
	long	i;

	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_create(&data->philos[i].tid, NULL,
				routine, &data->philos[i]) != 0)
		{
			set_dead(data);
			pthread_mutex_lock(&data->print_mutex);
			write_fd(2, "Error: pthread_create failed\n");
			pthread_mutex_unlock(&data->print_mutex);
			break ;
		}
		i++;
	}
	return (i);
}

int	manage_threads(t_data *data)
{
	long	i;
	long	j;

	if (pthread_create(&data->monitor_tid, NULL, monitor, data) != 0)
		return (1);
	i = create_threads(data);
	j = 0;
	while (j < i)
	{
		pthread_join(data->philos[j].tid, NULL);
		j++;
	}
	pthread_join(data->monitor_tid, NULL);
	return (0);
}

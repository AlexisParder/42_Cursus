/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:15:42 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/06 15:09:35 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	pthread_mutex_lock(&data->print_mutex);
	printf("Philo %ld has started routine\n", philo->id);
	pthread_mutex_unlock(&data->print_mutex);
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
			pthread_mutex_lock(&data->death_mutex);
			data->dead = 1;
			pthread_mutex_unlock(&data->death_mutex);
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

	i = create_threads(data);
	j = 0;
	while (j < i)
	{
		pthread_join(data->philos[j].tid, NULL);
		j++;
	}
	return (0);
}

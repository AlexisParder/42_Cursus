/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:15:42 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/06 13:48:16 by achauvie         ###   ########.fr       */
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
	printf("Philo %ld has start routine\n", philo->id);
	pthread_mutex_unlock(&data->print_mutex);
	return (NULL);
}

int	create_threads(t_data *dt)
{
	long	i;

	i = 0;
	while (i < dt->nb_philos)
	{
		if (pthread_create(&dt->philos[i].tid, NULL,
			routine, &dt->philos[i]) != 0)
		{
			print_error("Error: pthread_create failed\n");
			// Il faudrait clean
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < dt->nb_philos)
	{
		if (pthread_join(dt->philos[i].tid, NULL) != 0)
		{
			print_error("Error: pthread_join failed\n");
			// Il faudrait clean
			return (1);
		}
		i++;
	}
	return (0);
}

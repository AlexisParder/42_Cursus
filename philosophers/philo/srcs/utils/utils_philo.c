/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 09:48:00 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/07 10:37:57 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	print_action(t_philo *philo, char *msg)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->print_mutex);
	if (!is_dead(data))
		printf("%ld %ld %s \n", get_time_ms() - data->start_time,
			philo->id, msg);
	pthread_mutex_unlock(&data->print_mutex);
}

int	is_dead(t_data *data)
{
	int	res;

	pthread_mutex_lock(&data->death_mutex);
	res = data->dead;
	pthread_mutex_unlock(&data->death_mutex);
	return (res);
}

void	set_dead(t_data *data)
{
	pthread_mutex_lock(&data->death_mutex);
	data->dead = 1;
	pthread_mutex_unlock(&data->death_mutex);
}

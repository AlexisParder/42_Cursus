/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 08:58:56 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/06 15:09:42 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	write_fd(int fd, char *err)
{
	size_t	len;

	len = 0;
	while (err[len])
		len++;
	write(fd, err, len);
}

void	clean_err(t_data *data)
{
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
}

void	clean_mutex_forks(pthread_mutex_t *forks, long last)
{
	long	i;

	i = 0;
	while (i < last)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

void	clean_mutex_philos(t_data *data, long last)
{
	long	i;

	i = 0;
	while (i < last)
	{
		pthread_mutex_destroy(&data->philos[i].meal_mutex);
		i++;
	}
}

void	clean_all(t_data *data)
{
	if (data->forks)
		clean_mutex_forks(data->forks, data->nb_philos);
	if (data->philos)
		clean_mutex_philos(data, data->nb_philos);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->death_mutex);
	clean_err(data);
}

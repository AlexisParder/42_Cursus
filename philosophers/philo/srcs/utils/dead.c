/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 09:48:00 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/09 12:51:00 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

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

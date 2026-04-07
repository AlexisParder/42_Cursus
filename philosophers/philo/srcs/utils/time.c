/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 09:05:34 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/07 16:47:33 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

long	get_time_ms(void)
{
	struct timeval	tv;
	long			time_ms;

	gettimeofday(&tv, NULL);
	time_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time_ms);
}

void	ft_usleep(long time_ms, t_data *data)
{
	long	start_time;

	start_time = get_time_ms();
	while (get_time_ms() - start_time < time_ms)
	{
		if (is_dead(data))
			return ;
		usleep(100);
	}
}

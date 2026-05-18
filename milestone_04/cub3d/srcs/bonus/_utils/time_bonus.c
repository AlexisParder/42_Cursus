/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:25:07 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/27 15:26:20 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

long	get_time_ms(void)
{
	struct timeval	time_val;
	long			res;

	gettimeofday(&time_val, NULL);
	res = (time_val.tv_sec * 1000) + (time_val.tv_usec / 1000);
	return (res);
}

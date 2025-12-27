/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 09:05:38 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/27 15:08:01 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

long	get_time_ms(void)
{
	struct timeval	time_val;
	long			res;

	gettimeofday(&time_val, NULL);
	res = (time_val.tv_sec * 1000) + (time_val.tv_usec / 1000);
	return (res);
}

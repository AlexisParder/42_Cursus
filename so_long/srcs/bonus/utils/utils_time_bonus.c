/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 09:05:38 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/26 09:13:06 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

long	get_time_ms(void)
{
	struct timeval	tv;
	long			res;

	gettimeofday(&tv, NULL);
	res = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_distance_player_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 08:51:19 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/28 08:53:11 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

static int	check_player_distance(long x, long y, long j, long i)
{
	long	dist_x;
	long	dist_y;

	if (x > j)
		dist_x = x - j;
	else
		dist_x = j - x;
	if (y > i)
		dist_y = y - i;
	else
		dist_y = i - y;
	if (dist_x <= 2 && dist_y <= 2)
		return (1);
	return (0);
}

int	player_too_close(t_gen_map *dt, long x, long y)
{
	long	i;
	long	j;

	i = 0;
	while (dt->map[i])
	{
		j = 0;
		while (dt->map[i][j])
		{
			if (dt->map[i][j] == 'P')
			{
				if (check_player_distance(x, y, j, i))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_gen_walls_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 08:38:21 by achauvie          #+#    #+#             */
/*   Updated: 2026/01/02 09:24:50 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

static int	wall_is_valid(t_gen_map *dt)
{
	t_map_dt	map_dt;

	map_dt.map = dt->map;
	map_dt.x_exit = dt->w;
	map_dt.y_max = dt->h;
	map_dt.total_loots = dt->c;
	if (check_map_path(&map_dt, 0))
		return (1);
	return (0);
}

static int	try_place_wall(t_gen_map *dt, long x, long y)
{
	char	base;

	if (dt->map[y][x] != '0')
		return (0);
	base = dt->map[y][x];
	dt->map[y][x] = '1';
	if (wall_is_valid(dt))
	{
		dt->space--;
		return (1);
	}
	dt->map[y][x] = base;
	return (0);
}

void	fill_walls_rnd(t_gen_map *dt)
{
	long	walls;
	long	x;
	long	y;

	walls = dt->space / 5;
	if (walls < 1)
		return ;
	while (walls)
	{
		x = rand() % dt->w;
		y = rand() % dt->h;
		if (try_place_wall(dt, x, y))
			walls--;
	}
}

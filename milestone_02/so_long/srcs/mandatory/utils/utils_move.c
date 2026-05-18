/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:04:42 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/23 12:42:11 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static int	check_move_rl(t_mlx_dt *dt, char move, size_t p_x, size_t p_y)
{
	size_t	map_max_x;

	map_max_x = dt->map_dt.x_max;
	if (move == MOVE_RIGHT)
	{
		if ((p_x + 1 >= map_max_x) || dt->map_dt.map[p_y][p_x + 1] == '1')
			return (0);
	}
	else if (move == MOVE_LEFT)
	{
		if ((p_x - 1 <= 0) || dt->map_dt.map[p_y][p_x - 1] == '1')
			return (0);
	}
	return (1);
}

static int	check_move_td(t_mlx_dt *dt, char move, size_t p_x, size_t p_y)
{
	size_t	map_max_y;

	map_max_y = dt->map_dt.y_max;
	if (move == MOVE_UP)
	{
		if ((p_y - 1 <= 0) || dt->map_dt.map[p_y - 1][p_x] == '1')
			return (0);
	}
	else if (move == MOVE_DOWN)
	{
		if ((p_y + 1 >= map_max_y) || dt->map_dt.map[p_y + 1][p_x] == '1')
			return (0);
	}
	return (1);
}

int	check_move(t_mlx_dt *mlx_data, char move, size_t p_x, size_t p_y)
{
	if (move == MOVE_RIGHT || move == MOVE_LEFT)
	{
		if (!check_move_rl(mlx_data, move, p_x, p_y))
			return (0);
	}
	else if (move == MOVE_UP || move == MOVE_DOWN)
	{
		if (!check_move_td(mlx_data, move, p_x, p_y))
			return (0);
	}
	return (1);
}

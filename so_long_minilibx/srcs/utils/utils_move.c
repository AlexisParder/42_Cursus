/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:04:42 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/10 11:33:02 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static int	check_move_rl(t_mlx_dt *mlx_dt, char move)
{
	size_t	p_x;
	size_t	p_y;
	size_t	map_max_x;

	p_x = mlx_dt->player->pos_x;
	p_y = mlx_dt->player->pos_y;
	map_max_x = mlx_dt->map_dt.x_max;
	if (move == 'r')
	{
		if ((p_x + 1 >= map_max_x) || mlx_dt->map_dt.map[p_y][p_x + 1] == '1')
			return (0);
	}
	else if (move == 'l')
	{
		if ((p_x - 1 <= 0) || mlx_dt->map_dt.map[p_y][p_x - 1] == '1')
			return (0);
	}
	return (1);
}

static int	check_move_td(t_mlx_dt *mlx_dt, char move)
{
	size_t	p_x;
	size_t	p_y;
	size_t	map_max_y;

	p_x = mlx_dt->player->pos_x;
	p_y = mlx_dt->player->pos_y;
	map_max_y = mlx_dt->map_dt.y_max;
	if (move == 't')
	{
		if ((p_y - 1 <= 0) || mlx_dt->map_dt.map[p_y - 1][p_x] == '1')
			return (0);
	}
	else if (move == 'd')
	{
		if ((p_y + 1 >= map_max_y) || mlx_dt->map_dt.map[p_y + 1][p_x] == '1')
			return (0);
	}
	return (1);
}

int	check_move(t_mlx_dt *mlx_data, char move)
{
	if (move == 'r' || move == 'l')
	{
		if (!check_move_rl(mlx_data, move))
			return (0);
	}
	else if (move == 't' || move == 'd')
	{
		if (!check_move_td(mlx_data, move))
			return (0);
	}
	return (1);
}

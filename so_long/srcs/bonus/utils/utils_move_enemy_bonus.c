/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_move_enemy_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:42:58 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/16 11:30:37 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

static int	check_move_en_rl(t_mlx_dt *dt, char move, size_t p_x, size_t p_y)
{
	size_t	map_max_x;

	map_max_x = dt->map_dt.x_max;
	if (move == 'r')
	{
		if ((p_x + 1 >= map_max_x) || dt->map_dt.map[p_y][p_x + 1] == '1')
			return (0);
		if (dt->map_dt.map[p_y][p_x + 1] == 'H')
			return (0);
	}
	else if (move == 'l')
	{
		if ((p_x - 1 <= 0) || dt->map_dt.map[p_y][p_x - 1] == '1')
			return (0);
		if (dt->map_dt.map[p_y][p_x - 1] == 'H')
			return (0);
	}
	return (1);
}

static int	check_move_en_td(t_mlx_dt *dt, char move, size_t p_x, size_t p_y)
{
	size_t	map_max_y;

	map_max_y = dt->map_dt.y_max;
	if (move == 't')
	{
		if ((p_y - 1 <= 0) || dt->map_dt.map[p_y - 1][p_x] == '1')
			return (0);
		if (dt->map_dt.map[p_y - 1][p_x] == 'H')
			return (0);
	}
	else if (move == 'd')
	{
		if ((p_y + 1 >= map_max_y) || dt->map_dt.map[p_y + 1][p_x] == '1')
			return (0);
		if (dt->map_dt.map[p_y + 1][p_x] == 'H')
			return (0);
	}
	return (1);
}

int	check_move_en(t_mlx_dt *mlx_dt, char move, size_t p_x, size_t p_y)
{
	if (move == 'r' || move == 'l')
	{
		if (!check_move_en_rl(mlx_dt, move, p_x, p_y))
			return (0);
	}
	else if (move == 't' || move == 'd')
	{
		if (!check_move_en_td(mlx_dt, move, p_x, p_y))
			return (0);
	}
	return (1);
}

static int	updt_arr(char *arr, char c, int count)
{
	arr[count] = c;
	count++;
	return (count);
}

char	random_dir(int l, int r, int t, int d)
{
	char	*dirs;
	int		count;
	char	res;

	count = l + r + t + d;
	dirs = ft_calloc(count, sizeof(char));
	if (!dirs)
		return (0);
	count = 0;
	if (l)
		count = updt_arr(dirs, 'l', count);
	if (r)
		count = updt_arr(dirs, 'r', count);
	if (t)
		count = updt_arr(dirs, 't', count);
	if (d)
		count = updt_arr(dirs, 'd', count);
	if (count == 0)
		return (0);
	res = dirs[rand() % count];
	free(dirs);
	return (res);
}

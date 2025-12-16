/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_moves_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:05:34 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/16 09:07:49 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

static void	updt_area(t_mlx_dt *mlx_data, size_t pos_x, size_t pos_y)
{
	if (mlx_data->map_dt.map[pos_y][pos_x] == 'E')
	{
		if (mlx_data->player->loot_collected >= mlx_data->map_dt.total_loots)
			display_win(mlx_data);
	}
	else if (mlx_data->map_dt.map[pos_y][pos_x] == 'C')
		mlx_data->player->loot_collected++;
	else if (mlx_data->map_dt.map[pos_y][pos_x] == 'H')
		display_lose(mlx_data);
}

void	updt_pl(t_mlx_dt *mlx_data)
{
	void	*img;

	if (mlx_data->player->direction == 'r')
		img = mlx_data->img_ref.pl_r;
	else if (mlx_data->player->direction == 'l')
		img = mlx_data->img_ref.pl_l;
	else if (mlx_data->player->direction == 't')
		img = mlx_data->img_ref.pl_t;
	else
		img = mlx_data->img_ref.pl_d;
	add_img_pl(mlx_data, img, mlx_data->player->pos_x, mlx_data->player->pos_y);
}

static void	updt_pl_move(t_mlx_dt *mlx_data, char move)
{
	if (move == 'r')
		mlx_data->player->pos_x++;
	else if (move == 'l')
		mlx_data->player->pos_x--;
	else if (move == 't')
		mlx_data->player->pos_y--;
	else if (move == 'd')
		mlx_data->player->pos_y++;
	mlx_data->player->direction = move;
	mlx_data->player->nb_move++;
}

void	make_move(t_mlx_dt *mlx_dt, char move)
{
	size_t	pos_x;
	size_t	pos_y;
	size_t	last_pos_x;
	size_t	last_pos_y;

	last_pos_x = mlx_dt->player->pos_x;
	last_pos_y = mlx_dt->player->pos_y;
	if (check_move(mlx_dt, move, last_pos_x, last_pos_y))
	{
		updt_pl_move(mlx_dt, move);
		pos_x = mlx_dt->player->pos_x;
		pos_y = mlx_dt->player->pos_y;
		updt_area(mlx_dt, pos_x, pos_y);
		mlx_dt->map_dt.map[last_pos_y][last_pos_x] = '0';
		mlx_dt->map_dt.map[mlx_dt->map_dt.y_exit][mlx_dt->map_dt.x_exit] = 'E';
		mlx_dt->map_dt.map[pos_y][pos_x] = 'P';
		redraw_window(mlx_dt);
		draw_enemies(mlx_dt);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:05:34 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/15 14:13:51 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	updt_area(t_mlx_dt *mlx_data, size_t pos_x, size_t pos_y)
{
	if (mlx_data->map_dt.map[pos_y][pos_x] == 'E')
	{
		if (mlx_data->player->loot_collected >= mlx_data->map_dt.total_loots)
		{
			ft_printf("YOU WIN !");
			close_game(mlx_data, EXIT_SUCCESS);
		}
	}
	else if (mlx_data->map_dt.map[pos_y][pos_x] == 'C')
		mlx_data->player->loot_collected++;
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
	mlx_data->player->nb_move++;
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
}

static void	display_move_shell(t_mlx_dt *mlx_data)
{
	char		*nb_move;

	nb_move = ft_itoa(mlx_data->player->nb_move);
	ft_printf("Number of movements: %s\n", nb_move);
	free(nb_move);
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
		display_move_shell(mlx_dt);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:05:34 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/09 09:30:38 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	updt_area(t_mlx_dt *mlx_data, size_t pos_x, size_t pos_y)
{
	if (mlx_data->map.map[pos_y][pos_x] == 'E')
	{
		if (mlx_data->player->loot_collected >= mlx_data->map.total_loots)
			mlx_loop_end((mlx_context)mlx_data->mlx);
		add_image(mlx_data, mlx_data->img_ref.exit, pos_x, pos_y);
	}
	else if (is_area_loot(mlx_data->loots, pos_x, pos_y))
	{
		if (can_loot(mlx_data->loots, pos_x, pos_y))
		{
			take_loot(mlx_data->loots, pos_x, pos_y);
			mlx_data->player->loot_collected++;
		}
		add_image(mlx_data, mlx_data->img_ref.path, pos_x, pos_y);
	}
	else
		add_image(mlx_data, mlx_data->img_ref.path, pos_x, pos_y);
}

static void	updt_pl(t_mlx_dt *mlx_data, size_t pos_x, size_t pos_y, char move)
{
	mlx_image	img;

	if (move == 'r')
		img = mlx_data->img_ref.pl_r;
	else if (move == 'l')
		img = mlx_data->img_ref.pl_l;
	else if (move == 't')
		img = mlx_data->img_ref.pl_t;
	else
		img = mlx_data->img_ref.pl_d;
	add_img_pl(mlx_data, img, pos_x, pos_y);
	mlx_data->player->nb_move++;
}

void	make_move(t_mlx_dt *mlx_data, char move)
{
	size_t	pos_x;
	size_t	pos_y;
	size_t	last_pos_x;
	size_t	last_pos_y;

	if (check_move(mlx_data, move))
	{
		last_pos_x = mlx_data->player->pos_x;
		last_pos_y = mlx_data->player->pos_y;
		if (move == 'r')
			mlx_data->player->pos_x++;
		else if (move == 'l')
			mlx_data->player->pos_x--;
		else if (move == 't')
			mlx_data->player->pos_y--;
		else if (move == 'd')
			mlx_data->player->pos_y++;
		pos_x = mlx_data->player->pos_x;
		pos_y = mlx_data->player->pos_y;
		updt_area(mlx_data, last_pos_x, last_pos_y);
		updt_area(mlx_data, pos_x, pos_y);
		updt_pl(mlx_data, pos_x, pos_y, move);
		ft_printf("NB MOVE: %s\n", ft_itoa(mlx_data->player->nb_move));
	}
}

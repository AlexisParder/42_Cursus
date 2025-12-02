/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:05:34 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/02 09:33:45 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

char	check_area(t_mlx_data *mlx_data, size_t pos_x, size_t pos_y)
{
	if (mlx_data->map.map[pos_y][pos_x] == 'E')
		return ('E');
	else if (is_area_loot(mlx_data->loots, pos_x, pos_y))
		return ('C');
	return (-1);
}

static void	updt_area(t_mlx_data *mlx_data, size_t pos_x, size_t pos_y)
{
	char	area_type;
	
	area_type = check_area(mlx_data, pos_x, pos_y);
	if (area_type == 'E')
	{
		if (mlx_data->player->loot_collected >= mlx_data->map.total_loots)
			ft_printf("FINNN");
		add_image(mlx_data, TEXTURE_EXIT, pos_x, pos_y);
	}
	else if (area_type == 'C')
	{
		remove_loot(mlx_data->loots, pos_x, pos_y);
		mlx_data->player->loot_collected++;
		add_image(mlx_data, TEXTURE_PATH, pos_x, pos_y);
	}
	else
		add_image(mlx_data, TEXTURE_PATH, pos_x, pos_y);
}

static void	updt_pl(t_mlx_data *mlx_data, size_t pos_x, size_t pos_y, char move)
{
	char	*texture;
	
	if (move == 'r')
		texture = TEXTURE_PLAYER_R;
	else if (move == 'l')
		texture = TEXTURE_PLAYER_L;
	else if (move == 't')
		texture = TEXTURE_PLAYER_T;
	else
		texture = TEXTURE_PLAYER_D;
	mlx_destroy_image((*mlx_data).mlx, mlx_data->player->img);
	add_img_pl(mlx_data,  texture, pos_x, pos_y);
	mlx_data->player->nb_move++;
}

void	make_move(t_mlx_data *mlx_data, char move)
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
	}
}

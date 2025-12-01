/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:05:34 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/01 15:37:14 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

char	check_case(t_mlx_data *mlx_data, size_t pos_x, size_t pos_y)
{
	if (mlx_data->map.map[pos_y][pos_x] == 'E')
		return ('E');
	else if (is_case_loot(mlx_data->loots, pos_x, pos_y))
		return ('C');
	return (-1);
}

void	make_move_r(t_mlx_data *mlx_data)
{
	size_t	pos_x;
	size_t	pos_y;
	char	type;
	
	if (check_move(mlx_data, 'r'))
	{
		pos_x = mlx_data->player->pos_x;
		pos_y = mlx_data->player->pos_y;
		type = check_case(mlx_data, pos_x, pos_y);
		if (type == 'E')
		{
			if (mlx_data->player->loot_collected >= mlx_data->map.total_loots)
				ft_printf("FINNN");
			add_image(mlx_data, "./textures/exit.png", pos_x, pos_y);
		}
		else if (type == 'C')
		{
			remove_loot(mlx_data->loots, pos_x, pos_y);
			mlx_data->player->loot_collected++;
			add_image(mlx_data, "./textures/path.png", pos_x, pos_y);
		}
		else
			add_image(mlx_data, "./textures/path.png", pos_x, pos_y);
		mlx_data->player->pos_x++;
		pos_x = mlx_data->player->pos_x;
		mlx_data->player->nb_move++;
		add_img_player(mlx_data,  "./textures/player/player_r.png", pos_x, pos_y);
	}
}

void	make_move_l(t_mlx_data *mlx_data)
{
	size_t	pos_x;
	size_t	pos_y;
	char	type;
	
	if (check_move(mlx_data, 'l'))
	{
		pos_x = mlx_data->player->pos_x;
		pos_y = mlx_data->player->pos_y;
		type = check_case(mlx_data, pos_x, pos_y);
		if (type == 'E')
		{
			if (mlx_data->player->loot_collected >= mlx_data->map.total_loots)
				ft_printf("FINNN");
			add_image(mlx_data, "./textures/exit.png", pos_x, pos_y);
		}
		else if (type == 'C')
		{
			remove_loot(mlx_data->loots, pos_x, pos_y);
			mlx_data->player->loot_collected++;
			add_image(mlx_data, "./textures/path.png", pos_x, pos_y);
		}
		else
			add_image(mlx_data, "./textures/path.png", pos_x, pos_y);
		mlx_data->player->pos_x--;
		pos_x = mlx_data->player->pos_x;
		mlx_data->player->nb_move++;
		add_img_player(mlx_data,  "./textures/player/player_l.png", pos_x, pos_y);
	}
}

void	make_move_t(t_mlx_data *mlx_data)
{
	size_t	pos_x;
	size_t	pos_y;
	char	type;
	
	if (check_move(mlx_data, 't'))
	{
		pos_x = mlx_data->player->pos_x;
		pos_y = mlx_data->player->pos_y;
		type = check_case(mlx_data, pos_x, pos_y);
		if (type == 'E')
		{
			if (mlx_data->player->loot_collected >= mlx_data->map.total_loots)
				ft_printf("FINNN");
			add_image(mlx_data, "./textures/exit.png", pos_x, pos_y);
		}
		else if (type == 'C')
		{
			remove_loot(mlx_data->loots, pos_x, pos_y);
			mlx_data->player->loot_collected++;
			add_image(mlx_data, "./textures/path.png", pos_x, pos_y);
		}
		else
			add_image(mlx_data, "./textures/path.png", pos_x, pos_y);
		mlx_data->player->pos_y--;
		pos_y = mlx_data->player->pos_y;
		mlx_data->player->nb_move++;
		add_img_player(mlx_data,  "./textures/player/player_t.png", pos_x, pos_y);
	}
}

void	make_move_d(t_mlx_data *mlx_data)
{
	size_t	pos_x;
	size_t	pos_y;
	char	type;
	
	if (check_move(mlx_data, 'd'))
	{
		pos_x = mlx_data->player->pos_x;
		pos_y = mlx_data->player->pos_y;
		type = check_case(mlx_data, pos_x, pos_y);
		if (type == 'E')
		{
			if (mlx_data->player->loot_collected >= mlx_data->map.total_loots)
				ft_printf("FINNN");
			add_image(mlx_data, "./textures/exit.png", pos_x, pos_y);
		}
		else if (type == 'C')
		{
			remove_loot(mlx_data->loots, pos_x, pos_y);
			mlx_data->player->loot_collected++;
			add_image(mlx_data, "./textures/path.png", pos_x, pos_y);
		}
		else
			add_image(mlx_data, "./textures/path.png", pos_x, pos_y);
		mlx_data->player->pos_y++;
		pos_y = mlx_data->player->pos_y;
		mlx_data->player->nb_move++;
		add_img_player(mlx_data,  "./textures/player/player_d.png", pos_x, pos_y);
	}
}

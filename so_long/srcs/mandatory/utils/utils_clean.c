/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:57:44 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/15 09:43:54 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	destroy_images(t_mlx_dt *mlx_data)
{
	if (mlx_data->img_ref.exit)
		mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.exit);
	if (mlx_data->img_ref.loot)
		mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.loot);
	if (mlx_data->img_ref.path)
		mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.path);
	if (mlx_data->img_ref.wall)
		mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.wall);
	if (mlx_data->img_ref.pl_d)
		mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.pl_d);
	if (mlx_data->img_ref.pl_l)
		mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.pl_l);
	if (mlx_data->img_ref.pl_r)
		mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.pl_r);
	if (mlx_data->img_ref.pl_t)
		mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.pl_t);
}

void	clean_all(t_mlx_dt *mlx_data)
{
	destroy_images(mlx_data);
	if (mlx_data->player)
		free(mlx_data->player);
	if (mlx_data->map_dt.map)
		free_arr(mlx_data->map_dt.map);
	if (mlx_data->win)
		mlx_destroy_window(mlx_data->mlx, mlx_data->win);
	mlx_destroy_display(mlx_data->mlx);
	if (mlx_data->mlx)
		free(mlx_data->mlx);
}

void	close_game(t_mlx_dt *mlx_data)
{
	mlx_do_key_autorepeaton(mlx_data->mlx);
	clean_all(mlx_data);
	exit(0);
}

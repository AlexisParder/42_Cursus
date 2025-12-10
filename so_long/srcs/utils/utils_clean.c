/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:57:44 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/10 10:44:47 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	destroy_images(t_mlx_dt *mlx_data)
{
	mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.exit);
	mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.loot);
	mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.path);
	mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.wall);
	mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.pl_d);
	mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.pl_l);
	mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.pl_r);
	mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.pl_t);
}

void	clean_all(t_mlx_dt mlx_data)
{
	mlx_destroy_window(mlx_data.mlx, mlx_data.win);
	destroy_images(&mlx_data);
	free(mlx_data.player);
	free(mlx_data.map.map);
	mlx_destroy_context(mlx_data.mlx);
}

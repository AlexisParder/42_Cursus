/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_clean_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:57:44 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/27 09:33:02 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

static void	destroy_images_bonus(t_mlx_dt *mlx_data)
{
	if (mlx_data->img_ref.en1_d)
		mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.en1_d);
	if (mlx_data->img_ref.en1_l)
		mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.en1_l);
	if (mlx_data->img_ref.en1_r)
		mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.en1_r);
	if (mlx_data->img_ref.en1_t)
		mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.en1_t);
	if (mlx_data->img_ref.en2_d)
		mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.en2_d);
	if (mlx_data->img_ref.en2_l)
		mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.en2_l);
	if (mlx_data->img_ref.en2_r)
		mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.en2_r);
	if (mlx_data->img_ref.en2_t)
		mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.en2_t);
	if (mlx_data->img_ref.win)
		mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.win);
	if (mlx_data->img_ref.lose)
		mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.lose);
	if (mlx_data->img_ref.cnt)
		mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.cnt);
	if (mlx_data->img_ref.cnt2)
		mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.cnt2);
}

static void	destroy_images(t_mlx_dt *mlx_data)
{
	if (mlx_data->img_ref.exit_c)
		mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.exit_c);
	if (mlx_data->img_ref.exit_o)
		mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.exit_o);
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
	destroy_images_bonus(mlx_data);
}

static void	clean_all(t_mlx_dt *mlx_data)
{
	destroy_images(mlx_data);
	if (mlx_data->player)
		free(mlx_data->player);
	if (mlx_data->enemy)
		free_lst(&mlx_data->enemy);
	if (mlx_data->map_dt.map)
		free_arr(mlx_data->map_dt.map);
	if (mlx_data->win)
		mlx_destroy_window(mlx_data->mlx, mlx_data->win);
	mlx_destroy_display(mlx_data->mlx);
	if (mlx_data->mlx)
		free(mlx_data->mlx);
}

void	close_game(t_mlx_dt *mlx_data, int status)
{
	mlx_do_key_autorepeaton(mlx_data->mlx);
	clean_all(mlx_data);
	exit(status);
}

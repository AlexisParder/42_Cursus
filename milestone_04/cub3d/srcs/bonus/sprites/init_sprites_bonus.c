/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 09:10:34 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/05 16:03:37 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static void	create_battery_sprites(t_data *dt)
{
	dt->imgs.b_0.tex = mlx_new_image_from_file(dt->mlx, TEX_B_0,
			&dt->imgs.b_0.w, &dt->imgs.b_0.h);
	dt->imgs.b_1.tex = mlx_new_image_from_file(dt->mlx, TEX_B_1,
			&dt->imgs.b_1.w, &dt->imgs.b_1.h);
	dt->imgs.b_2.tex = mlx_new_image_from_file(dt->mlx, TEX_B_2,
			&dt->imgs.b_2.w, &dt->imgs.b_2.h);
	dt->imgs.b_3.tex = mlx_new_image_from_file(dt->mlx, TEX_B_3,
			&dt->imgs.b_3.w, &dt->imgs.b_3.h);
	dt->imgs.b_4.tex = mlx_new_image_from_file(dt->mlx, TEX_B_4,
			&dt->imgs.b_4.w, &dt->imgs.b_4.h);
	dt->imgs.b_5.tex = mlx_new_image_from_file(dt->mlx, TEX_B_5,
			&dt->imgs.b_5.w, &dt->imgs.b_5.h);
	check_transparency(dt, &dt->imgs.b_0);
	check_transparency(dt, &dt->imgs.b_1);
	check_transparency(dt, &dt->imgs.b_2);
	check_transparency(dt, &dt->imgs.b_3);
	check_transparency(dt, &dt->imgs.b_4);
	check_transparency(dt, &dt->imgs.b_5);
}

static void	create_sprites(t_data *dt)
{
	dt->imgs.fl_on.tex = mlx_new_image_from_file(dt->mlx, TEX_FL_ON,
			&dt->imgs.fl_on.w, &dt->imgs.fl_on.h);
	dt->imgs.fl_off.tex = mlx_new_image_from_file(dt->mlx, TEX_FL_OFF,
			&dt->imgs.fl_off.w, &dt->imgs.fl_off.h);
	dt->imgs.rec_on.tex = mlx_new_image_from_file(dt->mlx, TEX_REC_ON,
			&dt->imgs.rec_on.w, &dt->imgs.rec_on.h);
	dt->imgs.rec_off.tex = mlx_new_image_from_file(dt->mlx, TEX_REC_OFF,
			&dt->imgs.rec_off.w, &dt->imgs.rec_off.h);
	check_transparency(dt, &dt->imgs.fl_on);
	check_transparency(dt, &dt->imgs.fl_off);
	check_transparency(dt, &dt->imgs.rec_on);
	check_transparency(dt, &dt->imgs.rec_off);
	create_battery_sprites(dt);
	cache_sprites(dt);
}

static void	check_all_sprites_created(t_data *dt)
{
	if (dt->imgs.fl_on.tex == MLX_NULL_HANDLE
		|| dt->imgs.fl_off.tex == MLX_NULL_HANDLE
		|| dt->imgs.rec_on.tex == MLX_NULL_HANDLE
		|| dt->imgs.rec_off.tex == MLX_NULL_HANDLE
		|| dt->imgs.b_0.tex == MLX_NULL_HANDLE
		|| dt->imgs.b_1.tex == MLX_NULL_HANDLE
		|| dt->imgs.b_2.tex == MLX_NULL_HANDLE
		|| dt->imgs.b_3.tex == MLX_NULL_HANDLE
		|| dt->imgs.b_4.tex == MLX_NULL_HANDLE
		|| dt->imgs.b_5.tex == MLX_NULL_HANDLE
	)
		close_game(dt, EXIT_FAILURE);
}

void	init_sprites(t_data *dt)
{
	if (!file_exists(TEX_FL_ON, 1) || !file_exists(TEX_FL_OFF, 1)
		|| !file_exists(TEX_REC_ON, 1) || !file_exists(TEX_REC_OFF, 1)
		|| !file_exists(TEX_B_0, 1) || !file_exists(TEX_B_1, 1)
		|| !file_exists(TEX_B_2, 1) || !file_exists(TEX_B_3, 1)
		|| !file_exists(TEX_B_4, 1) || !file_exists(TEX_B_5, 1))
		close_game(dt, EXIT_FAILURE);
	create_sprites(dt);
	if (dt->imgs.fl_on.tex == MLX_NULL_HANDLE
		|| dt->imgs.fl_off.tex == MLX_NULL_HANDLE)
		ft_dprintf(2, "Error\nFailure dring creation of flashlight image.\n");
	if (dt->imgs.rec_off.tex == MLX_NULL_HANDLE
		|| dt->imgs.rec_on.tex == MLX_NULL_HANDLE)
		ft_dprintf(2, "Error\nFailure dring creation of rec image.\n");
	if (dt->imgs.b_0.tex == MLX_NULL_HANDLE
		|| dt->imgs.b_1.tex == MLX_NULL_HANDLE
		|| dt->imgs.b_2.tex == MLX_NULL_HANDLE
		|| dt->imgs.b_3.tex == MLX_NULL_HANDLE
		|| dt->imgs.b_4.tex == MLX_NULL_HANDLE
		|| dt->imgs.b_5.tex == MLX_NULL_HANDLE)
		ft_dprintf(2, "Error\nFailure dring creation of battery image.\n");
	check_all_sprites_created(dt);
}

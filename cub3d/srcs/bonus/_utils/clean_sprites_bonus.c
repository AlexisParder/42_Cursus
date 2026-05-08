/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_sprites_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 15:58:32 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/05 15:59:18 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static void	free_sprites_pixel(t_data *data)
{
	if (data->imgs.fl_on.pixels)
		free(data->imgs.fl_on.pixels);
	if (data->imgs.fl_off.pixels)
		free(data->imgs.fl_off.pixels);
	if (data->imgs.rec_off.pixels)
		free(data->imgs.rec_off.pixels);
	if (data->imgs.rec_on.pixels)
		free(data->imgs.rec_on.pixels);
	if (data->imgs.b_0.pixels)
		free(data->imgs.b_0.pixels);
	if (data->imgs.b_1.pixels)
		free(data->imgs.b_1.pixels);
	if (data->imgs.b_2.pixels)
		free(data->imgs.b_2.pixels);
	if (data->imgs.b_3.pixels)
		free(data->imgs.b_3.pixels);
	if (data->imgs.b_4.pixels)
		free(data->imgs.b_4.pixels);
	if (data->imgs.b_5.pixels)
		free(data->imgs.b_5.pixels);
}

void	destroy_sprites(t_data *data)
{
	if (!data->mlx)
		return ;
	if (data->imgs.fl_on.tex)
		mlx_destroy_image(data->mlx, data->imgs.fl_on.tex);
	if (data->imgs.fl_off.tex)
		mlx_destroy_image(data->mlx, data->imgs.fl_off.tex);
	if (data->imgs.rec_off.tex)
		mlx_destroy_image(data->mlx, data->imgs.rec_off.tex);
	if (data->imgs.rec_on.tex)
		mlx_destroy_image(data->mlx, data->imgs.rec_on.tex);
	if (data->imgs.b_0.tex)
		mlx_destroy_image(data->mlx, data->imgs.b_0.tex);
	if (data->imgs.b_1.tex)
		mlx_destroy_image(data->mlx, data->imgs.b_1.tex);
	if (data->imgs.b_2.tex)
		mlx_destroy_image(data->mlx, data->imgs.b_2.tex);
	if (data->imgs.b_3.tex)
		mlx_destroy_image(data->mlx, data->imgs.b_3.tex);
	if (data->imgs.b_4.tex)
		mlx_destroy_image(data->mlx, data->imgs.b_4.tex);
	if (data->imgs.b_5.tex)
		mlx_destroy_image(data->mlx, data->imgs.b_5.tex);
	free_sprites_pixel(data);
}

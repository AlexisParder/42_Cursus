/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 12:24:33 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/06 09:57:52 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static void	free_imgs_pixel(t_data *data)
{
	if (data->imgs.wall_n.pixels)
		free(data->imgs.wall_n.pixels);
	if (data->imgs.wall_s.pixels)
		free(data->imgs.wall_s.pixels);
	if (data->imgs.wall_e.pixels)
		free(data->imgs.wall_e.pixels);
	if (data->imgs.wall_w.pixels)
		free(data->imgs.wall_w.pixels);
	if (data->imgs.door_c.pixels)
		free(data->imgs.door_c.pixels);
	if (data->imgs.door_o.pixels)
		free(data->imgs.door_o.pixels);
}

static void	destroy_images(t_data *data)
{
	if (!data->mlx)
		return ;
	if (data->imgs.wall_n.tex)
		mlx_destroy_image(data->mlx, data->imgs.wall_n.tex);
	if (data->imgs.wall_s.tex)
		mlx_destroy_image(data->mlx, data->imgs.wall_s.tex);
	if (data->imgs.wall_e.tex)
		mlx_destroy_image(data->mlx, data->imgs.wall_e.tex);
	if (data->imgs.wall_w.tex)
		mlx_destroy_image(data->mlx, data->imgs.wall_w.tex);
	if (data->imgs.door_c.tex)
		mlx_destroy_image(data->mlx, data->imgs.door_c.tex);
	if (data->imgs.door_o.tex)
		mlx_destroy_image(data->mlx, data->imgs.door_o.tex);
	if (data->global_img)
		mlx_destroy_image(data->mlx, data->global_img);
	free_imgs_pixel(data);
}

static void	free_tex(t_data *data)
{
	if (data->tex_n)
		free(data->tex_n);
	if (data->tex_s)
		free(data->tex_s);
	if (data->tex_e)
		free(data->tex_e);
	if (data->tex_w)
		free(data->tex_w);
	if (data->tex_dc)
		free(data->tex_dc);
	if (data->tex_do)
		free(data->tex_do);
}

static void	clean_all(t_data *data)
{
	if (data->mlx)
		mlx_loop_end(data->mlx);
	destroy_images(data);
	destroy_sprites(data);
	if (data->mlx && data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_context(data->mlx);
	free_tex(data);
	if (data->framebuffer)
		free(data->framebuffer);
	if (data->coll_map)
		free(data->coll_map);
	if (data->buttons)
		free(data->buttons);
	ft_free_arr(data->map);
}

void	close_game(t_data *data, int status)
{
	clean_all(data);
	exit(status);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 12:24:33 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/21 09:30:11 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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
}

static void	clean_all(t_data *data)
{
	if (data->mlx)
		mlx_loop_end(data->mlx);
	destroy_images(data);
	if (data->mlx && data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_context(data->mlx);
	if (data->tex_n)
		free(data->tex_n);
	if (data->tex_s)
		free(data->tex_s);
	if (data->tex_e)
		free(data->tex_e);
	if (data->tex_w)
		free(data->tex_w);
	if (data->framebuffer)
		free(data->framebuffer);
	ft_free_arr(data->map);
}

void	close_game(t_data *data, int status)
{
	clean_all(data);
	exit(status);
}

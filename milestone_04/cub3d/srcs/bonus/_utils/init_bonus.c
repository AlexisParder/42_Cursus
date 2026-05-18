/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 09:30:35 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/08 11:16:32 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	init_window(t_data *data)
{
	mlx_window_create_info	window_info;

	ft_memset(&window_info, 0, sizeof(mlx_window_create_info));
	window_info.title = "UNDEFINED cub3d - Bonus";
	window_info.width = data->win_w;
	window_info.height = data->win_h;
	data->framebuffer = ft_calloc(data->win_w * data->win_h, sizeof(mlx_color));
	if (!data->framebuffer)
	{
		ft_dprintf(2, "Error\nFailure during allocation\n");
		close_game(data, EXIT_FAILURE);
	}
	data->win = mlx_new_window(data->mlx, &window_info);
	if (!data->win)
	{
		ft_dprintf(2, "Error\nFailure during window creation\n");
		close_game(data, EXIT_FAILURE);
	}
	data->redraw = 1;
	ft_memset(data->keys, 0, sizeof(data->keys));
	ft_memset(data->old_keys, 0, sizeof(data->old_keys));
	mlx_mouse_hide(data->mlx);
}

static void	init_bzero(t_data *data)
{
	ft_bzero(&data->imgs.wall_n, sizeof(t_img_dt));
	ft_bzero(&data->imgs.wall_s, sizeof(t_img_dt));
	ft_bzero(&data->imgs.wall_e, sizeof(t_img_dt));
	ft_bzero(&data->imgs.wall_w, sizeof(t_img_dt));
	ft_bzero(&data->imgs.door_c, sizeof(t_img_dt));
	ft_bzero(&data->imgs.door_o, sizeof(t_img_dt));
	ft_bzero(&data->imgs.fl_on, sizeof(t_img_dt));
	ft_bzero(&data->imgs.fl_off, sizeof(t_img_dt));
	ft_bzero(&data->imgs.rec_off, sizeof(t_img_dt));
	ft_bzero(&data->imgs.rec_on, sizeof(t_img_dt));
	ft_bzero(&data->imgs.b_0, sizeof(t_img_dt));
	ft_bzero(&data->imgs.b_1, sizeof(t_img_dt));
	ft_bzero(&data->imgs.b_2, sizeof(t_img_dt));
	ft_bzero(&data->imgs.b_3, sizeof(t_img_dt));
	ft_bzero(&data->imgs.b_4, sizeof(t_img_dt));
	ft_bzero(&data->imgs.b_5, sizeof(t_img_dt));
	ft_bzero(&data->imgs, sizeof(t_imgs_ref));
	ft_bzero(&data->tile_front, sizeof(t_tile));
}

void	init_data(t_data *data)
{
	init_bzero(data);
	data->tex_n = NULL;
	data->tex_s = NULL;
	data->tex_e = NULL;
	data->tex_w = NULL;
	data->tex_dc = NULL;
	data->tex_do = NULL;
	data->pause = 0;
	data->map = NULL;
	data->win_w = WINDOW_WIDTH;
	data->win_h = WINDOW_HEIGHT;
	data->win = NULL;
	data->mlx = NULL;
	data->has_door = 0;
	data->interact_door = 0;
	data->draw_fps = 0;
	data->framebuffer = NULL;
	data->coll_map = NULL;
	data->flashlight = 0;
	data->cl_interact.rgba = 0xFFFFFFFF;
	data->battery = 100.0f;
	data->buttons = NULL;
	data->change_key = -1;
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_dprintf(2, "Error\nFailure during mlx creation\n");
		close_game(data, EXIT_FAILURE);
	}
}

void	init_color(t_data *data)
{
	data->colors.bg.r = 60;
	data->colors.bg.g = 60;
	data->colors.bg.b = 60;
	data->colors.bg.a = 0xFF;
	data->colors.key_bg.r = 100;
	data->colors.key_bg.g = 100;
	data->colors.key_bg.b = 100;
	data->colors.key_bg.a = 0xFF;
	data->colors.white.rgba = 0xFFFFFFFF;
	data->colors.fill.r = 80;
	data->colors.fill.g = 140;
	data->colors.fill.b = 200;
	data->colors.fill.a = 200;
}

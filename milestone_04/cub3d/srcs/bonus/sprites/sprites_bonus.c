/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 09:10:50 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/08 11:32:58 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static void	blit_sprite_to_framebuffer(t_data *dt,
	t_img_dt sprite, int x_off, int y_off)
{
	int			x;
	int			y;
	t_vec2		fb;
	mlx_color	color;

	y = 0;
	while (y < sprite.h)
	{
		x = 0;
		while (x < sprite.w)
		{
			color = mlx_get_image_pixel(dt->mlx, sprite.tex, x, y);
			if (color.a > 0)
			{
				fb.x = x_off + x;
				fb.y = y_off + y;
				if (fb.x >= 0 && fb.x < (int)dt->win_w
					&& fb.y >= 0 && fb.y < (int)dt->win_h)
					dt->framebuffer[(int)fb.y
						* dt->win_w + (int)fb.x] = apply_brightness(dt, color);
			}
			x++;
		}
		y++;
	}
}

static void	draw_moved_arms(t_data *data)
{
	t_img_dt	img;

	img = data->imgs.fl_on;
	if (!data->flashlight)
		img = data->imgs.fl_off;
	blit_sprite_to_framebuffer(data, img, 0, 0);
	mlx_set_image_region(data->mlx, data->global_img, 0, 0,
		data->win_w, data->win_h, data->framebuffer);
}

static void	draw_rec(t_data *data)
{
	long			current_time;
	static t_img_dt	img;
	static int		state = 0;
	static long		last_time = 0;

	current_time = get_time_ms();
	if (current_time - last_time >= SPRITE_DELAY)
	{
		if (state)
		{
			img = data->imgs.rec_on;
			state = 0;
		}
		else
		{
			img = data->imgs.rec_off;
			state = 1;
		}
		last_time = current_time;
	}
	blit_sprite_to_framebuffer(data, img, 10, 10);
	mlx_set_image_region(data->mlx, data->global_img, 0, 0,
		data->win_w, data->win_h, data->framebuffer);
}

static void	draw_battery(t_data *data)
{
	long			current_time;
	static t_img_dt	img;
	static long		last_time = 0;

	current_time = get_time_ms();
	if (current_time - last_time >= 250)
	{
		if (data->battery > 80.0f && data->battery <= 100.0f)
			img = data->imgs.b_5;
		else if (data->battery > 60.0f && data->battery <= 80.0f)
			img = data->imgs.b_4;
		else if (data->battery > 40.0f && data->battery <= 60.0f)
			img = data->imgs.b_3;
		else if (data->battery > 20.0f && data->battery <= 40.0f)
			img = data->imgs.b_2;
		else if (data->battery > 0.0f && data->battery <= 20.0f)
			img = data->imgs.b_1;
		else if (data->battery <= 0.0f)
			img = data->imgs.b_0;
		last_time = current_time;
	}
	blit_sprite_to_framebuffer(data, img, data->win_w - img.w - 10, 10);
	mlx_set_image_region(data->mlx, data->global_img, 0, 0,
		data->win_w, data->win_h, data->framebuffer);
}

void	manage_sprites(t_data *data)
{
	if (data->pause)
		return ;
	draw_moved_arms(data);
	draw_rec(data);
	draw_battery(data);
}

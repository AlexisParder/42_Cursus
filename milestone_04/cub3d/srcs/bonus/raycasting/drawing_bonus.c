/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 09:00:27 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/04 15:33:58 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static void	draw_ceilling_floor(t_data *data, t_draw *draw, size_t x)
{
	long		y;
	mlx_color	color;

	y = 0;
	while (y < draw->start)
	{
		color = apply_brightness(data, data->cl_ceiling);
		data->framebuffer[x + data->win_w * y] = color;
		y++;
	}
	y = draw->end;
	while (y < (long)data->win_h)
	{
		color = apply_brightness(data, data->cl_floor);
		data->framebuffer[x + data->win_w * y] = color;
		y++;
	}
}

static t_draw_w	init_draw_wall_struct(t_data *data, t_draw *draw, t_ray *ray)
{
	t_draw_w	draw_struct;

	draw_struct.img = get_img(data, ray);
	draw_struct.tex_x = get_tex_x(data, ray, draw_struct.img, draw);
	draw_struct.step = (double)draw_struct.img.h / draw->line_h;
	return (draw_struct);
}

static double	calc_tex_pos(t_data *data, t_draw *draw, t_draw_w *d_w)
{
	long	real_start;
	double	tex_pos;

	real_start = -draw->line_h / 2 + (long)(data->win_h / 2)
		+ (long)data->player.pitch
		+ (long)((data->player.z + data->player.bob_offset)
			/ draw->perp_wall_dist);
	tex_pos = (double)(draw->start - real_start) * d_w->step;
	return (tex_pos);
}

void	draw_column_behind(t_data *data, t_draw *draw, t_ray *ray, size_t x)
{
	int			tex_y;
	double		tex_pos;
	mlx_color	color;
	long		y;
	t_draw_w	d_w;

	draw_ceilling_floor(data, draw, x);
	d_w = init_draw_wall_struct(data, draw, ray);
	tex_pos = calc_tex_pos(data, draw, &d_w);
	y = draw->start;
	while (y < draw->end)
	{
		tex_y = (int)tex_pos % d_w.img.h;
		if (tex_y < 0)
			tex_y += d_w.img.h;
		tex_pos += d_w.step;
		color = get_pixel(d_w.img, d_w.tex_x, tex_y);
		color = apply_fog(data, color, draw->perp_wall_dist);
		data->framebuffer[x + data->win_w * y] = color;
		y++;
	}
}

void	draw_column(t_data *data, t_draw *draw, t_ray *ray, size_t x)
{
	int			tex_y;
	double		tex_pos;
	mlx_color	color;
	long		y;
	t_draw_w	d_w;

	d_w = init_draw_wall_struct(data, draw, ray);
	tex_pos = calc_tex_pos(data, draw, &d_w);
	y = draw->start;
	while (y < draw->end)
	{
		tex_y = (int)tex_pos % d_w.img.h;
		if (tex_y < 0)
			tex_y += d_w.img.h;
		tex_pos += d_w.step;
		color = get_pixel(d_w.img, d_w.tex_x, tex_y);
		if (color.a != 0)
		{
			color = apply_fog(data, color, draw->perp_wall_dist);
			data->framebuffer[x + data->win_w * y] = color;
		}
		y++;
	}
}

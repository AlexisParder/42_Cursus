/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 09:00:27 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/21 09:09:41 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	draw_ceilling_floor(t_data *data, t_draw *draw, size_t x)
{
	long		y;

	y = 0;
	while (y < draw->start)
	{
		data->framebuffer[x + data->win_w * y] = data->cl_ceiling;
		y++;
	}
	y = draw->start;
	while (y < draw->end)
		y++;
	while (y < (long)data->win_h)
	{
		data->framebuffer[x + data->win_w * y] = data->cl_floor;
		y++;
	}
}

static int	get_tex_x(t_data *data, t_ray *ray, t_img_dt img, t_draw *draw)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == 0)
		wall_x = data->player.pos.y + draw->perp_wall_dist * ray->dir.y;
	else
		wall_x = data->player.pos.x + draw->perp_wall_dist * ray->dir.x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * img.w);
	if (ray->side == 0 && ray->step_x > 0)
		tex_x = img.w - tex_x - 1;
	if (ray->side == 1 && ray->step_y < 0)
		tex_x = img.w - tex_x - 1;
	return (tex_x);
}

static t_draw_w	init_draw_wall_struct(t_data *data, t_draw *draw, t_ray *ray)
{
	t_draw_w	draw_struct;

	draw_struct.img = get_img(data, ray);
	draw_struct.tex_x = get_tex_x(data, ray, draw_struct.img, draw);
	draw_struct.step = (double)draw_struct.img.h / draw->line_h;
	return (draw_struct);
}

void	draw_column(t_data *data, t_draw *draw, t_ray *ray, size_t x)
{
	int			tex_y;
	double		tex_pos;
	mlx_color	color;
	long		y;
	t_draw_w	d_w;

	draw_ceilling_floor(data, draw, x);
	d_w = init_draw_wall_struct(data, draw, ray);
	tex_pos = (draw->start - data->win_h / 2.0 + draw->line_h / 2.0) * d_w.step;
	y = draw->start;
	while (y < draw->end)
	{
		tex_y = (int)tex_pos % d_w.img.h;
		tex_pos += d_w.step;
		color = mlx_get_image_pixel(data->mlx, d_w.img.tex, d_w.tex_x, tex_y);
		data->framebuffer[x + data->win_w * y] = color;
		y++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:16:30 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/21 09:02:35 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static t_draw	calc_draw(t_ray *ray, int win_h)
{
	t_draw	draw;

	if (!ray->side)
		draw.perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		draw.perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
	draw.line_h = (int)(win_h / draw.perp_wall_dist);
	draw.start = -draw.line_h / 2 + win_h / 2;
	if (draw.start < 0)
		draw.start = 0;
	draw.end = draw.line_h / 2 + win_h / 2;
	if (draw.end >= win_h)
		draw.end = win_h - 1;
	return (draw);
}

static t_ray	init_ray(t_data *data, size_t x)
{
	t_ray	ray;
	double	camera_x;

	camera_x = 2.0 * x / data->win_w - 1.0;
	ray.dir.x = data->player.dir.x + data->player.plane.x * camera_x;
	ray.dir.y = data->player.dir.y + data->player.plane.y * camera_x;
	ray.delta_dist_x = calc_delta(ray.dir.x);
	ray.delta_dist_y = calc_delta(ray.dir.y);
	ray.map_x = (int)data->player.pos.x;
	ray.map_y = (int)data->player.pos.y;
	ray.hit = 0;
	return (ray);
}

void	raycasting(t_data *data)
{
	t_ray	ray;
	t_draw	draw;
	size_t	x;

	data->redraw = 0;
	mlx_clear_window(data->mlx, data->win, (mlx_color){.rgba = 0x00000000});
	x = 0;
	while (x < data->win_w)
	{
		ray = init_ray(data, x);
		calc_step_side(&ray, &data->player);
		dda(&ray, data->map);
		draw = calc_draw(&ray, data->win_h);
		draw_column(data, &draw, &ray, x);
		x++;
	}
	mlx_pixel_put_region(data->mlx, data->win, 0, 0,
		data->win_w, data->win_h, data->framebuffer);
}

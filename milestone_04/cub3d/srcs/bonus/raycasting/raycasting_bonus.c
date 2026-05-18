/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:16:30 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/04 15:34:13 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static t_draw	calc_draw(t_ray *ray, t_data *data)
{
	t_draw	draw;
	int		pitch;
	int		z_off;

	pitch = (int)data->player.pitch;
	if (!ray->side)
		draw.perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		draw.perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
	z_off = (int)((data->player.z + data->player.bob_offset)
			/ draw.perp_wall_dist);
	draw.line_h = (int)(data->win_h / draw.perp_wall_dist);
	draw.start = -draw.line_h / 2 + data->win_h / 2 + pitch + z_off;
	if (draw.start < 0)
		draw.start = 0;
	draw.end = draw.line_h / 2 + data->win_h / 2 + pitch + z_off;
	if (draw.end >= (int)data->win_h)
		draw.end = data->win_h - 1;
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
	ray.hit_tile = 0;
	return (ray);
}

static void	handle_transparent(t_data *data, t_ray *ray, t_draw *draw, size_t x)
{
	t_ray	ray2;
	t_draw	draw2;
	t_ray	ray3;
	t_draw	draw3;

	ray2 = *ray;
	dda(&ray2, data->map, 1);
	draw2 = calc_draw(&ray2, data);
	if (ray2.hit_tile == 'O')
	{
		ray3 = ray2;
		dda(&ray3, data->map, 1);
		draw3 = calc_draw(&ray3, data);
		draw_column_behind(data, &draw3, &ray3, x);
		draw_column(data, &draw2, &ray2, x);
	}
	else
		draw_column_behind(data, &draw2, &ray2, x);
	draw_column(data, draw, ray, x);
}

static void	get_tile_in_front(t_data *data)
{
	data->tile_front.x = (int)(data->player.pos.x + data->player.dir.x);
	data->tile_front.y = (int)(data->player.pos.y + data->player.dir.y);
	data->tile_front.type = data->map[data->tile_front.y][data->tile_front.x];
}

void	raycasting(t_data *data)
{
	t_ray	ray;
	t_draw	draw;
	size_t	x;

	data->redraw = 0;
	mlx_clear_window(data->mlx, data->win, (mlx_color){.rgba = 0x000000FF});
	x = 0;
	while (x < data->win_w)
	{
		ray = init_ray(data, x);
		calc_step_side(&ray, &data->player);
		dda(&ray, data->map, 0);
		draw = calc_draw(&ray, data);
		if (ray.hit_tile == 'O')
			handle_transparent(data, &ray, &draw, x);
		else
			draw_column_behind(data, &draw, &ray, x);
		x++;
	}
	if (data->pause)
		draw_settings(data);
	mlx_set_image_region(data->mlx, data->global_img, 0, 0,
		data->win_w, data->win_h, data->framebuffer);
	get_tile_in_front(data);
}

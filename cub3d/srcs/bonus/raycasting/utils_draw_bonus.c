/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 10:35:18 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/30 15:45:11 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

mlx_color	apply_fog(t_data *data, mlx_color color, double dist)
{
	double	factor;

	if (dist > FOG_DIST)
		factor = 0.07;
	else
		factor = 1.0 - (dist / FOG_DIST);
	if (factor <= 0.1)
		factor = 0.07;
	factor *= (data->settings.brightness / 100.0);
	color.r = (uint8_t)(color.r * factor);
	color.g = (uint8_t)(color.g * factor);
	color.b = (uint8_t)(color.b * factor);
	return (color);
}

mlx_color	apply_brightness(t_data *data, mlx_color color)
{
	double	factor;

	factor = 1;
	factor *= (data->settings.brightness / 100.0);
	color.r = (uint8_t)(color.r * factor);
	color.g = (uint8_t)(color.g * factor);
	color.b = (uint8_t)(color.b * factor);
	return (color);
}

mlx_color	get_pixel(t_img_dt img, int x, int y)
{
	return ((mlx_color){.rgba = img.pixels[y * img.w + x]});
}

int	get_tex_x(t_data *data, t_ray *ray, t_img_dt img, t_draw *draw)
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

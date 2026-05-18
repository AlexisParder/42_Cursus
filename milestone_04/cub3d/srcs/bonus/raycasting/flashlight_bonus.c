/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flashlight_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 13:00:03 by tjourdai          #+#    #+#             */
/*   Updated: 2026/05/06 09:09:51 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static mlx_color	set_brighten_pixel(mlx_color color, double factor)
{
	int	r;
	int	g;
	int	b;

	r = (int)(color.r * factor);
	g = (int)(color.g * factor);
	b = (int)(color.b * factor);
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	color.r = (uint8_t)r;
	color.g = (uint8_t)g;
	color.b = (uint8_t)b;
	return (color);
}

static void	set_brighten_radius(t_data *data, size_t y,
	t_vec2 pos, double radius)
{
	double		dist;
	double		factor;
	mlx_color	color;
	size_t		x;

	x = 0;
	while (x < data->win_w)
	{
		dist = vec2_dist((t_vec2){x, y}, pos);
		if (dist < radius)
		{
			factor = 1.0 + 2.5 * (1.0 - dist / radius);
			color.rgba = data->framebuffer[x + data->win_w * y].rgba;
			data->framebuffer[x + data->win_w * y]
				= set_brighten_pixel(color, factor);
		}
		x++;
	}
}

void	apply_flashlight(t_data *data)
{
	size_t		y;
	t_vec2		pos;
	double		radius;

	if (!data->flashlight || data->battery <= 0.0f)
		return ;
	pos.x = data->win_w / 2.0;
	pos.y = data->win_h / 2.0;
	radius = data->win_h * 0.45;
	y = 0;
	while (y < data->win_h)
	{
		set_brighten_radius(data, y, pos, radius);
		y++;
	}
	data->battery -= 0.1f;
}

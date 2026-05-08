/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 13:57:49 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/29 13:24:53 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

double	calc_delta(double ray_dir)
{
	if (ray_dir == 0)
		return (INFINITY);
	return (fabs(1.0 / ray_dir));
}

void	calc_step_side(t_ray *ray, t_player *pl)
{
	if (ray->dir.x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (pl->pos.x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - pl->pos.x) * ray->delta_dist_x;
	}
	if (ray->dir.y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (pl->pos.y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - pl->pos.y) * ray->delta_dist_y;
	}
}

void	dda(t_ray *ray, char **map, int dda_continue)
{
	char	tile;

	if (dda_continue)
		ray->hit = 0;
	while (!ray->hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		tile = map[ray->map_y][ray->map_x];
		if (tile == '1' || tile == 'D' || tile == 'O')
		{
			ray->hit = 1;
			ray->hit_tile = tile;
		}
	}
}

t_img_dt	get_img(t_data *data, t_ray *ray)
{
	if (ray->hit_tile == 'D')
		return (data->imgs.door_c);
	if (ray->hit_tile == 'O')
		return (data->imgs.door_o);
	if (ray->side == 0)
	{
		if (ray->step_x > 0)
			return (data->imgs.wall_w);
		return (data->imgs.wall_e);
	}
	else
	{
		if (ray->step_y > 0)
			return (data->imgs.wall_n);
		return (data->imgs.wall_s);
	}
}

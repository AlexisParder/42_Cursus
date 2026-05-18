/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 13:52:56 by tjourdai          #+#    #+#             */
/*   Updated: 2026/04/22 14:29:59 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	is_wall(t_data *data, double nx, double ny)
{
	return (data->map[(int)ny][(int)nx] == '1');
}

static void	move_forward_back(t_data *data, int key)
{
	double	nx;
	double	ny;
	double	speed;

	if (key == KEY_W)
		speed = MOVE_SPEED;
	else
		speed = -MOVE_SPEED;
	nx = data->player.pos.x + data->player.dir.x * speed;
	ny = data->player.pos.y + data->player.dir.y * speed;
	if (!is_wall(data, nx, data->player.pos.y))
		data->player.pos.x = nx;
	if (!is_wall(data, data->player.pos.x, ny))
		data->player.pos.y = ny;
	data->redraw = 1;
}

static void	move_strafe(t_data *data, int key)
{
	double	nx;
	double	ny;
	double	speed;

	if (key == KEY_D)
		speed = MOVE_SPEED;
	else
		speed = -MOVE_SPEED;
	nx = data->player.pos.x + data->player.plane.x * speed;
	ny = data->player.pos.y + data->player.plane.y * speed;
	if (!is_wall(data, nx, data->player.pos.y))
		data->player.pos.x = nx;
	if (!is_wall(data, data->player.pos.x, ny))
		data->player.pos.y = ny;
	data->redraw = 1;
}

static void	rotate(t_data *data, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir.x;
	data->player.dir.x = old_dir_x * cos(angle)
		- data->player.dir.y * sin(angle);
	data->player.dir.y = old_dir_x * sin(angle)
		+ data->player.dir.y * cos(angle);
	old_plane_x = data->player.plane.x;
	data->player.plane.x = old_plane_x * cos(angle)
		- data->player.plane.y * sin(angle);
	data->player.plane.y = old_plane_x * sin(angle)
		+ data->player.plane.y * cos(angle);
	data->redraw = 1;
}

void	actions(t_data *data)
{
	if (data->keys[KEY_W])
		move_forward_back(data, KEY_W);
	else if (data->keys[KEY_S])
		move_forward_back(data, KEY_S);
	if (data->keys[KEY_A])
		move_strafe(data, KEY_A);
	else if (data->keys[KEY_D])
		move_strafe(data, KEY_D);
	if (data->keys[KEY_RIGHT])
		rotate(data, ROT_SPEED);
	else if (data->keys[KEY_LEFT])
		rotate(data, -ROT_SPEED);
	ft_memcpy(data->old_keys, data->keys, 512);
}

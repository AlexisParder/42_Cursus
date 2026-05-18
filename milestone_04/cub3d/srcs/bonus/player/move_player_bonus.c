/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 13:52:56 by tjourdai          #+#    #+#             */
/*   Updated: 2026/05/01 14:55:08 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	move_forward_back(t_data *data, int key)
{
	double	nx;
	double	ny;
	double	speed;
	double	sprint;

	sprint = 1;
	if (data->keys[KEY_CTRL])
		sprint /= 2;
	else if (!data->pause && data->keys[KEY_SHIFT])
		sprint = 2;
	if (key == data->settings.key_forward)
		speed = MOVE_SPEED * sprint;
	else
		speed = -MOVE_SPEED * sprint;
	nx = data->player.pos.x + data->player.dir.x * speed;
	ny = data->player.pos.y + data->player.dir.y * speed;
	if (!is_blocked(data, nx, data->player.pos.y))
		data->player.pos.x = nx;
	if (!is_blocked(data, data->player.pos.x, ny))
		data->player.pos.y = ny;
	data->redraw = 1;
}

void	move_strafe(t_data *data, int key)
{
	double	nx;
	double	ny;
	double	speed;
	double	sprint;

	sprint = 1;
	if (data->keys[KEY_CTRL])
		sprint /= 2;
	else if (!data->pause && data->keys[KEY_SHIFT])
		sprint = 2;
	if (key == data->settings.key_right)
		speed = MOVE_SPEED * sprint;
	else
		speed = -MOVE_SPEED * sprint;
	nx = data->player.pos.x + data->player.plane.x * speed;
	ny = data->player.pos.y + data->player.plane.y * speed;
	if (!is_blocked(data, nx, data->player.pos.y))
		data->player.pos.x = nx;
	if (!is_blocked(data, data->player.pos.x, ny))
		data->player.pos.y = ny;
	data->redraw = 1;
}

void	rotate(t_data *data, double angle)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 09:28:30 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/06 13:29:49 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static void	actions_mouse(t_data *data)
{
	int		mouse_x;
	int		mouse_y;
	int		center_x;
	int		center_y;

	if (data->pause)
		return ;
	center_x = WINDOW_WIDTH / 2;
	center_y = WINDOW_HEIGHT / 2;
	mlx_mouse_get_pos(data->mlx, &mouse_x, &mouse_y);
	if (mouse_x != center_x)
		rotate(data,
			(mouse_x - center_x) * data->settings.mouse_sensitivity);
	if (mouse_y != center_y)
	{
		data->player.pitch -= (mouse_y - center_y)
			* data->settings.mouse_sensitivity * 250.0;
		if (data->player.pitch > (WINDOW_HEIGHT / 2 - 10))
			data->player.pitch = (WINDOW_HEIGHT / 2 - 10);
		if (data->player.pitch < -(WINDOW_HEIGHT / 2 - 10))
			data->player.pitch = -(WINDOW_HEIGHT / 2 - 10);
		data->redraw = 1;
	}
	mlx_mouse_move(data->mlx, data->win, center_x, center_y);
}

static void	actions_move_rot(t_data *data)
{
	if (data->pause)
		return ;
	if (data->keys[data->settings.key_forward])
		move_forward_back(data, data->settings.key_forward);
	else if (data->keys[data->settings.key_backward])
		move_forward_back(data, data->settings.key_backward);
	if (data->keys[data->settings.key_left])
		move_strafe(data, data->settings.key_left);
	else if (data->keys[data->settings.key_right])
		move_strafe(data, data->settings.key_right);
	if (data->keys[KEY_RIGHT])
		rotate(data, ROT_SPEED);
	else if (data->keys[KEY_LEFT])
		rotate(data, -ROT_SPEED);
	actions_mouse(data);
}

static void	pause_action(t_data *data)
{
	static int	mouse_x = 0;
	static int	mouse_y = 0;

	if (data->pause)
	{
		mlx_mouse_get_pos(data->mlx, &mouse_x, &mouse_y);
		mlx_mouse_show(data->mlx);
	}
	else
	{
		mlx_mouse_move(data->mlx, data->win, mouse_x, mouse_y);
		mlx_mouse_hide(data->mlx);
	}
	data->change_key = -1;
}

static void	toggle_door(t_data *data)
{
	int	x;
	int	y;

	x = data->tile_front.x;
	y = data->tile_front.y;
	if (data->map[y][x] == 'O')
		data->map[y][x] = 'D';
	else
		data->map[y][x] = 'O';
	update_collision_tile(data, x, y);
	data->redraw = 1;
}

void	actions(t_data *data)
{
	actions_move_rot(data);
	if (!data->pause)
		actions_jump_crouch(data);
	if (data->keys[KEY_TAB] && !data->old_keys[KEY_TAB])
	{
		data->pause = !data->pause;
		pause_action(data);
		data->redraw = 1;
	}
	if (data->keys[KEY_F] && !data->old_keys[KEY_F])
	{
		data->flashlight = !data->flashlight;
		data->redraw = 1;
	}
	if (data->keys[KEY_Q] && !data->old_keys[KEY_Q])
	{
		data->draw_fps = !data->draw_fps;
		data->redraw = 1;
	}
	if (data->keys[KEY_R] && !data->old_keys[KEY_R] && data->battery <= 0.0f)
		data->battery = 100.f;
	if (!data->pause && data->keys[KEY_E]
		&& !data->old_keys[KEY_E] && data->interact_door)
		toggle_door(data);
	ft_memcpy(data->old_keys, data->keys, sizeof(data->keys));
}

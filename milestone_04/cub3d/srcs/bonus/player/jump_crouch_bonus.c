/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_crouch_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 14:00:00 by tjourdai          #+#    #+#             */
/*   Updated: 2026/05/04 15:29:30 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static void	update_jump(t_data *data)
{
	data->player.z += data->player.z_vel;
	if (JUMP_CROUCH_GRAVITY > 0.22)
		data->player.z_vel -= JUMP_CROUCH_GRAVITY;
	if (data->player.z <= 0)
	{
		data->player.z = 0;
		data->player.z_vel = 0;
		data->player.jumping = 0;
	}
	data->redraw = 1;
}

static int	is_player_moving(t_data *data)
{
	return (data->keys[data->settings.key_forward]
		|| data->keys[data->settings.key_backward]
		|| data->keys[data->settings.key_left]
		|| data->keys[data->settings.key_right]);
}

static void	update_bob(t_data *data)
{
	double	speed_factor;

	speed_factor = 1.0;
	if (data->keys[KEY_CTRL])
		speed_factor = 0.5;
	else if (!data->pause && data->keys[KEY_SHIFT])
		speed_factor = 1.5;
	if (is_player_moving(data) && !data->player.jumping)
	{
		data->player.bob_phase += 0.35 * speed_factor;
		if (data->player.bob_phase > 2 * M_PI)
			data->player.bob_phase -= 2 * M_PI;
		data->player.bob_offset = sin(data->player.bob_phase)
			* 8.0 * speed_factor;
	}
	else
	{
		data->player.bob_offset *= 0.85;
		if (fabs(data->player.bob_offset) < 0.1)
		{
			data->player.bob_offset = 0;
			data->player.bob_phase = 0;
		}
	}
	data->redraw = 1;
}

void	actions_jump_crouch(t_data *data)
{
	double	target;

	if (data->keys[KEY_SPACE] && !data->old_keys[KEY_SPACE]
		&& !data->player.jumping && data->player.z == 0)
	{
		data->player.jumping = 1;
		data->player.z_vel = 22.0;
	}
	if (data->player.jumping)
	{
		update_jump(data);
		update_bob(data);
		return ;
	}
	if (data->keys[KEY_CTRL])
		target = -140.0;
	else
		target = 0;
	data->player.z += (target - data->player.z)
		* (JUMP_CROUCH_GRAVITY / 8.18);
	if (target == 0 && data->player.z > -0.5)
		data->player.z = 0;
	update_bob(data);
	data->redraw = 1;
}

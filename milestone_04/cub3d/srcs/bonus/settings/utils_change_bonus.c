/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_change_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:18:51 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/04 16:01:23 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	change_key_bind(t_data *data, int key)
{
	if (data->change_key != -1)
	{
		if (data->change_key == 0)
			data->settings.key_forward = key;
		if (data->change_key == 1)
			data->settings.key_backward = key;
		if (data->change_key == 2)
			data->settings.key_right = key;
		if (data->change_key == 3)
			data->settings.key_left = key;
		save_settings_in_file(data);
		data->buttons[data->change_key].key = (char *)mbx_key_from_id(key);
	}
}

void	change_keys(t_click_args *element)
{
	if (element->data->change_key == element->index)
		element->data->change_key = -1;
	else
		element->data->change_key = element->index;
	element->data->redraw = 1;
}

void	change_fov(t_click_args *element)
{
	float	new_val;

	new_val = *(float *)element->val;
	element->data->settings.fov = (int)(MIN_FOV + new_val
			* (MAX_FOV - MIN_FOV));
	init_player_plane(element->data, element->data->settings.fov);
	save_settings_in_file(element->data);
	element->data->redraw = 1;
}

void	change_brightness(t_click_args *element)
{
	float	new_val;

	new_val = *(float *)element->val;
	element->data->settings.brightness = (int)(MIN_BRIGHT + new_val
			* (100 - MIN_BRIGHT));
	save_settings_in_file(element->data);
	element->data->redraw = 1;
}

void	change_mouse_sensitivity(t_click_args *element)
{
	float	new_val;

	new_val = *(float *)element->val;
	element->data->settings.mouse_sensitivity = MOUSE_SENS_MIN + new_val
		* (MOUSE_SENS_MAX - MOUSE_SENS_MIN);
	save_settings_in_file(element->data);
}

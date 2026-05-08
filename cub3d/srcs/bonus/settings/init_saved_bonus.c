/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saved_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:29:17 by tjourdai          #+#    #+#             */
/*   Updated: 2026/05/08 11:31:10 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static void	set_saved_key(t_data *data, char *line)
{
	if (!ft_strncmp(line, "FW=", 3))
	{
		data->settings.key_forward = ft_atoi(line + 3);
		if (!key_is_bindable(data, data->settings.key_forward))
			data->settings.key_forward = KEY_W;
	}
	else if (!ft_strncmp(line, "BW=", 3))
	{
		data->settings.key_backward = ft_atoi(line + 3);
		if (!key_is_bindable(data, data->settings.key_backward))
			data->settings.key_backward = KEY_S;
	}
	else if (!ft_strncmp(line, "LW=", 3))
	{
		data->settings.key_left = ft_atoi(line + 3);
		if (!key_is_bindable(data, data->settings.key_left))
			data->settings.key_left = KEY_A;
	}
	else if (!ft_strncmp(line, "RW=", 3))
	{
		data->settings.key_right = ft_atoi(line + 3);
		if (!key_is_bindable(data, data->settings.key_right))
			data->settings.key_right = KEY_D;
	}
}

void	set_saved_value(t_data *data, char *line)
{
	if (!ft_strncmp(line, "DC=", 3))
	{
		data->settings.fov = ft_atoi(line + 3);
		if (data->settings.fov < MIN_FOV)
			data->settings.fov = MIN_FOV;
		else if (data->settings.fov > MAX_FOV)
			data->settings.fov = MAX_FOV;
	}
	else if (!ft_strncmp(line, "MS=", 3))
	{
		data->settings.mouse_sensitivity = ft_atoi(line + 3) / 1000.0;
		if (data->settings.mouse_sensitivity < MOUSE_SENS_MIN)
			data->settings.mouse_sensitivity = MOUSE_SENS_MIN;
		else if (data->settings.mouse_sensitivity > MOUSE_SENS_MAX)
			data->settings.mouse_sensitivity = MOUSE_SENS_MAX;
	}
	else if (!ft_strncmp(line, "BR=", 3))
	{
		data->settings.brightness = ft_atoi(line + 3);
		if (data->settings.brightness < MIN_BRIGHT)
			data->settings.brightness = MIN_BRIGHT;
		else if (data->settings.brightness > 100)
			data->settings.brightness = 100;
	}
	set_saved_key(data, line);
}

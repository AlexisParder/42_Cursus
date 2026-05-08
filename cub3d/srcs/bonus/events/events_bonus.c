/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 12:35:26 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/06 13:51:22 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	key_hook(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == 41)
		close_game(data, EXIT_SUCCESS);
	data->keys[key] = 1;
	if (key_is_bindable(data, key))
	{
		change_key_bind(data, key);
		data->change_key = -1;
		data->redraw = 1;
	}
	if (data->change_key != -1)
	{
		data->change_key = -1;
		data->redraw = 1;
	}
}

void	key_up_hook(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->keys[key] = 0;
}

void	window_hook(int event, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (event == 0)
		close_game(data, EXIT_SUCCESS);
}

void	mouse_click_hook(int button, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (!data->pause || button != 1)
		return ;
	data->dragging = 1;
}

void	mouse_release_hook(int button, void *param)
{
	t_data	*data;

	(void)button;
	data = (t_data *)param;
	if (data->dragging)
	{
		data->dragging = 0;
		data->drag_idx = -1;
	}
}

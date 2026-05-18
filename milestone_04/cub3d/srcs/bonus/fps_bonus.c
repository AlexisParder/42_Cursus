/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 09:42:48 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/07 10:25:37 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	fps_init(t_fps *fps)
{
	fps->last_time_ms = get_time_ms();
	fps->frame_count = 0;
	fps->fps = 0;
}

static void	draw_fps(t_data *data)
{
	char	*fps_str;

	fps_str = ft_itoa(data->fps.fps);
	if (fps_str)
	{
		if (file_exists(INT_FONT, 0))
			mlx_set_font_scale(data->mlx, INT_FONT, 16);
		mlx_string_put(data->mlx, data->win, M_MARGIN,
			data->win_h - M_MARGIN - M_SIZE - 10,
			data->cl_interact, fps_str);
		free(fps_str);
	}
	else
	{
		ft_dprintf(2, "Error\nFailure during allocation.\n");
		close_game(data, EXIT_FAILURE);
	}
}

void	fps_update(t_data *data)
{
	long	current_ms;
	long	elapsed_ms;

	data->fps.frame_count++;
	current_ms = get_time_ms();
	elapsed_ms = current_ms - data->fps.last_time_ms;
	if (elapsed_ms >= 1000)
	{
		data->fps.fps = (data->fps.frame_count * 1000) / elapsed_ms;
		data->fps.frame_count = 0;
		data->fps.last_time_ms = current_ms;
	}
	if (data->draw_fps && !data->pause)
		draw_fps(data);
}

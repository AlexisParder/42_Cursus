/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:25:07 by tjourdai          #+#    #+#             */
/*   Updated: 2026/04/30 16:15:00 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static void	draw_background(t_data *data)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < data->win_w)
	{
		j = 0;
		while (j < data->win_h)
		{
			data->framebuffer[i + j * data->win_w].a = 100;
			j++;
		}
		i++;
	}
	mlx_set_image_region(data->mlx, data->global_img, 0, 0,
		data->win_w, data->win_h, data->framebuffer);
}

static void	draw_buttons(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->buttons_count)
	{
		if (data->buttons[i].label)
			draw_button(data, &data->buttons[i]);
		i++;
	}
}

void	draw_settings(t_data *data)
{
	mlx_color	cl;

	cl.rgba = 0xFFFFFFFF;
	draw_background(data);
	mlx_put_image_to_window(data->mlx, data->win, data->global_img, 0, 0);
	if (file_exists(INT_FONT, 0))
		mlx_set_font_scale(data->mlx, INT_FONT, data->win_h / 15.0f);
	mlx_string_put(data->mlx, data->win,
		data->win_w / 2 - data->win_w / 15, data->win_h / 6, cl, "SETTINGS");
	if (file_exists(INT_FONT, 0))
		mlx_set_font_scale(data->mlx, INT_FONT, data->win_h / 25.0f);
	mlx_string_put(data->mlx, data->win,
		data->win_w / 4 - data->win_w / 20, data->win_h / 4, cl, "CONTROLS");
	mlx_string_put(data->mlx, data->win,
		(data->win_w / 4) * 3 - data->win_w / 20, data->win_h / 4, cl,
		"ADVANCED");
	if (file_exists(INT_FONT, 0))
		mlx_set_font_scale(data->mlx, INT_FONT, data->win_h / 35.0f);
	draw_buttons(data);
}

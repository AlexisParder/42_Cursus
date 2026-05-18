/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sld_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 08:44:05 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/01 08:45:42 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static void	draw_sld_btn(t_data *data, t_button *btn)
{
	int	i;
	int	j;

	i = btn->x;
	while (i < btn->x + btn->w)
	{
		j = btn->y;
		while (j < btn->y + btn->h)
		{
			mlx_pixel_put(data->mlx, data->win, i, j, data->colors.bg);
			j++;
		}
		i++;
	}
}

void	draw_slider_button(t_data *data, t_button *btn)
{
	int	filled_w;
	int	label_y;
	int	i;
	int	j;

	filled_w = (int)(btn->w * btn->value);
	draw_sld_btn(data, btn);
	i = btn->x;
	while (i < btn->x + filled_w)
	{
		j = btn->y;
		while (j < btn->y + btn->h)
		{
			mlx_pixel_put(data->mlx, data->win, i, j, data->colors.fill);
			j++;
		}
		i++;
	}
	label_y = btn->y + (btn->h / 2) + 5;
	mlx_string_put(data->mlx, data->win, btn->x + 10, label_y,
		data->colors.white, btn->label);
}

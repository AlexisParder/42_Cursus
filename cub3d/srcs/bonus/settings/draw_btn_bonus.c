/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_btn_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:48:25 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/01 08:43:53 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static void	draw_btn(t_data *data, t_button *btn)
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

static void	draw_key(t_data *data, t_button *btn, int key_size, int key_x)
{
	int	i;
	int	j;

	i = key_x;
	while (i < key_x + key_size)
	{
		j = btn->y;
		while (j < btn->y + btn->h)
		{
			if (data->change_key == btn->index)
				mlx_pixel_put(data->mlx, data->win, i, j, data->colors.bg);
			else
				mlx_pixel_put(data->mlx, data->win, i, j, data->colors.key_bg);
			j++;
		}
		i++;
	}
}

static void	draw_key_button(t_data *data, t_button *btn)
{
	int			key_size;
	int			key_x;
	int			label_y;
	int			key_text_x;

	key_size = btn->h;
	key_x = btn->x + btn->w + 8;
	draw_btn(data, btn);
	draw_key(data, btn, key_size, key_x);
	label_y = btn->y + (btn->h / 2) + 5;
	mlx_string_put(data->mlx, data->win, btn->x + 10, label_y,
		data->colors.white, btn->label);
	key_text_x = key_x + (key_size / 2) - (ft_strlen(btn->key) * 5);
	mlx_string_put(data->mlx, data->win, key_text_x, label_y,
		data->colors.white, btn->key);
}

void	draw_button(t_data *data, t_button *btn)
{
	if (btn->type == BUTTON_KEY)
		draw_key_button(data, btn);
	else if (btn->type == BUTTON_SLIDER)
		draw_slider_button(data, btn);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:42:00 by tjourdai          #+#    #+#             */
/*   Updated: 2026/04/30 16:51:38 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

int	key_is_bindable(t_data *data, int key)
{
	if (data->change_key == -1)
		return (0);
	if (!data->buttons[data->change_key].key)
		return (0);
	if (!mbx_key_from_id(key))
		return (0);
	if (data->settings.key_forward == key
		|| data->settings.key_backward == key
		|| data->settings.key_right == key
		|| data->settings.key_left == key)
		return (0);
	return (1);
}

static int	is_on_button(t_button *btn, int mx, int my)
{
	int	key_x;

	if (btn->type == BUTTON_SLIDER)
		return (mx >= btn->x && mx <= btn->x + btn->w
			&& my >= btn->y && my <= btn->y + btn->h);
	key_x = btn->x + btn->w + 8;
	return (mx >= key_x && mx <= key_x + btn->h
		&& my >= btn->y && my <= btn->y + btn->h);
}

static void	set_slider_new_val(t_data *data, int mx)
{
	float			new_val;
	t_click_args	args;

	if (data->drag_idx < 0)
		return ;
	new_val = (float)(mx - data->buttons[data->drag_idx].x)
		/ (float)data->buttons[data->drag_idx].w;
	if (new_val < 0.0f)
		new_val = 0.0f;
	if (new_val > 1.0f)
		new_val = 1.0f;
	data->buttons[data->drag_idx].value = new_val;
	args.data = data;
	args.val = &new_val;
	args.index = data->drag_idx;
	data->buttons[data->drag_idx].on_click(&args);
	data->redraw = 1;
}

static void	updt_slider_data(t_data *data, int i, int mx)
{
	t_click_args	args;

	if (data->buttons[i].type == BUTTON_SLIDER)
	{
		data->drag_idx = i;
		set_slider_new_val(data, mx);
	}
	else if (data->buttons[i].on_click && data->dragging)
	{
		data->dragging = 0;
		args.data = data;
		args.val = NULL;
		args.index = i;
		data->buttons[i].on_click(&args);
	}
}

void	update_sliders(t_data *data)
{
	int				mx;
	int				my;
	int				i;

	if (!data->dragging)
		return ;
	mlx_mouse_get_pos(data->mlx, &mx, &my);
	i = 0;
	while (i < data->buttons_count)
	{
		if (is_on_button(&data->buttons[i], mx, my))
			updt_slider_data(data, i, mx);
		i++;
	}
}

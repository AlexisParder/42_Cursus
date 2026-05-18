/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:35:44 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/06 14:09:37 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static void	register_button(t_data *data, t_button button)
{
	static int	i = 0;

	data->buttons[i].x = button.x;
	data->buttons[i].y = button.y;
	data->buttons[i].w = button.w;
	data->buttons[i].h = button.h;
	data->buttons[i].label = button.label;
	data->buttons[i].key = button.key;
	data->buttons[i].type = button.type;
	data->buttons[i].index = i;
	data->buttons[i].value = button.value;
	data->buttons[i].on_click = button.on_click;
	i++;
}

static void	register_slider(t_data *dt, t_vec2 btn_sz, int start_y, int gap)
{
	int	col2_x;

	col2_x = (dt->win_w / 4) * 3 - dt->win_w / 10;
	register_button(dt, (t_button){
		.x = col2_x, .y = start_y,
		.w = (int)btn_sz.x, .h = (int)btn_sz.y,
		.label = "FOV", .type = BUTTON_SLIDER,
		.value = (float)(dt->settings.fov - MIN_FOV) / (MAX_FOV - MIN_FOV),
		.on_click = change_fov
	});
	register_button(dt, (t_button){
		.x = col2_x, .y = start_y + gap,
		.w = (int)btn_sz.x, .h = (int)btn_sz.y,
		.label = "Brightness", .type = BUTTON_SLIDER,
		.value = (float)(dt->settings.brightness - MIN_BRIGHT)
		/ (100 - MIN_BRIGHT), .on_click = change_brightness
	});
	register_button(dt, (t_button){
		.x = col2_x, .y = start_y + (gap * 2),
		.w = (int)btn_sz.x, .h = (int)btn_sz.y,
		.label = "Mouse sensitivity", .type = BUTTON_SLIDER,
		.value = (dt->settings.mouse_sensitivity - MOUSE_SENS_MIN)
		/ (MOUSE_SENS_MAX - MOUSE_SENS_MIN),
		.on_click = change_mouse_sensitivity
	});
}

static void	register_mv_fb(t_data *dt, t_vec2 btn_sz, int start_y, int gap)
{
	int	col1_x;

	col1_x = (dt->win_w / 4 - dt->win_w / 10) - ((int)btn_sz.x / 10);
	register_button(dt, (t_button){
		.x = col1_x, .y = start_y,
		.w = (int)btn_sz.x, .h = (int)btn_sz.y,
		.label = "Forward",
		.key = (char *)mbx_key_from_id(dt->settings.key_forward),
		.on_click = change_keys
	});
	register_button(dt, (t_button){
		.x = col1_x, .y = start_y + gap,
		.w = (int)btn_sz.x, .h = (int)btn_sz.y,
		.label = "Backward",
		.key = (char *)mbx_key_from_id(dt->settings.key_backward),
		.on_click = change_keys
	});
}

static void	register_mv_lr(t_data *dt, t_vec2 btn_sz, int start_y, int gap)
{
	int	col1_x;

	col1_x = (dt->win_w / 4 - dt->win_w / 10) - ((int)btn_sz.x / 10);
	register_button(dt, (t_button){
		.x = col1_x, .y = start_y + gap * 2,
		.w = (int)btn_sz.x, .h = (int)btn_sz.y,
		.label = "Strafe right",
		.key = (char *)mbx_key_from_id(dt->settings.key_right),
		.on_click = change_keys
	});
	register_button(dt, (t_button){
		.x = col1_x, .y = start_y + gap * 3,
		.w = (int)btn_sz.x, .h = (int)btn_sz.y,
		.label = "Strafe left",
		.key = (char *)mbx_key_from_id(dt->settings.key_left),
		.on_click = change_keys
	});
}

void	register_sl_btn(t_data *data)
{
	t_vec2	btn_sz;
	int		gap;
	int		start_y;

	data->dragging = 0;
	data->drag_idx = -1;
	data->buttons_count = 7;
	data->buttons = ft_calloc(data->buttons_count, sizeof(t_button));
	if (!data->buttons)
	{
		ft_dprintf(2, "Error\ninit settings failure\n");
		close_game(data, EXIT_FAILURE);
	}
	set_save_settings(data);
	btn_sz.x = data->win_w / 5;
	btn_sz.y = data->win_h / 13;
	gap = data->win_h / 10;
	start_y = data->win_h / 3;
	register_mv_fb(data, btn_sz, start_y, gap);
	register_mv_lr(data, btn_sz, start_y, gap);
	register_slider(data, btn_sz, start_y, gap);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 13:10:58 by tjourdai          #+#    #+#             */
/*   Updated: 2026/05/05 15:28:44 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static void	interact_door(t_data *data)
{
	if (data->tile_front.x == (int)data->player.pos.x
		&& data->tile_front.y == (int)data->player.pos.y)
		data->interact_door = 0;
	if (!data->pause && ft_strchr("DO", data->tile_front.type))
	{
		data->interact_door = 1;
		if (file_exists(INT_FONT, 0))
			mlx_set_font_scale(data->mlx, INT_FONT, INT_FONT_SIZE);
		mlx_string_put(data->mlx, data->win, data->win_w / 2, data->win_h / 2,
			data->cl_interact, "E - Interact");
	}
	else if (!ft_strchr("DO", data->tile_front.type))
		data->interact_door = 0;
}

static void	redraw(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	actions(data);
	if (data->redraw)
	{
		raycasting(data);
		apply_flashlight(data);
		mlx_put_image_to_window(data->mlx, data->win, data->global_img, 0, 0);
		fps_update(data);
		draw_minimap(data);
		manage_sprites(data);
	}
	interact_door(data);
	update_sliders(data);
}

static void	create_mlx_event(t_data *data)
{
	mlx_on_event(data->mlx, data->win, MLX_WINDOW_EVENT, window_hook, data);
	mlx_on_event(data->mlx, data->win, MLX_KEYDOWN, key_hook, data);
	mlx_on_event(data->mlx, data->win, MLX_KEYUP, key_up_hook, data);
	mlx_on_event(data->mlx, data->win, MLX_MOUSEDOWN, mouse_click_hook, data);
	mlx_on_event(data->mlx, data->win, MLX_MOUSEUP, mouse_release_hook, data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		ft_dprintf(2, "Error\nInvalid format: './cub3D <path/map_name.cub>'\n");
		return (1);
	}
	check_map_format(av[1]);
	init_data(&data);
	parse_map(&data, av[1]);
	check_map(&data);
	register_sl_btn(&data);
	init_player(&data);
	init_mlx(&data);
	init_imgs(&data);
	init_sprites(&data);
	init_collision(&data);
	init_color(&data);
	init_window(&data);
	fps_init(&data.fps);
	create_mlx_event(&data);
	mlx_add_loop_hook(data.mlx, redraw, &data);
	mlx_loop(data.mlx);
	return (0);
}

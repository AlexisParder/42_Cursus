/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 13:10:58 by tjourdai          #+#    #+#             */
/*   Updated: 2026/04/22 14:29:33 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	key_hook(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == 41)
		close_game(data, EXIT_SUCCESS);
	data->keys[key] = 1;
}

static void	key_up_hook(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->keys[key] = 0;
}

static void	window_hook(int event, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (event == 0)
		close_game(data, EXIT_SUCCESS);
}

static void	redraw(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	actions(data);
	if (data->redraw)
		raycasting(data);
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
	init_player(&data);
	init_mlx(&data);
	init_imgs(&data);
	init_window(&data);
	mlx_on_event(data.mlx, data.win, MLX_WINDOW_EVENT, window_hook, &data);
	mlx_on_event(data.mlx, data.win, MLX_KEYDOWN, key_hook, &data);
	mlx_on_event(data.mlx, data.win, MLX_KEYUP, key_up_hook, &data);
	mlx_add_loop_hook(data.mlx, redraw, &data);
	mlx_loop(data.mlx);
	return (0);
}

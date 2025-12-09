/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:30:13 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/09 13:14:41 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	keydown_hook(int key, void *param)
{
	t_mlx_dt	*mlx_data;

	mlx_data = (t_mlx_dt *)param;
	if (key == 41)
		mlx_loop_end((mlx_context)mlx_data->mlx);
	else if (!mlx_data->key_pressed && key == 7)
	{
		mlx_data->key_pressed = 1;
		make_move(mlx_data, 'r');
	}
	else if (!mlx_data->key_pressed && key == 26)
	{
		mlx_data->key_pressed = 1;
		make_move(mlx_data, 't');
	}
	else if (!mlx_data->key_pressed && key == 4)
	{
		mlx_data->key_pressed = 1;
		make_move(mlx_data, 'l');
	}
	else if (!mlx_data->key_pressed && key == 22)
	{
		mlx_data->key_pressed = 1;
		make_move(mlx_data, 'd');
	}
}

static void	keyup_hook(int key, void *param)
{
	t_mlx_dt	*mlx_data;

	mlx_data = (t_mlx_dt *)param;
	if (key)
		mlx_data->key_pressed = 0;
}

static void	win_hook(int key, void *param)
{
	t_mlx_dt	*mlx_data;

	mlx_data = (t_mlx_dt *)param;
	if (key == 0)
		mlx_loop_end((mlx_context)mlx_data->mlx);
}

int	main(int ac, char **av)
{
	t_mlx_dt				mlx_dt;
	mlx_window_create_info	info = {0};

	if (ac != 2)
	{
		perror("Error:\nInvalid format: './so_long <map_name.ber>'");
		return (1);
	}
	mlx_dt.player = NULL;
	mlx_dt.key_pressed = 0;
	create_map_dt(&mlx_dt, av);
	mlx_dt.mlx = mlx_init();
	info.title = "so_long";
	info.width = 1920;
	info.height = 1080;
	info.is_resizable = true;
	mlx_dt.win = mlx_new_window(mlx_dt.mlx, &info);
	mlx_on_event(mlx_dt.mlx, mlx_dt.win, MLX_KEYDOWN, keydown_hook, &mlx_dt);
	mlx_on_event(mlx_dt.mlx, mlx_dt.win, MLX_WINDOW_EVENT, win_hook, &mlx_dt);
	mlx_on_event(mlx_dt.mlx, mlx_dt.win, MLX_KEYUP, keyup_hook, &mlx_dt);
	creates_images(&mlx_dt, &mlx_dt.map);
	mlx_loop(mlx_dt.mlx);
	clean_all(mlx_dt);
	return (0);
}

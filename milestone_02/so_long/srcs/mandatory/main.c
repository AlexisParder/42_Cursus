/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:30:13 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/23 12:40:49 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static int	keydown_hook(int key, t_mlx_dt *mlx_data)
{
	if (key == 65307)
		close_game(mlx_data, EXIT_SUCCESS);
	else if (key == 119 || key == 65362)
		make_move(mlx_data, MOVE_UP);
	else if (key == 115 || key == 65364)
		make_move(mlx_data, MOVE_DOWN);
	else if (key == 97 || key == 65361)
		make_move(mlx_data, MOVE_LEFT);
	else if (key == 100 || key == 65363)
		make_move(mlx_data, MOVE_RIGHT);
	return (0);
}

static int	close_hook(void *param)
{
	t_mlx_dt	*mlx_data;

	mlx_data = (t_mlx_dt *)param;
	close_game(mlx_data, EXIT_SUCCESS);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx_dt	mlx_dt;

	if (ac != 2)
	{
		ft_printf("Error\nInvalid format: './so_long <path/map_name.ber>'");
		return (1);
	}
	mlx_dt.player = NULL;
	create_map_dt(&mlx_dt, av);
	mlx_dt.mlx = mlx_init();
	if (!mlx_dt.mlx)
		close_game(&mlx_dt, EXIT_FAILURE);
	init_img_ref(&mlx_dt);
	mlx_do_key_autorepeatoff(mlx_dt.mlx);
	manage_window(&mlx_dt);
	mlx_hook(mlx_dt.win, 2, 1, keydown_hook, &mlx_dt);
	mlx_hook(mlx_dt.win, 17, 0, close_hook, &mlx_dt);
	creates_images(&mlx_dt, &mlx_dt.map_dt);
	mlx_loop(mlx_dt.mlx);
	free(mlx_dt.mlx);
	return (0);
}

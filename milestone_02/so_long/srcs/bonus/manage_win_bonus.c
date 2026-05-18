/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_win_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:25:18 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/23 09:39:42 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	manage_window(t_mlx_dt *mlx_dt)
{
	int			win_width;
	int			win_height;

	mlx_dt->stop_game = 0;
	mlx_dt->frame = 0;
	mlx_dt->enemy = NULL;
	win_width = mlx_dt->map_dt.x_max * IMG_SIZE;
	win_height = mlx_dt->map_dt.y_max * IMG_SIZE;
	mlx_get_screen_size(mlx_dt->mlx, &mlx_dt->w, &mlx_dt->h);
	if (win_width < mlx_dt->w)
		mlx_dt->w = win_width;
	if (win_height < mlx_dt->h)
		mlx_dt->h = win_height;
	mlx_dt->win = mlx_new_window(mlx_dt->mlx, mlx_dt->w, mlx_dt->h, TITLE);
	if (!mlx_dt->win)
		close_game(mlx_dt, EXIT_FAILURE);
}

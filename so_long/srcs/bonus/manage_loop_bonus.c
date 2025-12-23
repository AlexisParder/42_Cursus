/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_loop_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 13:34:08 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/23 13:34:26 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

int	manage_loop(t_mlx_dt *mlx_dt)
{
	if (mlx_dt->stop_game)
		return (0);
	mlx_dt->frame++;
	if (mlx_dt->frame % MOVE_DELAY_ENEMY == 0)
		move_enemies(mlx_dt, &mlx_dt->enemy);
	draw_enemies(mlx_dt);
	display_move(mlx_dt);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_loop_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 13:34:08 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/27 08:50:32 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

int	manage_loop(t_mlx_dt *mlx_dt)
{
	long		current_time;
	static long	last_time_enemy_move = 0;

	if (mlx_dt->stop_game)
		return (0);
	mlx_dt->frame++;
	current_time = get_time_ms();
	if (current_time - last_time_enemy_move >= MOVE_DELAY_ENEMY)
	{
		move_enemies(mlx_dt, &mlx_dt->enemy);
		last_time_enemy_move = current_time;
	}
	draw_enemies(mlx_dt);
	display_move(mlx_dt);
	return (0);
}

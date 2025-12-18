/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_enemy_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:29:07 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/18 16:36:08 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	updt_map(t_mlx_dt *dt, t_enemy_dt *en, size_t pos_x, size_t pos_y)
{
	t_player_dt	*player;
	t_map_dt	map_dt;

	player = dt->player;
	map_dt = dt->map_dt;
	if (en->is_on_loot)
	{
		map_dt.map[pos_y][pos_x] = 'C';
		en->is_on_loot = 0;
	}
	else
		map_dt.map[pos_y][pos_x] = '0';
	pos_x = en->pos_x;
	pos_y = en->pos_y;
	if (map_dt.map[pos_y][pos_x] == 'C')
		en->is_on_loot = 1;
	if (map_dt.y_exit == player->pos_y && map_dt.x_exit == player->pos_x)
		map_dt.map[map_dt.y_exit][map_dt.x_exit] = 'P';
	else
		map_dt.map[map_dt.y_exit][map_dt.x_exit] = 'E';
}

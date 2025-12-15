/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_enemy_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:45:42 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/15 14:41:38 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

#include <stdio.h>

static void	updt_en_move(t_enemy_dt *enemy)
{
	if (enemy->direction == 'r')
		enemy->pos_x++;
	else if (enemy->direction == 'l')
		enemy->pos_x--;
	else if (enemy->direction == 't')
		enemy->pos_y--;
	else if (enemy->direction == 'd')
		enemy->pos_y++;
	enemy->direction = enemy->direction;
}

void	make_move_enemy(t_mlx_dt *mlx_dt, t_enemy_dt *enemy)
{
	size_t	pos_x;
	size_t	pos_y;
	size_t	last_pos_x;
	size_t	last_pos_y;

	last_pos_x = enemy->pos_x;
	last_pos_y = enemy->pos_y;
	updt_en_move(enemy);
	pos_x = enemy->pos_x;
	pos_y = enemy->pos_y;
	if (enemy->is_on_loot)
	{
		mlx_dt->map_dt.map[last_pos_y][last_pos_x] = 'C';
		enemy->is_on_loot = 0;
	}
	else
		mlx_dt->map_dt.map[last_pos_y][last_pos_x] = '0';
	if (mlx_dt->map_dt.map[pos_y][pos_x] == 'C')
		enemy->is_on_loot = 1;
	mlx_dt->map_dt.map[mlx_dt->map_dt.y_exit][mlx_dt->map_dt.x_exit] = 'E';
	if (mlx_dt->map_dt.map[pos_y][pos_x] == 'P')
		display_lose(mlx_dt);
	mlx_dt->map_dt.map[pos_y][pos_x] = 'H';
}

static void move_enemies(t_mlx_dt *mlx_dt, t_enemy_dt **lst)
{
	t_enemy_dt	*enemy;

	enemy = *lst;
	while (enemy)
	{
		if (check_move(mlx_dt, enemy->direction, enemy->pos_x, enemy->pos_y))
			make_move_enemy(mlx_dt, enemy);
		else
			ft_printf("DOIT CHANGER DE DIRECTION\n");
		enemy = enemy->next;
	}
	redraw_window(mlx_dt);
	draw_enemies(mlx_dt);
}

int	manage_enemy(t_mlx_dt *mlx_dt)
{
	if (mlx_dt->stop_game)
		return (0);
	mlx_dt->frame++;
	if (mlx_dt->frame % SPEED_MOVE_ENEMY == 0)
	{
		move_enemies(mlx_dt, &mlx_dt->enemy);
	}
	return (0);
}

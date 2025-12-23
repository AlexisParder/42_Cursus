/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_enemy_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:45:42 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/23 12:37:06 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

static void	updt_en_move(t_enemy_dt *enemy)
{
	if (enemy->direction == MOVE_RIGHT)
		enemy->pos_x++;
	else if (enemy->direction == MOVE_LEFT)
		enemy->pos_x--;
	else if (enemy->direction == MOVE_UP)
		enemy->pos_y--;
	else if (enemy->direction == MOVE_DOWN)
		enemy->pos_y++;
	enemy->direction = enemy->direction;
}

static void	make_move_enemy(t_mlx_dt *mlx_dt, t_enemy_dt *enemy)
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
	updt_map(mlx_dt, enemy, last_pos_x, last_pos_y);
	if (pos_x == mlx_dt->player->pos_x && pos_y == mlx_dt->player->pos_y)
		display_lose(mlx_dt);
	mlx_dt->map_dt.map[pos_y][pos_x] = 'H';
}

static void	updt_direction(t_mlx_dt *mlx_dt, t_enemy_dt *enemy)
{
	int		move_l;
	int		move_r;
	int		move_t;
	int		move_d;
	char	r_dir;

	move_l = check_move_en(mlx_dt, MOVE_LEFT, enemy->pos_x, enemy->pos_y);
	move_r = check_move_en(mlx_dt, MOVE_RIGHT, enemy->pos_x, enemy->pos_y);
	move_t = check_move_en(mlx_dt, MOVE_UP, enemy->pos_x, enemy->pos_y);
	move_d = check_move_en(mlx_dt, MOVE_DOWN, enemy->pos_x, enemy->pos_y);
	r_dir = random_dir(move_l, move_r, move_t, move_d);
	if (r_dir == MOVE_DOWN || r_dir == MOVE_RIGHT
		|| r_dir == MOVE_LEFT || r_dir == MOVE_UP)
	{
		enemy->direction = r_dir;
		make_move_enemy(mlx_dt, enemy);
	}
}

static void	move_enemies(t_mlx_dt *mlx_dt, t_enemy_dt **lst)
{
	t_enemy_dt	*enemy;

	enemy = *lst;
	while (enemy)
	{
		if (check_move_en(mlx_dt, enemy->direction, enemy->pos_x, enemy->pos_y))
			make_move_enemy(mlx_dt, enemy);
		else
			updt_direction(mlx_dt, enemy);
		enemy = enemy->next;
	}
	redraw_window(mlx_dt);
}

int	manage_enemy(t_mlx_dt *mlx_dt)
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

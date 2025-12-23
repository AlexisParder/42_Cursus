/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:48:43 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/23 09:50:56 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	display_move(t_mlx_dt *dt)
{
	char	*nb_move;
	int		pos_x;

	nb_move = ft_itoa(dt->player->nb_move);
	mlx_set_font(dt->mlx, dt->win, "9x15");
	mlx_put_image_to_window(dt->mlx, dt->win, dt->img_ref.cnt, 0, 0);
	if (dt->player->nb_move >= 100)
		pos_x = 45;
	else if (dt->player->nb_move >= 10)
		pos_x = 50;
	else
		pos_x = 55;
	mlx_string_put(dt->mlx, dt->win, pos_x, 34, 0x000000, nb_move);
	free(nb_move);
}

void	display_lose(t_mlx_dt *dt)
{
	char	*msg;
	int		x;
	int		y;

	dt->stop_game = 1;
	mlx_clear_window(dt->mlx, dt->win);
	mlx_set_font(dt->mlx, dt->win, "9x15");
	x = (dt->w / 2) - (392 / 2);
	y = (dt->h / 2) - (636 / 2);
	mlx_put_image_to_window(dt->mlx, dt->win, dt->img_ref.lose, x, y);
	msg = "Quit game with ESCAPE key";
	mlx_string_put(dt->mlx, dt->win, x + (32 * 3), y + (64 * 2), 0xFF0000, msg);
}

void	display_win(t_mlx_dt *dt)
{
	char	*msg;
	int		x;
	int		y;

	dt->stop_game = 1;
	mlx_clear_window(dt->mlx, dt->win);
	mlx_set_font(dt->mlx, dt->win, "9x15");
	x = (dt->w / 2) - (425 / 2);
	y = (dt->h / 2) - (588 / 2);
	mlx_put_image_to_window(dt->mlx, dt->win, dt->img_ref.win, x, y);
	msg = "Quit game with ESCAPE key";
	mlx_string_put(dt->mlx, dt->win, x + (32 * 3), y + (64 * 2), 0x00FF00, msg);
}

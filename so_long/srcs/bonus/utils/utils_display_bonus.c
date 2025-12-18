/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:48:43 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/18 10:10:02 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	display_move(t_mlx_dt *dt)
{
	char	*nb_move;

	nb_move = ft_itoa(dt->player->nb_move);
	mlx_string_put(dt->mlx, dt->win, 64, 13, 0x000000, "Number of movements:");
	mlx_string_put(dt->mlx, dt->win, 192, 13, 0x000000, nb_move);
	free(nb_move);
}

void	display_lose(t_mlx_dt *dt)
{
	char	*msg;

	(*dt).stop_game = 1;
	mlx_clear_window(dt->mlx, dt->win);
	mlx_put_image_to_window((*dt).mlx, (*dt).win, (*dt).img_ref.lose, 0, 0);
	msg = "Quit game with ESCAPE key";
	mlx_string_put(dt->mlx, dt->win, 192 * 3, 64, 0xFF0000, msg);
}

void	display_win(t_mlx_dt *dt)
{
	char	*msg;

	(*dt).stop_game = 1;
	mlx_clear_window(dt->mlx, dt->win);
	mlx_put_image_to_window((*dt).mlx, (*dt).win, (*dt).img_ref.win, 0, 0);
	msg = "Quit game with ESCAPE key";
	mlx_string_put(dt->mlx, dt->win, 192 * 3, 64, 0x00FF00, msg);
}

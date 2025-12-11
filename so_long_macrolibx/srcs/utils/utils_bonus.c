/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:48:43 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/09 13:22:44 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	display_move(t_mlx_dt *dt)
{
	mlx_color	color;
	char		*nb_move;

	color.rgba = 0xFFFFFFFF;
	nb_move = ft_itoa(dt->player->nb_move);
	mlx_string_put(dt->mlx, dt->win, 32, 32, color, "Number of movements:");
	mlx_string_put(dt->mlx, dt->win, 192, 32, color, nb_move);
	free(nb_move);
}

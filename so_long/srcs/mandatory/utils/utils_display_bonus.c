/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:48:43 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/11 12:07:51 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	display_move(t_mlx_dt *dt)
{
	char	*nb_move;

	nb_move = ft_itoa(dt->player->nb_move);
	mlx_string_put(dt->mlx, dt->win, 64, 32, 0xFFFFFF, "Number of movements:");
	mlx_string_put(dt->mlx, dt->win, 192, 32, 0xFFFFFF, nb_move);
	free(nb_move);
}

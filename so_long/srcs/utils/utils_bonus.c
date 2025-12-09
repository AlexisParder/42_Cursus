/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:48:43 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/09 12:54:57 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	display_move(t_mlx_dt *mlx_data)
{
	mlx_color	color;

	color.rgba = 0xFFFFFFFF;
	mlx_string_put(mlx_data->mlx, mlx_data->win, 32, 32, color, "Number of movements:");
	mlx_string_put(mlx_data->mlx, mlx_data->win, 192, 32, color, ft_itoa(mlx_data->player->nb_move));
}
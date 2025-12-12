/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_win_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:25:18 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/12 12:37:34 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	manage_window(t_mlx_dt *mlx_dt)
{
	int			win_width;
	int			win_height;
	int			w;
	int			h;
	
	win_width = (*mlx_dt).map_dt.x_max * IMG_SIZE;
	win_height = ((*mlx_dt).map_dt.y_max + 1) * IMG_SIZE;
	mlx_get_screen_size((*mlx_dt).mlx, &w, &h);
	if (win_width < w)
		w = win_width;
	if (win_height < h)
		h = win_height;	
	(*mlx_dt).win = mlx_new_window((*mlx_dt).mlx, w, h, "so_long - achauvie");
}
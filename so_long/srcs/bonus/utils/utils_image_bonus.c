/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_image_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:14:59 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/15 10:36:52 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	*get_image_ref(t_mlx_dt *mlx_data, char chr)
{
	if (chr == '1')
		return (mlx_data->img_ref.wall);
	else if (chr == 'C')
		return (mlx_data->img_ref.loot);
	else if (chr == 'H')
		return (mlx_data->img_ref.enemy);
	return (mlx_data->img_ref.path);
}

void	err_img(t_mlx_dt *mlx_data, char *line)
{
	free(line);
	close_game(mlx_data);
}

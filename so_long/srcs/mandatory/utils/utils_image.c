/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:14:59 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/15 10:33:15 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	*get_image_ref(t_mlx_dt *mlx_data, char chr)
{
	if (chr == '1')
		return (mlx_data->img_ref.wall);
	else if (chr == '0')
		return (mlx_data->img_ref.path);
	return (mlx_data->img_ref.loot);
}

void	err_img(t_mlx_dt *mlx_data, char *line)
{
	free(line);
	close_game(mlx_data);
}

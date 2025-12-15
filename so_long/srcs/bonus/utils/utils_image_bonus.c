/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_image_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:14:59 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/15 14:17:07 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	*get_image_ref(t_mlx_dt *mlx_data, char chr)
{
	if (chr == '1')
		return (mlx_data->img_ref.wall);
	else if (chr == 'C')
		return (mlx_data->img_ref.loot);
	else if (chr == 'E')
	{
		if (mlx_data->player->loot_collected >= mlx_data->map_dt.total_loots)
			return (mlx_data->img_ref.exit_o);
		return (mlx_data->img_ref.exit_c);
	}
	return (mlx_data->img_ref.path);
}

void	err_img(t_mlx_dt *mlx_data, char *line)
{
	free(line);
	free_lst(&mlx_data->enemy);
	close_game(mlx_data, EXIT_FAILURE);
}

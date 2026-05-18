/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:14:59 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/27 09:37:01 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	*get_image_ref(t_mlx_dt *mlx_data, char chr)
{
	if (chr == '1')
		return (mlx_data->img_ref.wall);
	else if (chr == 'C')
		return (mlx_data->img_ref.loot);
	else if (chr == 'E' && mlx_data->player)
	{
		if (mlx_data->player->loot_collected >= mlx_data->map_dt.total_loots)
			return (mlx_data->img_ref.exit_o);
		return (mlx_data->img_ref.exit_c);
	}
	else if (chr == 'E' && !mlx_data->player)
		return (mlx_data->img_ref.exit_c);
	return (mlx_data->img_ref.path);
}

void	init_img_ref(t_mlx_dt *mlx_data)
{
	mlx_data->img_ref.pl_d = NULL;
	mlx_data->img_ref.pl_l = NULL;
	mlx_data->img_ref.pl_r = NULL;
	mlx_data->img_ref.pl_t = NULL;
	mlx_data->img_ref.exit_c = NULL;
	mlx_data->img_ref.exit_o = NULL;
	mlx_data->img_ref.loot = NULL;
	mlx_data->img_ref.path = NULL;
	mlx_data->img_ref.wall = NULL;
}

void	check_img_ref(t_mlx_dt *dt)
{
	t_imgs_ref	img_ref;
	int			err_found;

	img_ref = dt->img_ref;
	err_found = 0;
	if (!img_ref.pl_d || !img_ref.pl_l || !img_ref.pl_r || !img_ref.pl_t)
		err_found = 1;
	if (!img_ref.exit_c || !img_ref.exit_o)
		err_found = 1;
	if (!img_ref.loot || !img_ref.path || !img_ref.wall)
		err_found = 1;
	if (err_found)
	{
		ft_printf("Error\nProblem when creating an image");
		close_game(dt, EXIT_FAILURE);
	}
}

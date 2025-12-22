/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_image_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:14:59 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/22 13:31:27 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

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

void	err_img(t_mlx_dt *mlx_data, char *line)
{
	ft_printf("Error\nAllocation failure");
	free(line);
	free_lst(&mlx_data->enemy);
	close_game(mlx_data, EXIT_FAILURE);
}

void	init_img_ref(t_mlx_dt *mlx_data)
{
	mlx_data->img_ref.pl_d = NULL;
	mlx_data->img_ref.pl_l = NULL;
	mlx_data->img_ref.pl_r = NULL;
	mlx_data->img_ref.pl_t = NULL;
	mlx_data->img_ref.en1_d = NULL;
	mlx_data->img_ref.en1_l = NULL;
	mlx_data->img_ref.en1_r = NULL;
	mlx_data->img_ref.en1_t = NULL;
	mlx_data->img_ref.en2_d = NULL;
	mlx_data->img_ref.en2_l = NULL;
	mlx_data->img_ref.en2_r = NULL;
	mlx_data->img_ref.en2_t = NULL;
	mlx_data->img_ref.exit_c = NULL;
	mlx_data->img_ref.exit_o = NULL;
	mlx_data->img_ref.loot = NULL;
	mlx_data->img_ref.path = NULL;
	mlx_data->img_ref.wall = NULL;
	mlx_data->img_ref.lose = NULL;
	mlx_data->img_ref.win = NULL;
	mlx_data->img_ref.cnt = NULL;
}

void	check_img_ref(t_mlx_dt *dt)
{
	t_imgs_ref	img_ref;
	int			err_found;

	img_ref = dt->img_ref;
	err_found = 0;
	if (!img_ref.pl_d || !img_ref.pl_l || !img_ref.pl_r || !img_ref.pl_t)
		err_found = 1;
	if (!img_ref.en1_d || !img_ref.en1_l || !img_ref.en1_r || !img_ref.en1_t)
		err_found = 1;
	if (!img_ref.en2_d || !img_ref.en2_l || !img_ref.en2_r || !img_ref.en2_t)
		err_found = 1;
	if (!img_ref.exit_c || !img_ref.exit_o)
		err_found = 1;
	if (!img_ref.loot || !img_ref.path || !img_ref.wall)
		err_found = 1;
	if (!img_ref.lose || !img_ref.win || !img_ref.cnt)
		err_found = 1;
	if (err_found)
	{
		ft_printf("Error\nProblem when creating an image");
		close_game(dt, EXIT_FAILURE);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:06:39 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/22 13:14:59 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

static void	manage_line(t_mlx_dt *mlx_data, t_map_dt *map_data, size_t pos_y)
{
	size_t	i;
	char	*line;
	int		add_res;

	i = 0;
	line = ft_strdup(map_data->map[pos_y]);
	add_res = 1;
	while (line[i])
	{
		if (line[i] != 'P' && line[i] != 'H')
			add_image(mlx_data, get_image_ref(mlx_data, line[i]), i, pos_y);
		else if (line[i] == 'P')
			add_res = add_img_pl(mlx_data, mlx_data->img_ref.pl_r, i, pos_y);
		else if (line[i] == 'H')
			add_res = create_enemy(&(mlx_data->enemy), i, pos_y);
		if (line[i] == 'E')
		{
			mlx_data->map_dt.x_exit = i;
			mlx_data->map_dt.y_exit = pos_y;
		}
		if (!add_res)
			err_img(mlx_data, line);
		i++;
	}
	free(line);
}

static void	creates_images_ref(t_mlx_dt *dt)
{
	int			size;
	t_imgs_ref	i_ref;

	size = IMG_SIZE;
	i_ref.pl_d = mlx_xpm_file_to_image(dt->mlx, TXT_PLAYER_D, &size, &size);
	i_ref.pl_l = mlx_xpm_file_to_image(dt->mlx, TXT_PLAYER_L, &size, &size);
	i_ref.pl_r = mlx_xpm_file_to_image(dt->mlx, TXT_PLAYER_R, &size, &size);
	i_ref.pl_t = mlx_xpm_file_to_image(dt->mlx, TXT_PLAYER_T, &size, &size);
	i_ref.en1_d = mlx_xpm_file_to_image(dt->mlx, TXT_ENEMY_D_1, &size, &size);
	i_ref.en1_l = mlx_xpm_file_to_image(dt->mlx, TXT_ENEMY_L_1, &size, &size);
	i_ref.en1_r = mlx_xpm_file_to_image(dt->mlx, TXT_ENEMY_R_1, &size, &size);
	i_ref.en1_t = mlx_xpm_file_to_image(dt->mlx, TXT_ENEMY_T_1, &size, &size);
	i_ref.en2_d = mlx_xpm_file_to_image(dt->mlx, TXT_ENEMY_D_2, &size, &size);
	i_ref.en2_l = mlx_xpm_file_to_image(dt->mlx, TXT_ENEMY_L_2, &size, &size);
	i_ref.en2_r = mlx_xpm_file_to_image(dt->mlx, TXT_ENEMY_R_2, &size, &size);
	i_ref.en2_t = mlx_xpm_file_to_image(dt->mlx, TXT_ENEMY_T_2, &size, &size);
	i_ref.exit_c = mlx_xpm_file_to_image(dt->mlx, TXT_EXIT_C, &size, &size);
	i_ref.exit_o = mlx_xpm_file_to_image(dt->mlx, TXT_EXIT_O, &size, &size);
	i_ref.loot = mlx_xpm_file_to_image(dt->mlx, TXT_LOOT, &size, &size);
	i_ref.path = mlx_xpm_file_to_image(dt->mlx, TXT_PATH, &size, &size);
	i_ref.wall = mlx_xpm_file_to_image(dt->mlx, TXT_WALL, &size, &size);
	i_ref.lose = mlx_xpm_file_to_image(dt->mlx, TXT_LOSE, &size, &size);
	i_ref.win = mlx_xpm_file_to_image(dt->mlx, TXT_WIN, &size, &size);
	i_ref.cnt = mlx_xpm_file_to_image(dt->mlx, TXT_COUNT_BG, &size, &size);
	dt->img_ref = i_ref;
}

void	creates_images(t_mlx_dt *dt, t_map_dt *map_dt)
{
	size_t		pos_y;

	pos_y = 0;
	creates_images_ref(dt);
	check_img_ref(dt);
	while (map_dt->map[pos_y])
	{
		manage_line(dt, map_dt, pos_y);
		pos_y++;
	}
	display_move(dt);
}

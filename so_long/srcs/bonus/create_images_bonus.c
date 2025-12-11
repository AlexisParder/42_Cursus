/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:06:39 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/11 12:21:00 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static t_player_dt	*create_player(t_mlx_dt *dt, size_t pos_x, size_t pos_y)
{
	t_player_dt	*tmp;
	size_t		tmp_nb_move;
	size_t		tmp_nb_loot;
	char		tmp_last_move;

	tmp = ft_calloc(1, sizeof(t_player_dt));
	if (!tmp)
		return (NULL);
	tmp->size = IMG_SIZE;
	tmp->pos_x = pos_x;
	tmp->pos_y = pos_y;
	tmp_nb_move = 0;
	tmp_nb_loot = 0;
	tmp_last_move = 'r';
	if (dt->player != NULL)
	{
		tmp_nb_move = dt->player->nb_move;
		tmp_nb_loot = dt->player->loot_collected;
		tmp_last_move = dt->player->last_move;
		free(dt->player);
	}
	tmp->nb_move = tmp_nb_move;
	tmp->loot_collected = tmp_nb_loot;
	tmp->last_move = tmp_last_move;
	return (tmp);
}

void	add_img_pl(t_mlx_dt *dt, void *img, size_t pos_x, size_t pos_y)
{
	long	x_calc;
	long	y_calc;

	(*dt).player = create_player(dt, pos_x, pos_y);
	if (!(*dt).player)
		mlx_loop_end((void *)dt->mlx);
	x_calc = (*dt).player->pos_x * (*dt).player->size;
	y_calc = ((*dt).player->pos_y + 1) * (*dt).player->size;
	mlx_put_image_to_window((*dt).mlx, (*dt).win, img, x_calc, y_calc);
}

void	add_image(t_mlx_dt *dt, void *img, size_t pos_x, size_t pos_y)
{
	long	x_calc;
	long	y_calc;
	size_t	size;

	size = IMG_SIZE;
	x_calc = pos_x * size;
	y_calc = (pos_y + 1) * size;
	mlx_put_image_to_window((*dt).mlx, (*dt).win, img, x_calc, y_calc);
}

static void	manage_line(t_mlx_dt *mlx_data, t_map_dt *map_data, size_t pos_y)
{
	size_t	i;
	char	*line;

	i = 0;
	line = ft_strdup((*map_data).map[pos_y]);
	while (line[i])
	{
		if (line[i] == '1')
			add_image(mlx_data, mlx_data->img_ref.wall, i, pos_y);
		else if (line[i] == '0')
			add_image(mlx_data, mlx_data->img_ref.path, i, pos_y);
		else if (line[i] == 'E')
		{
			add_image(mlx_data, mlx_data->img_ref.exit, i, pos_y);
			mlx_data->map_dt.x_exit = i;
			mlx_data->map_dt.y_exit = pos_y;
		}
		else if (line[i] == 'P')
			add_img_pl(mlx_data, mlx_data->img_ref.pl_r, i, pos_y);
		else if (line[i] == 'C')
			add_image(mlx_data, mlx_data->img_ref.loot, i, pos_y);
		i++;
	}
	free(line);
}

void	creates_images(t_mlx_dt *dt, t_map_dt *map_dt)
{
	int			size;
	size_t		pos_y;
	t_imgs_ref	i_ref;

	pos_y = 0;
	size = IMG_SIZE;
	i_ref.pl_d = mlx_xpm_file_to_image((*dt).mlx, TXT_PLAYER_D, &size, &size);
	i_ref.pl_l = mlx_xpm_file_to_image((*dt).mlx, TXT_PLAYER_L, &size, &size);
	i_ref.pl_r = mlx_xpm_file_to_image((*dt).mlx, TXT_PLAYER_R, &size, &size);
	i_ref.pl_t = mlx_xpm_file_to_image((*dt).mlx, TXT_PLAYER_T, &size, &size);
	i_ref.exit = mlx_xpm_file_to_image((*dt).mlx, TXT_EXIT, &size, &size);
	i_ref.loot = mlx_xpm_file_to_image((*dt).mlx, TXT_LOOT, &size, &size);
	i_ref.path = mlx_xpm_file_to_image((*dt).mlx, TXT_PATH, &size, &size);
	i_ref.wall = mlx_xpm_file_to_image((*dt).mlx, TXT_WALL, &size, &size);
	dt->img_ref = i_ref;
	while ((*map_dt).map[pos_y])
	{
		manage_line(dt, map_dt, pos_y);
		pos_y++;
	}
	display_move(dt);
}

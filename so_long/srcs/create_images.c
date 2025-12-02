/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:06:39 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/02 11:18:02 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	add_img_pl(t_mlx_data *mlx_data, char *txt, int pos_x, int pos_y)
{
	long			x_calc;
	long			y_calc;
	t_player_data 	*tmp;
	size_t			tmp_nb_move;
	size_t			tmp_nb_loot;

	tmp = ft_calloc(1, sizeof(t_player_data));
	tmp->size = IMG_SIZE;
	tmp->pos_x = pos_x;
	tmp->pos_y = pos_y;
	tmp_nb_move = 0;
	tmp_nb_loot = 0;
	if (mlx_data->player != NULL)
	{
		tmp_nb_move = mlx_data->player->nb_move;
		tmp_nb_loot = mlx_data->player->loot_collected;
		free(mlx_data->player);
	}
	tmp->nb_move = tmp_nb_move;
	tmp->loot_collected = tmp_nb_loot;
	tmp->img = mlx_new_image_from_file((*mlx_data).mlx, txt, &tmp->size, &tmp->size);
	(*mlx_data).player = tmp;
	x_calc = tmp->pos_x * tmp->size;
	y_calc = tmp->pos_y * tmp->size;
	mlx_put_image_to_window((*mlx_data).mlx, (*mlx_data).win, tmp->img, x_calc, y_calc);
}

void	add_img_lt(t_mlx_data *mlx_data, char *txt, int pos_x, int pos_y)
{
	t_img_data **loots;
	long int x_calc;
	long int y_calc;
	t_img_data *tmp;
	t_img_data *img_last;

	loots = &(*mlx_data).loots;
	tmp = ft_calloc(1, sizeof(t_img_data));
	tmp->size = IMG_SIZE;
	tmp->pos_x = pos_x;
	tmp->pos_y = pos_y;
	tmp->img = mlx_new_image_from_file((*mlx_data).mlx, txt, &tmp->size, &tmp->size);
	tmp->img_prev = NULL;
	tmp->img_next = NULL;
	if (*loots)
	{
		img_last = sl_imgs_last(*loots);
		tmp->img_prev = img_last;
		img_last->img_next = tmp;
	}
	else
		*loots = tmp;
	x_calc = tmp->pos_x * tmp->size;
	y_calc = tmp->pos_y * tmp->size;
	mlx_put_image_to_window((*mlx_data).mlx, (*mlx_data).win, tmp->img, x_calc, y_calc);
}

void	add_image(t_mlx_data *mlx_data, char *texture, int pos_x, int pos_y)
{
	t_img_data **imgs;
	long int x_calc;
	long int y_calc;
	t_img_data *tmp;
	t_img_data *img_last;

	imgs = &(*mlx_data).imgs;
	tmp = ft_calloc(1, sizeof(t_img_data));
	tmp->size = IMG_SIZE;
	tmp->pos_x = pos_x;
	tmp->pos_y = pos_y;
	tmp->img = mlx_new_image_from_file((*mlx_data).mlx, texture, &tmp->size, &tmp->size);
	tmp->img_prev = NULL;
	tmp->img_next = NULL;
	if (*imgs)
	{
		img_last = sl_imgs_last(*imgs);
		tmp->img_prev = img_last;
		img_last->img_next = tmp;
	}
	else
		*imgs = tmp;
	x_calc = tmp->pos_x * tmp->size;
	y_calc = tmp->pos_y * tmp->size;
	mlx_put_image_to_window((*mlx_data).mlx, (*mlx_data).win, tmp->img, x_calc, y_calc);
}

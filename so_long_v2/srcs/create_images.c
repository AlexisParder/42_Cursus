/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:06:39 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/05 12:55:38 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	add_img_pl(t_mlx_data *dt, mlx_image img, int pos_x, int pos_y)
{
	long			x_calc;
	long			y_calc;
	t_player_data	*tmp;
	size_t			tmp_nb_move;
	size_t			tmp_nb_loot;

	tmp = ft_calloc(1, sizeof(t_player_data));
	tmp->size = IMG_SIZE;
	tmp->pos_x = pos_x;
	tmp->pos_y = pos_y;
	tmp_nb_move = 0;
	tmp_nb_loot = 0;
	if (dt->player != NULL)
	{
		tmp_nb_move = dt->player->nb_move;
		tmp_nb_loot = dt->player->loot_collected;
		free(dt->player);
	}
	tmp->nb_move = tmp_nb_move;
	tmp->loot_collected = tmp_nb_loot;
	// tmp->img = img;
	(*dt).player = tmp;
	x_calc = tmp->pos_x * tmp->size;
	y_calc = tmp->pos_y * tmp->size;
	mlx_put_image_to_window((*dt).mlx, (*dt).win, img, x_calc, y_calc);
}

void	add_img_lt(t_mlx_data *dt, mlx_image img, int pos_x, int pos_y)
{
	t_img_data	**loots;
	long		x_calc;
	long		y_calc;
	t_img_data	*tmp;
	t_img_data	*img_last;

	loots = &(*dt).loots;
	tmp = ft_calloc(1, sizeof(t_img_data));
	tmp->size = IMG_SIZE;
	tmp->pos_x = pos_x;
	tmp->pos_y = pos_y;
	// tmp->img = img;
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
	mlx_put_image_to_window((*dt).mlx, (*dt).win, img, x_calc, y_calc);
}

void	add_image(t_mlx_data *dt, mlx_image img, int pos_x, int pos_y)
{
	t_img_data	**imgs;
	long		x_calc;
	long		y_calc;
	t_img_data	*tmp;
	t_img_data	*img_last;

	imgs = &(*dt).imgs;
	tmp = ft_calloc(1, sizeof(t_img_data));
	tmp->size = IMG_SIZE;
	tmp->pos_x = pos_x;
	tmp->pos_y = pos_y;
	// tmp->img = img;
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
	mlx_put_image_to_window((*dt).mlx, (*dt).win, img, x_calc, y_calc);
}

void	redraw_all_images(t_mlx_data *data)
{
	t_img_data	*tmp;
	long		x;
	long		y;
	mlx_color	bg_color;

	bg_color.rgba = 0x000000;
	mlx_clear_window(data->mlx, data->win, bg_color);
	tmp = data->imgs;
	while (tmp)
	{
		x = tmp->pos_x * tmp->size;
		y = tmp->pos_y * tmp->size;
		mlx_put_image_to_window(data->mlx, data->win, tmp->img, x, y);
		tmp = tmp->img_next;
	}
	tmp = data->loots;
	while (tmp)
	{
		x = tmp->pos_x * tmp->size;
		y = tmp->pos_y * tmp->size;
		mlx_put_image_to_window(data->mlx, data->win, tmp->img, x, y);
		tmp = tmp->img_next;
	}
}

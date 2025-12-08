/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:06:39 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/08 13:33:50 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	add_img_pl(t_mlx_dt *dt, mlx_image img, size_t pos_x, size_t pos_y)
{
	long		x_calc;
	long		y_calc;
	t_player_dt	*tmp;
	size_t		tmp_nb_move;
	size_t		tmp_nb_loot;

	tmp = ft_calloc(1, sizeof(t_player_dt));
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
	(*dt).player = tmp;
	x_calc = tmp->pos_x * tmp->size;
	y_calc = tmp->pos_y * tmp->size;
	mlx_put_image_to_window((*dt).mlx, (*dt).win, img, x_calc, y_calc);
}

void	add_img_lt(t_mlx_dt *dt, mlx_image img, size_t pos_x, size_t pos_y)
{
	t_loot_dt	**loots;
	long		x_calc;
	long		y_calc;
	t_loot_dt	*tmp;
	t_loot_dt	*loot_last;

	loots = &(*dt).loots;
	tmp = ft_calloc(1, sizeof(t_loot_dt));
	tmp->size = IMG_SIZE;
	tmp->is_looted = 0;
	tmp->pos_x = pos_x;
	tmp->pos_y = pos_y;
	tmp->loot_prev = NULL;
	tmp->loot_next = NULL;
	if (*loots)
	{
		loot_last = loots_last(*loots);
		tmp->loot_prev = loot_last;
		loot_last->loot_next = tmp;
	}
	else
		*loots = tmp;
	x_calc = tmp->pos_x * tmp->size;
	y_calc = tmp->pos_y * tmp->size;
	mlx_put_image_to_window((*dt).mlx, (*dt).win, img, x_calc, y_calc);
}

void	add_image(t_mlx_dt *dt, mlx_image img, size_t pos_x, size_t pos_y)
{
	long	x_calc;
	long	y_calc;
	size_t	size;

	size = IMG_SIZE;
	x_calc = pos_x * size;
	y_calc = pos_y * size;
	mlx_put_image_to_window((*dt).mlx, (*dt).win, img, x_calc, y_calc);
}

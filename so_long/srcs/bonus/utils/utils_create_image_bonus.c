/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_create_image_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 09:21:31 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/16 11:29:57 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

static t_player_dt	*create_player(t_mlx_dt *dt, size_t pos_x, size_t pos_y)
{
	t_player_dt	*tmp;
	size_t		tmp_nb_move;
	size_t		tmp_nb_loot;
	char		tmp_direction;

	tmp = ft_calloc(1, sizeof(t_player_dt));
	if (!tmp)
		return (NULL);
	tmp->size = IMG_SIZE;
	tmp->pos_x = pos_x;
	tmp->pos_y = pos_y;
	tmp_nb_move = 0;
	tmp_nb_loot = 0;
	tmp_direction = 'r';
	if (dt->player != NULL)
	{
		tmp_nb_move = dt->player->nb_move;
		tmp_nb_loot = dt->player->loot_collected;
		tmp_direction = dt->player->direction;
		free(dt->player);
	}
	tmp->nb_move = tmp_nb_move;
	tmp->loot_collected = tmp_nb_loot;
	tmp->direction = tmp_direction;
	return (tmp);
}

int	add_img_pl(t_mlx_dt *dt, void *img, size_t pos_x, size_t pos_y)
{
	long	x_calc;
	long	y_calc;

	(*dt).player = create_player(dt, pos_x, pos_y);
	if (!(*dt).player)
		return (0);
	x_calc = (*dt).player->pos_x * (*dt).player->size;
	y_calc = ((*dt).player->pos_y + 1) * (*dt).player->size;
	mlx_put_image_to_window((*dt).mlx, (*dt).win, img, x_calc, y_calc);
	return (1);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_enemy_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:50:36 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/15 14:33:28 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

int	create_enemy(t_enemy_dt **lst, size_t pos_x, size_t pos_y)
{
	t_enemy_dt	*tmp;
	t_enemy_dt	*last;

	tmp = ft_calloc(1, sizeof(t_enemy_dt));
	if (!tmp)
		return (0);
	tmp->size = IMG_SIZE;
	tmp->pos_x = pos_x;
	tmp->pos_y = pos_y;
	tmp->direction = 'l';
	tmp->is_on_loot = 0;
	tmp->next = NULL;
	if (*lst)
	{
		last = sl_lstlast(*lst);
		last->next = tmp;
	}
	else
		*lst = tmp;
	return (1);
}

void	draw_enemies(t_mlx_dt *dt)
{
	long		x_calc;
	long		y_calc;
	t_enemy_dt	*tmp;
	void		*img;
	
	tmp = (*dt).enemy;
	while (!dt->stop_game && tmp)
	{
		img = dt->img_ref.en_l;
		if (tmp->direction == 't')
			img = dt->img_ref.en_t;
		else if (tmp->direction == 'r')
			img = dt->img_ref.en_r;
		else if (tmp->direction == 'd')
			img = dt->img_ref.en_d;
		x_calc = tmp->pos_x * tmp->size;
		y_calc = (tmp->pos_y + 1) * tmp->size;
		mlx_put_image_to_window((*dt).mlx, (*dt).win, img, x_calc, y_calc);
		tmp = tmp->next;
	}
}

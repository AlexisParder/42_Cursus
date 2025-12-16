/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_enemy_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:50:36 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/16 12:44:38 by achauvie         ###   ########.fr       */
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

static void	*get_image_sprite(t_mlx_dt *dt, t_enemy_dt *enemy)
{
	void		*img;

	if (enemy->direction == 't' && dt->frame % 2 == 0)
		img = dt->img_ref.en1_t;
	else if (enemy->direction == 't' && dt->frame % 2 != 0)
		img = dt->img_ref.en2_t;
	else if (enemy->direction == 'd' && dt->frame % 2 == 0)
		img = dt->img_ref.en1_d;
	else if (enemy->direction == 'd' && dt->frame % 2 != 0)
		img = dt->img_ref.en2_d;
	else if (enemy->direction == 'r' && dt->frame % 2 == 0)
		img = dt->img_ref.en1_r;
	else if (enemy->direction == 'r' && dt->frame % 2 != 0)
		img = dt->img_ref.en2_r;
	else
	{
		if (dt->frame % 2 == 0)
			img = dt->img_ref.en1_l;
		else
			img = dt->img_ref.en2_l;
	}
	return (img);
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
		img = get_image_sprite(dt, tmp);
		x_calc = tmp->pos_x * tmp->size;
		y_calc = (tmp->pos_y + 1) * tmp->size;
		mlx_put_image_to_window((*dt).mlx, (*dt).win, img, x_calc, y_calc);
		tmp = tmp->next;
	}
}

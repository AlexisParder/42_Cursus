/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:48:43 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/23 11:45:46 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	display_move(t_mlx_dt *dt)
{
	char	*nb_move;
	int		pos_x;
	void	*img;

	nb_move = ft_itoa(dt->player->nb_move);
	mlx_set_font(dt->mlx, dt->win, "9x15");
	if (dt->frame % 2 == 0)
		img = dt->img_ref.cnt;
	else
		img = dt->img_ref.cnt2;
	mlx_put_image_to_window(dt->mlx, dt->win, img, 0, 0);
	if (dt->player->nb_move >= 100)
		pos_x = 45;
	else if (dt->player->nb_move >= 10)
		pos_x = 50;
	else
		pos_x = 55;
	mlx_string_put(dt->mlx, dt->win, pos_x, 36, 0xFFFFFF, nb_move);
	free(nb_move);
}

static void	fill_background(t_mlx_dt *dt)
{
	int	x;
	int	y;

	y = 0;
	while (y < dt->h)
	{
		x = 0;
		while (x < dt->w)
		{
			mlx_put_image_to_window(dt->mlx, dt->win, dt->img_ref.path, x, y);
			x += IMG_SIZE;
		}
		y += IMG_SIZE;
	}
}

void	display_lose(t_mlx_dt *dt)
{
	int		x;
	int		y;

	dt->stop_game = 1;
	mlx_clear_window(dt->mlx, dt->win);
	fill_background(dt);
	x = (dt->w / 2) - (1024 / 2);
	y = (dt->h / 2) - (490 / 2);
	mlx_put_image_to_window(dt->mlx, dt->win, dt->img_ref.lose, x, y);
}

void	display_win(t_mlx_dt *dt)
{
	int		x;
	int		y;

	dt->stop_game = 1;
	mlx_clear_window(dt->mlx, dt->win);
	fill_background(dt);
	x = (dt->w / 2) - (1024 / 2);
	y = (dt->h / 2) - (495 / 2);
	mlx_put_image_to_window(dt->mlx, dt->win, dt->img_ref.win, x, y);
}

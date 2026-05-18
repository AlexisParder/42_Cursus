/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cache_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:10:49 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/06 14:01:28 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static void	cache_pixels(t_data *dt, t_img_dt *img)
{
	int	x;
	int	y;

	if (!img->tex)
		return ;
	img->pixels = ft_calloc(img->w * img->h, sizeof(uint32_t));
	if (!img->pixels)
	{
		ft_dprintf(2, "Error\nFailure during allocation\n");
		close_game(dt, EXIT_FAILURE);
	}
	y = 0;
	while (y < img->h)
	{
		x = 0;
		while (x < img->w)
		{
			img->pixels[y * img->w + x] = mlx_get_image_pixel(dt->mlx,
					img->tex, x, y).rgba;
			x++;
		}
		y++;
	}
}

void	cache_imgs(t_data *dt)
{
	cache_pixels(dt, &dt->imgs.wall_n);
	cache_pixels(dt, &dt->imgs.wall_s);
	cache_pixels(dt, &dt->imgs.wall_e);
	cache_pixels(dt, &dt->imgs.wall_w);
	if (dt->has_door)
	{
		cache_pixels(dt, &dt->imgs.door_c);
		cache_pixels(dt, &dt->imgs.door_o);
	}
}

void	cache_sprites(t_data *dt)
{
	cache_pixels(dt, &dt->imgs.fl_on);
	cache_pixels(dt, &dt->imgs.fl_off);
	cache_pixels(dt, &dt->imgs.rec_on);
	cache_pixels(dt, &dt->imgs.rec_off);
	cache_pixels(dt, &dt->imgs.b_0);
	cache_pixels(dt, &dt->imgs.b_1);
	cache_pixels(dt, &dt->imgs.b_2);
	cache_pixels(dt, &dt->imgs.b_3);
	cache_pixels(dt, &dt->imgs.b_4);
	cache_pixels(dt, &dt->imgs.b_5);
}

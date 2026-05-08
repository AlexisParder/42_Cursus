/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:30:32 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/04 15:48:05 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	check_transparency(t_data *dt, t_img_dt *img)
{
	int			x;
	int			y;
	mlx_color	color;

	img->has_transparency = 0;
	y = 0;
	while (y < img->h)
	{
		x = 0;
		while (x < img->w)
		{
			color = mlx_get_image_pixel(dt->mlx, img->tex, x, y);
			if (color.a == 0)
			{
				img->has_transparency = 1;
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	create_imgs(t_data *dt)
{
	dt->imgs.wall_n.tex = mlx_new_image_from_file(dt->mlx, dt->tex_n,
			&dt->imgs.wall_n.w, &dt->imgs.wall_n.h);
	dt->imgs.wall_s.tex = mlx_new_image_from_file(dt->mlx, dt->tex_s,
			&dt->imgs.wall_s.w, &dt->imgs.wall_s.h);
	dt->imgs.wall_e.tex = mlx_new_image_from_file(dt->mlx, dt->tex_e,
			&dt->imgs.wall_e.w, &dt->imgs.wall_e.h);
	dt->imgs.wall_w.tex = mlx_new_image_from_file(dt->mlx, dt->tex_w,
			&dt->imgs.wall_w.w, &dt->imgs.wall_w.h);
	check_transparency(dt, &dt->imgs.wall_n);
	check_transparency(dt, &dt->imgs.wall_s);
	check_transparency(dt, &dt->imgs.wall_e);
	check_transparency(dt, &dt->imgs.wall_w);
	if (dt->has_door)
	{
		dt->imgs.door_c.tex = mlx_new_image_from_file(dt->mlx, dt->tex_dc,
				&dt->imgs.door_c.w, &dt->imgs.door_c.h);
		dt->imgs.door_o.tex = mlx_new_image_from_file(dt->mlx, dt->tex_do,
				&dt->imgs.door_o.w, &dt->imgs.door_o.h);
		check_transparency(dt, &dt->imgs.door_c);
		check_transparency(dt, &dt->imgs.door_o);
	}
	cache_imgs(dt);
}

int	file_exists(const char *path, int print_err)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		if (print_err)
			ft_dprintf(2, "Error\nTexture file (%s) not found.\n", path);
		return (0);
	}
	close(fd);
	return (1);
}

static void	check_door_file(t_data *dt)
{
	if (dt->has_door && !file_exists(dt->tex_dc, 0))
	{
		if (!dt->tex_dc)
			ft_dprintf(2, "Error\nDoor texture file not found.\n");
		else
			ft_dprintf(2, "Error\nTexture file (%s) not found.\n", dt->tex_dc);
		close_game(dt, EXIT_FAILURE);
	}
	if (dt->has_door && !file_exists(dt->tex_do, 0))
	{
		if (!dt->tex_do)
			ft_dprintf(2, "Error\nDoor texture file not found.\n");
		else
			ft_dprintf(2, "Error\nTexture file (%s) not found.\n", dt->tex_do);
		close_game(dt, EXIT_FAILURE);
	}
}

void	init_imgs(t_data *dt)
{
	dt->global_img = mlx_new_image(dt->mlx, dt->win_w, dt->win_h);
	if (!file_exists(dt->tex_n, 1) || !file_exists(dt->tex_s, 1)
		|| !file_exists(dt->tex_e, 1) || !file_exists(dt->tex_w, 1))
		close_game(dt, EXIT_FAILURE);
	check_door_file(dt);
	create_imgs(dt);
	if (dt->imgs.wall_n.tex == MLX_NULL_HANDLE)
		ft_dprintf(2, "Error\nFailure dring creation of NORTH image.\n");
	if (dt->imgs.wall_s.tex == MLX_NULL_HANDLE)
		ft_dprintf(2, "Error\nFailure dring creation of SOUTH image.\n");
	if (dt->imgs.wall_e.tex == MLX_NULL_HANDLE)
		ft_dprintf(2, "Error\nFailure dring creation of EAST image.\n");
	if (dt->imgs.wall_w.tex == MLX_NULL_HANDLE)
		ft_dprintf(2, "Error\nFailure dring creation of WEST image.\n");
	if (dt->has_door && dt->imgs.door_c.tex == MLX_NULL_HANDLE)
		ft_dprintf(2, "Error\nFailure dring creation of CLOSED DOOR image.\n");
	if (dt->has_door && dt->imgs.door_o.tex == MLX_NULL_HANDLE)
		ft_dprintf(2, "Error\nFailure dring creation of OPENED DOOR image.\n");
	if (dt->imgs.wall_n.tex == MLX_NULL_HANDLE
		|| dt->imgs.wall_s.tex == MLX_NULL_HANDLE
		|| dt->imgs.wall_e.tex == MLX_NULL_HANDLE
		|| dt->imgs.wall_w.tex == MLX_NULL_HANDLE
		|| (dt->has_door && dt->imgs.door_c.tex == MLX_NULL_HANDLE)
		|| (dt->has_door && dt->imgs.door_o.tex == MLX_NULL_HANDLE))
		close_game(dt, EXIT_FAILURE);
}

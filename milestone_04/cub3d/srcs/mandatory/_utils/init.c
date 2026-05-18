/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 09:30:35 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/24 14:09:16 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_window(t_data *data)
{
	mlx_window_create_info	window_info;

	ft_memset(&window_info, 0, sizeof(mlx_window_create_info));
	window_info.title = "UNDEFINED cub3d";
	window_info.width = data->win_w;
	window_info.height = data->win_h;
	data->framebuffer = malloc(sizeof(mlx_color) * data->win_w * data->win_h);
	if (!data->framebuffer)
	{
		ft_dprintf(2, "Error\nFailure during allocation\n");
		close_game(data, EXIT_FAILURE);
	}
	data->win = mlx_new_window(data->mlx, &window_info);
	if (!data->win)
	{
		ft_dprintf(2, "Error\nFailure during window creation\n");
		close_game(data, EXIT_FAILURE);
	}
	data->redraw = 1;
	ft_memset(data->keys, 0, 512);
	ft_memset(data->old_keys, 0, 512);
}

void	init_data(t_data *data)
{
	ft_bzero(&data->imgs.wall_n, sizeof(t_img_dt));
	ft_bzero(&data->imgs.wall_s, sizeof(t_img_dt));
	ft_bzero(&data->imgs.wall_e, sizeof(t_img_dt));
	ft_bzero(&data->imgs.wall_w, sizeof(t_img_dt));
	ft_bzero(&data->imgs, sizeof(t_imgs_ref));
	data->tex_n = NULL;
	data->tex_s = NULL;
	data->tex_e = NULL;
	data->tex_w = NULL;
	data->map = NULL;
	data->win_w = WINDOW_WIDTH;
	data->win_h = WINDOW_HEIGHT;
	data->win = NULL;
	data->mlx = NULL;
	if (FOV < 50 || FOV > 130)
		data->fov = 90;
	else
		data->fov = FOV;
	data->framebuffer = NULL;
}

static int	file_exists(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_dprintf(2, "Error\nTexture file (%s) not found.\n", path);
		return (0);
	}
	close(fd);
	return (1);
}

void	init_imgs(t_data *dt)
{
	if (!file_exists(dt->tex_n) || !file_exists(dt->tex_s)
		|| !file_exists(dt->tex_e) || !file_exists(dt->tex_w))
		close_game(dt, EXIT_FAILURE);
	dt->imgs.wall_n.tex = mlx_new_image_from_file(dt->mlx, dt->tex_n,
			&dt->imgs.wall_n.w, &dt->imgs.wall_n.h);
	dt->imgs.wall_s.tex = mlx_new_image_from_file(dt->mlx, dt->tex_s,
			&dt->imgs.wall_s.w, &dt->imgs.wall_s.h);
	dt->imgs.wall_e.tex = mlx_new_image_from_file(dt->mlx, dt->tex_e,
			&dt->imgs.wall_e.w, &dt->imgs.wall_e.h);
	dt->imgs.wall_w.tex = mlx_new_image_from_file(dt->mlx, dt->tex_w,
			&dt->imgs.wall_w.w, &dt->imgs.wall_w.h);
	if (dt->imgs.wall_n.tex == MLX_NULL_HANDLE)
		ft_dprintf(2, "Error\nFailure dring creation of NORTH image.\n");
	if (dt->imgs.wall_s.tex == MLX_NULL_HANDLE)
		ft_dprintf(2, "Error\nFailure dring creation of SOUTH image.\n");
	if (dt->imgs.wall_e.tex == MLX_NULL_HANDLE)
		ft_dprintf(2, "Error\nFailure dring creation of EAST image.\n");
	if (dt->imgs.wall_w.tex == MLX_NULL_HANDLE)
		ft_dprintf(2, "Error\nFailure dring creation of WEST image.\n");
	if (dt->imgs.wall_n.tex == MLX_NULL_HANDLE
		|| dt->imgs.wall_s.tex == MLX_NULL_HANDLE
		|| dt->imgs.wall_e.tex == MLX_NULL_HANDLE
		|| dt->imgs.wall_w.tex == MLX_NULL_HANDLE)
		close_game(dt, EXIT_FAILURE);
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_dprintf(2, "Error\nFailure during mlx creation\n");
		close_game(data, EXIT_FAILURE);
	}
}

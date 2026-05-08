/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:00:00 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/06 14:28:06 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static void	init_coll_map(t_data *data, int i)
{
	size_t	j;
	char	tile;

	j = 0;
	while (j < data->map_cols)
	{
		if (!data->map[i] || j >= ft_strlen(data->map[i]))
		{
			data->coll_map[i * data->map_cols + j] = COLL_WALL;
			j++;
			continue ;
		}
		tile = data->map[i][j];
		if (tile == '1')
			data->coll_map[i * data->map_cols + j] = COLL_WALL;
		else if (tile == 'D')
			data->coll_map[i * data->map_cols + j] = COLL_DOOR_CLOSED;
		else if (tile == 'O')
			data->coll_map[i * data->map_cols + j] = COLL_DOOR_OPEN;
		else
			data->coll_map[i * data->map_cols + j] = COLL_FREE;
		j++;
	}
}

void	init_collision(t_data *dt)
{
	size_t	i;

	dt->coll_map = ft_calloc(dt->map_rows * dt->map_cols, sizeof(uint8_t));
	if (!dt->coll_map)
	{
		ft_dprintf(2, "Error\nFailure during collision map allocation\n");
		close_game(dt, EXIT_FAILURE);
	}
	i = 0;
	while (i < dt->map_rows)
	{
		init_coll_map(dt, i);
		i++;
	}
}

void	update_collision_tile(t_data *data, int x, int y)
{
	char	tile;

	tile = data->map[y][x];
	if (tile == 'D')
		data->coll_map[y * data->map_cols + x] = COLL_DOOR_CLOSED;
	else if (tile == 'O')
		data->coll_map[y * data->map_cols + x] = COLL_DOOR_OPEN;
	else if (tile == '1')
		data->coll_map[y * data->map_cols + x] = COLL_WALL;
	else
		data->coll_map[y * data->map_cols + x] = COLL_FREE;
}

static int	door_open_blocks(t_data *data, double nx, double ny)
{
	t_img_dt	*img;
	double		frac;
	int			tex_x;
	t_vec2		door;
	uint32_t	pixel;

	img = &data->imgs.door_o;
	if (!img->pixels || img->w == 0 || img->h == 0)
		return (1);
	door.x = fabs(nx - (floor(nx) + 0.5));
	door.y = fabs(ny - (floor(ny) + 0.5));
	if (door.x > door.y)
		frac = ny - floor(ny);
	else
		frac = nx - floor(nx);
	tex_x = (int)(frac * img->w);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= img->w)
		tex_x = img->w - 1;
	pixel = img->pixels[(img->h / 2) * img->w + tex_x];
	return (((mlx_color){.rgba = pixel}).a != 0);
}

int	is_blocked(t_data *data, double nx, double ny)
{
	uint8_t	cell;

	if (nx < 0 || ny < 0
		|| (size_t)nx >= data->map_cols
		|| (size_t)ny >= data->map_rows)
		return (1);
	if (!data->map[(int)ny] || (int)nx >= (int)ft_strlen(data->map[(int)ny]))
		return (1);
	cell = data->coll_map[(int)ny * data->map_cols + (int)nx];
	if (cell == COLL_WALL || cell == COLL_DOOR_CLOSED)
		return (1);
	if (cell == COLL_DOOR_OPEN)
		return (door_open_blocks(data, nx, ny));
	return (0);
}

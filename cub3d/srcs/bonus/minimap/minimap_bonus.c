/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 08:58:21 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/05 14:13:55 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static void	draw_minimap_border(t_data *data, t_minimap m_dt)
{
	int			i;
	mlx_color	cl;

	cl.rgba = 0xFFFFFFFF;
	i = -M_BORDER;
	while (i < M_SIZE + M_BORDER)
	{
		mlx_pixel_put(data->mlx, data->win, m_dt.ox + i,
			m_dt.oy - M_BORDER, cl);
		mlx_pixel_put(data->mlx, data->win, m_dt.ox + i,
			m_dt.oy + M_SIZE + M_BORDER, cl);
		i++;
	}
	i = -M_BORDER;
	while (i < M_SIZE + M_BORDER)
	{
		mlx_pixel_put(data->mlx, data->win, m_dt.ox - M_BORDER,
			m_dt.oy + i, cl);
		mlx_pixel_put(data->mlx, data->win,
			m_dt.ox + M_SIZE + M_BORDER, m_dt.oy + i, cl);
		i++;
	}
}

static void	draw_minimap_player(t_data *data, t_minimap m_dt)
{
	int			cx;
	int			cy;
	int			i;
	mlx_color	cl;

	cx = m_dt.ox + (int)((data->player.pos.x - m_dt.start_x) * M_CELL_SIZE);
	cy = m_dt.oy + (int)((data->player.pos.y - m_dt.start_y) * M_CELL_SIZE);
	i = -2;
	cl.rgba = 0xFF0000FF;
	while (i <= 2)
	{
		mlx_pixel_put(data->mlx, data->win, cx + i, cy - 2, cl);
		mlx_pixel_put(data->mlx, data->win, cx + i, cy - 1, cl);
		mlx_pixel_put(data->mlx, data->win, cx + i, cy, cl);
		mlx_pixel_put(data->mlx, data->win, cx + i, cy + 1, cl);
		mlx_pixel_put(data->mlx, data->win, cx + i, cy + 2, cl);
		i++;
	}
	i = 0;
	while (i < M_CELL_SIZE)
	{
		mlx_pixel_put(data->mlx, data->win, cx + (int)(data->player.dir.x * i),
			cy + (int)(data->player.dir.y * i), cl);
		i++;
	}
}

void	draw_minimap(t_data *data)
{
	t_minimap	m_dt;

	if (data->pause)
		return ;
	m_dt.ox = M_MARGIN;
	m_dt.oy = data->win_h - M_MARGIN - M_SIZE;
	draw_minimap_cells(data, &m_dt);
	if (M_BORDER > 0)
		draw_minimap_border(data, m_dt);
	draw_minimap_player(data, m_dt);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cells_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 09:46:23 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/07 16:15:50 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static mlx_color	get_color(t_data *data, t_minimap *m_dt)
{
	mlx_color	cl;
	char		c;

	cl.rgba = 0x00000000;
	if (m_dt->map_y < 0 || m_dt->map_y >= (int)data->map_rows)
		return (cl);
	if (m_dt->map_x < 0
		|| m_dt->map_x >= (int)ft_strlen(data->map[m_dt->map_y]))
		return (cl);
	c = data->map[m_dt->map_y][m_dt->map_x];
	if (ft_isspace(c) || c == '\0')
		return (cl);
	if (c == '1')
		cl.rgba = 0xFFFFFFFF;
	else
		cl.rgba = 0x333333FF;
	return (cl);
}

static void	draw_cell_pixels(t_data *data, t_minimap *m_dt, int dx, int dy)
{
	int			px;
	int			py;
	mlx_color	cl;

	py = 0;
	while (py < M_CELL_SIZE)
	{
		px = 0;
		while (px < M_CELL_SIZE)
		{
			cl = get_color(data, m_dt);
			if (cl.a != 0)
				mlx_pixel_put(data->mlx, data->win,
					m_dt->ox + dx * M_CELL_SIZE + px,
					m_dt->oy + dy * M_CELL_SIZE + py,
					cl);
			px++;
		}
		py++;
	}
}

static void	draw_cells_row(t_data *data, t_minimap *m_dt, int dy)
{
	int	dx;

	dx = 0;
	while (dx < m_dt->cells_x)
	{
		m_dt->map_x = m_dt->start_x + dx;
		m_dt->map_y = m_dt->start_y + dy;
		draw_cell_pixels(data, m_dt, dx, dy);
		dx++;
	}
}

static void	draw_bg(t_data *data, t_minimap *m_dt)
{
	int			px;
	int			py;
	mlx_color	cl;

	py = -M_BORDER;
	while (py < M_SIZE + M_BORDER)
	{
		px = -M_BORDER;
		while (px < M_SIZE + M_BORDER)
		{
			cl.rgba = 0x000000FF;
			mlx_pixel_put(data->mlx, data->win, m_dt->ox + px,
				m_dt->oy + py, cl);
			px++;
		}
		py++;
	}
}

void	draw_minimap_cells(t_data *data, t_minimap *m_dt)
{
	int	dy;

	m_dt->cells_x = M_SIZE / M_CELL_SIZE;
	m_dt->cells_y = M_SIZE / M_CELL_SIZE;
	m_dt->start_x = (int)data->player.pos.x - m_dt->cells_x / 2;
	m_dt->start_y = (int)data->player.pos.y - m_dt->cells_y / 2;
	draw_bg(data, m_dt);
	dy = 0;
	while (dy < m_dt->cells_y)
	{
		draw_cells_row(data, m_dt, dy);
		dy++;
	}
}

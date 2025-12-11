/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:34:13 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/11 13:28:38 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	redraw_line(t_mlx_dt *mlx_data, t_map_dt *map_data, size_t pos_y)
{
	size_t	i;
	char	*line;

	i = 0;
	line = ft_strdup((*map_data).map[pos_y]);
	while (line[i])
	{
		if (line[i] == '1')
			add_image(mlx_data, mlx_data->img_ref.wall, i, pos_y);
		else if (line[i] == '0')
			add_image(mlx_data, mlx_data->img_ref.path, i, pos_y);
		else if (line[i] == 'E')
			add_image(mlx_data, mlx_data->img_ref.exit, i, pos_y);
		else if (line[i] == 'P')
			updt_pl(mlx_data);
		else if (line[i] == 'C')
			add_image(mlx_data, mlx_data->img_ref.loot, i, pos_y);
		i++;
	}
	free(line);
}

void	redraw_window(t_mlx_dt *mlx_data)
{
	size_t	pos_y;

	pos_y = 0;
	while (mlx_data->map_dt.map[pos_y])
	{
		redraw_line(mlx_data, &mlx_data->map_dt, pos_y);
		pos_y++;
	}
}

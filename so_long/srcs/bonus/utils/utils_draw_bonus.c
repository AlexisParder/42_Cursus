/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:34:13 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/19 10:10:11 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

static void	redraw_line(t_mlx_dt *mlx_data, t_map_dt *map_data, size_t pos_y)
{
	size_t	i;
	char	*line;

	i = 0;
	line = ft_strdup((map_data)->map[pos_y]);
	while (line[i])
	{
		if (line[i] != 'P' && line[i] != 'H')
			add_image(mlx_data, get_image_ref(mlx_data, line[i]), i, pos_y);
		else if (line[i] == 'P')
			updt_pl(mlx_data);
		i++;
	}
	free(line);
}

void	redraw_window(t_mlx_dt *mlx_data)
{
	size_t	pos_y;

	if ((mlx_data)->stop_game)
		return ;
	pos_y = 0;
	while (mlx_data->map_dt.map[pos_y])
	{
		redraw_line(mlx_data, &mlx_data->map_dt, pos_y);
		pos_y++;
	}
	display_move(mlx_data);
}

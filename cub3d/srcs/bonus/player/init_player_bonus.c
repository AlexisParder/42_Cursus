/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 13:17:18 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/29 11:12:55 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static void	init_player_dir(t_data *data, char dir)
{
	data->player.pitch = 0.0;
	data->player.z = 0.0;
	data->player.z_vel = 0.0;
	data->player.jumping = 0;
	if (dir == 'N')
	{
		data->player.dir.x = 0;
		data->player.dir.y = -1;
	}
	else if (dir == 'E')
	{
		data->player.dir.x = 1;
		data->player.dir.y = 0;
	}
	else if (dir == 'S')
	{
		data->player.dir.x = 0;
		data->player.dir.y = 1;
	}
	else
	{
		data->player.dir.x = -1;
		data->player.dir.y = 0;
	}
}

void	init_player_plane(t_data *data, int fov)
{
	double	len;

	len = tan(fov * M_PI / 180 / 2) / 2
		* (double)data->win_w / (double)data->win_h;
	data->player.plane.x = -data->player.dir.y * len;
	data->player.plane.y = data->player.dir.x * len;
}

void	init_player(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (ft_strchr("NSEW", data->map[i][j]))
			{
				data->player.pos.x = j + 0.5;
				data->player.pos.y = i + 0.5;
				data->player.pos.z = 0;
				init_player_dir(data, data->map[i][j]);
				init_player_plane(data, data->settings.fov);
				return ;
			}
			j++;
		}
		i++;
	}
	ft_dprintf(2, "Error\nPlayer not found!\n");
	close_game(data, EXIT_FAILURE);
}

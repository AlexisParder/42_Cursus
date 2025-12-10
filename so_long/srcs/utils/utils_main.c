/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:24:37 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/10 12:34:44 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static char	*map_in_line(int fd)
{
	char	*map_tmp;
	char	*line;

	line = get_next_line(fd);
	map_tmp = NULL;
	while (line)
	{
		map_tmp = sl_strjoin(map_tmp, line);
		free(line);
		if (!map_tmp)
		{
			close(fd);
			free(map_tmp);
			return (NULL);
		}
		line = get_next_line(fd);
	}
	close(fd);
	return (map_tmp);
}

static char	**read_map(char *map_name)
{
	int		fd;
	char	*map_tmp;
	char	**map;

	if (!map_name)
	{
		perror("Error:\nInvalid map name");
		exit(EXIT_FAILURE);
	}
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		perror("Error:\nMap does not exist");
		exit(EXIT_FAILURE);
	}
	map_tmp = map_in_line(fd);
	map = ft_split(map_tmp, '\n');
	free(map_tmp);
	return (map);
}

void	create_map_dt(t_mlx_dt *mlx_data, char **av)
{
	(*mlx_data).map_dt.map = read_map(av[1]);
	(*mlx_data).map_dt.x_max = get_max_x((*mlx_data).map_dt.map);
	(*mlx_data).map_dt.y_max = get_max_y((*mlx_data).map_dt.map);
	(*mlx_data).map_dt.total_loots = get_total_loots((*mlx_data).map_dt.map);
	if (!check_map(&mlx_data->map_dt))
	{
		free((*mlx_data).map_dt.map);
		exit(EXIT_FAILURE);
	}
}

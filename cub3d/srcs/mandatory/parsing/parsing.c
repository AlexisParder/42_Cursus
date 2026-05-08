/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 10:14:58 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/07 10:23:06 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	init_split_line(char ***split_line, char *line, size_t *len,
	int *arr_len)
{
	*split_line = get_split_line(line);
	if (!*split_line)
		return ;
	if (!*split_line[0])
	{
		ft_free_arr(*split_line);
		return ;
	}
	*len = ft_strlen(*split_line[0]);
	*arr_len = ft_arr_len(*split_line);
}

static int	parse_line(t_data *data, t_parse_map *dt_parse, char *line,
	char **map)
{
	char	**split_line;
	size_t	len;
	int		arr_len;

	init_split_line(&split_line, line, &len, &arr_len);
	if (!split_line)
		return (1);
	if (!split_line[0])
		return (0);
	if ((len == 1 || len == 2))
	{
		if (arr_len == 2)
			return (!handle_param_or_color(data, dt_parse, &split_line));
		else if (arr_len > 2)
		{
			ft_dprintf(2, "Error\nInvalid format: %s", line);
			ft_free_arr(split_line);
			return (1);
		}
	}
	else if (handle_map_line(split_line, map, dt_parse))
		return (1);
	ft_free_arr(split_line);
	return (0);
}

static void	read_file(t_data *data, t_parse_map *dt_parse, int fd)
{
	char	*line;
	char	*map;

	map = NULL;
	line = get_next_line(fd);
	if (!line)
		ft_dprintf(2, "Error\nEmpty map\n");
	while (line)
	{
		if (parse_line(data, dt_parse, line, &map))
		{
			free_data_params(data);
			free_get_next_line(line, fd);
			break ;
		}
		free(line);
		line = get_next_line(fd);
	}
	if (map)
	{
		data->map = ft_split(map, '\n');
		free(map);
		if (!data->map)
			ft_dprintf(2, "Error\nFailure during allocation\n");
	}
}

void	parse_map(t_data *data, char *map_path)
{
	int			fd;
	t_parse_map	dt_parse;

	ft_bzero(&dt_parse, sizeof(t_parse_map));
	if (!map_path)
	{
		ft_dprintf(2, "Error\nInvalid map path\n");
		return ;
	}
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		ft_dprintf(2, "Error\nMap does not exist\n");
		return ;
	}
	read_file(data, &dt_parse, fd);
	close(fd);
}

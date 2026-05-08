/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:09:09 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/06 14:10:04 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	check_player(t_data *data)
{
	size_t	i;
	size_t	j;
	int		found;

	i = 0;
	found = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (ft_strchr("NSEW", data->map[i][j]))
				found++;
			j++;
		}
		i++;
	}
	if (found == 0)
		ft_dprintf(2, "Error\nPlayer not found!\n");
	if (found > 1)
		ft_dprintf(2, "Error\nMultiple player positions found!\n");
	if (found != 1)
		close_game(data, EXIT_FAILURE);
}

static int	map_cols(char **map)
{
	int	i;
	int	max;
	int	len;

	i = 0;
	max = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

static char	get_char_map(t_data *data, size_t x, size_t y)
{
	if (x >= data->map_cols || y >= data->map_rows)
		return (' ');
	if (x >= ft_strlen(data->map[y]))
		return (' ');
	return (data->map[y][x]);
}

static int	map_is_legit(t_data *data)
{
	size_t	y;
	size_t	x;
	char	c;

	y = 0;
	while (y < data->map_rows)
	{
		x = 0;
		while (x < data->map_cols)
		{
			c = get_char_map(data, x, y);
			if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				if (get_char_map(data, x + 1, y) == ' '
					|| get_char_map(data, x, y + 1) == ' '
					|| get_char_map(data, x - 1, y) == ' '
					|| get_char_map(data, x, y - 1) == ' ')
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

void	check_map(t_data *data)
{
	if (!data->map)
		close_game(data, EXIT_FAILURE);
	check_player(data);
	data->map_cols = map_cols(data->map);
	data->map_rows = ft_arr_len(data->map);
	if (!map_is_legit(data))
	{
		ft_dprintf(2, "Error\nMap is not valid\n");
		close_game(data, EXIT_FAILURE);
	}
}

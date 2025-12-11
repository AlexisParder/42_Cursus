/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:23:15 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/11 12:20:40 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static int	check_border(t_map_dt *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map->map[i])
	{
		if (i == 0 || i == map->y_max)
		{
			j = 0;
			while (map->map[i][j])
			{
				if (map->map[i][j] != '1')
					return (0);
				j++;
			}
			i++;
		}
		if (map->map[i][0] != '1' || map->map[i][map->x_max - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_type(t_map_dt *map)
{
	size_t	nb_loot;
	size_t	nb_exit;
	size_t	nb_player;

	nb_loot = count_type(map->map, "C");
	nb_exit = count_type(map->map, "E");
	nb_player = count_type(map->map, "P");
	if (nb_loot < 1)
	{
		perror("Error:\nThere must be at least one loot on the map");
		return (0);
	}
	if (nb_exit != 1)
	{
		perror("Error:\nThere should only be one exit on the map");
		return (0);
	}
	if (nb_player != 1)
	{
		perror("Error:\nThere should only be one player on the map");
		return (0);
	}
	return (1);
}

static int	check_map_fill(t_map_dt *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (!is_search(map->map[i][j], "01ECP"))
			{
				perror("Error:\nInvalid map format, authorized char: '01ECP'");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map(t_map_dt *map)
{
	if (!map || !map->map[0])
	{
		perror("Error:\nEmpty map");
		return (0);
	}
	if (map->x_max == map->y_max)
	{
		perror("Error:\nThe map is not rectangular");
		return (0);
	}
	if (!check_border(map))
	{
		perror("Error:\nThe borders are not valid.");
		return (0);
	}
	if (!check_type(map))
		return (0);
	if (!check_map_fill(map))
		return (0);
	if (!check_map_path(map))
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:23:15 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/19 11:19:31 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

static int	check_border(t_map_dt *m_dt)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (m_dt->map[i])
	{
		if (i == 0 || i == m_dt->y_max - 1)
		{
			j = 0;
			while (m_dt->map[i][j])
			{
				if (m_dt->map[i][j] != '1')
					return (0);
				j++;
			}
			i++;
		}
		if (i < m_dt->y_max - 1
			&& (m_dt->map[i][0] != '1' || m_dt->map[i][m_dt->x_max - 1] != '1'))
			return (0);
		i++;
	}
	return (1);
}

static int	check_type(t_map_dt *map_dt)
{
	size_t	nb_loot;
	size_t	nb_exit;
	size_t	nb_player;

	nb_loot = count_type(map_dt->map, "C");
	nb_exit = count_type(map_dt->map, "E");
	nb_player = count_type(map_dt->map, "P");
	if (nb_loot < 1)
	{
		ft_printf("Error\nThere must be at least one loot on the map");
		return (0);
	}
	if (nb_exit != 1)
	{
		ft_printf("Error\nThere should only be one exit on the map");
		return (0);
	}
	if (nb_player != 1)
	{
		ft_printf("Error\nThere should only be one player on the map");
		return (0);
	}
	return (1);
}

static int	check_map_fill(t_map_dt *map_dt)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map_dt->map[i])
	{
		j = 0;
		while (map_dt->map[i][j])
		{
			if (!ft_strchr("01ECPH", map_dt->map[i][j]))
			{
				ft_printf("Error\nInvalid map format, use: '01ECPH'");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_map_size(t_map_dt *map_dt)
{
	size_t	y;
	size_t	len;

	if (map_dt->x_max == map_dt->y_max)
		return (0);
	len = ft_strlen(map_dt->map[0]);
	y = 1;
	while (map_dt->map[y])
	{
		if (ft_strlen(map_dt->map[y]) != len)
			return (0);
		y++;
	}
	return (1);
}

int	check_map(t_map_dt *map_dt)
{
	if (!map_dt || !map_dt->map[0])
	{
		ft_printf("Error\nEmpty map");
		return (0);
	}
	if (!check_map_size(map_dt))
	{
		ft_printf("Error\nThe map is not rectangular");
		return (0);
	}
	if (!check_border(map_dt))
	{
		ft_printf("Error\nThe borders are not valid.");
		return (0);
	}
	if (!check_type(map_dt))
		return (0);
	if (!check_map_fill(map_dt))
		return (0);
	if (!check_map_path(map_dt))
		return (0);
	return (1);
}

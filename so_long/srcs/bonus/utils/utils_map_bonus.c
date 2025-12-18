/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 09:13:49 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/18 16:35:53 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

size_t	get_max_x(char **map)
{
	size_t	i;
	size_t	j;
	size_t	tmp_j;

	i = 0;
	tmp_j = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (tmp_j < j)
			tmp_j = j;
		i++;
	}
	return (j);
}

size_t	get_max_y(char **map)
{
	size_t	i;

	i = 0;
	while (map && map[i])
		i++;
	return (i);
}

size_t	get_total_loots(char **map)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	count = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

size_t	count_type(char **map, char *search)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	count = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr(search, map[i][j]))
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

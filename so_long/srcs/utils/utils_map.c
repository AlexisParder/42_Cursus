/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 09:13:49 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/01 09:21:20 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

size_t	get_max_x(char **map)
{
	size_t	i;
	size_t	j;
	size_t	tmp_j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
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
	while (map[i])
		i++;
	return (i);
}
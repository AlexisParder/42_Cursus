/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_map_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 09:22:18 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/10 13:10:05 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	**duplicate_map(t_map_dt *map)
{
	char	**copy;
	size_t	i;

	copy = ft_calloc(map->y_max + 1, sizeof(char *));
	if (!copy)
	{
		perror("Error\nFailure during allocation");
		return (NULL);
	}
	i = 0;
	while (map->map[i])
	{
		copy[i] = ft_strdup(map->map[i]);
		if (!copy[i])
		{
			perror("Error\nFailure during allocation");
			free_arr(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	flood_fill(long x, long y, t_map_ck *map_cp)
{
	if (x < 0 || y < 0 || !map_cp || !map_cp->map[y] || !map_cp->map[y][x])
		return ;
	if (map_cp->map[y][x] == '1' || map_cp->map[y][x] == 'V')
		return ;
	if (map_cp->map[y][x] == 'E')
		map_cp->exit_found = 1;
	if (map_cp->map[y][x] == 'C')
		map_cp->loot_found++;
	map_cp->map[y][x] = 'V';
	flood_fill(x + 1, y, map_cp);
	flood_fill(x - 1, y, map_cp);
	flood_fill(x, y + 1, map_cp);
	flood_fill(x, y - 1, map_cp);
}

static t_player_dt	*check_player(t_map_ck *map_ref)
{
	size_t		i;
	size_t		j;
	t_player_dt	*tmp_player;

	i = 0;
	while (map_ref->map[i])
	{
		j = 0;
		while (map_ref->map[i][j])
		{
			if (map_ref->map[i][j] == 'P')
			{
				tmp_player = ft_calloc(1, sizeof(t_player_dt));
				if (!tmp_player)
					return (NULL);
				tmp_player->pos_x = j;
				tmp_player->pos_y = i;
				return (tmp_player);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

int	check_map_path(t_map_dt *map)
{
	t_map_ck	map_copy;
	t_player_dt	*player;

	map_copy.map = duplicate_map(map);
	map_copy.exit_found = 0;
	map_copy.loot_found = 0;
	player = check_player(&map_copy);
	if (!player)
	{
		perror("Error\nNo player found");
		free_arr(map_copy.map);
		return (0);
	}
	flood_fill(player->pos_x, player->pos_y, &map_copy);
	free_arr(map_copy.map);
	if (!map_copy.exit_found)
		perror("Error\nNo valid path to exit");
	else if (map_copy.loot_found != map->total_loots)
		perror("Error\nCan't reach all loot");
	free(player);
	if (!map_copy.exit_found || map_copy.loot_found != map->total_loots)
		return (0);
	return (1);
}

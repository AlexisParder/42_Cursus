/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_loot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:32:13 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/08 13:40:58 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_loot_dt	*loot_at_pos(t_loot_dt **loots, size_t pos_x, size_t pos_y)
{
	if (!loots)
		return (NULL);
	while (*loots)
	{
		if ((*loots)->pos_x == pos_x && (*loots)->pos_y == pos_y)
			return (*loots);
		*loots = (*loots)->loot_next;
	}
	return (NULL);
}

int	is_area_loot(t_loot_dt *loots, size_t pos_x, size_t pos_y)
{
	t_loot_dt	*loot_pos;

	loot_pos = loot_at_pos(&loots, pos_x, pos_y);
	if (loot_pos)
		return (1);
	return (0);
}

int	can_loot(t_loot_dt *loots, size_t pos_x, size_t pos_y)
{
	t_loot_dt	*loot_pos;

	loot_pos = loot_at_pos(&loots, pos_x, pos_y);
	if (!loot_pos || loot_pos->is_looted)
		return (0);
	return (1);
}

void	take_loot(t_loot_dt *loots, size_t pos_x, size_t pos_y)
{
	t_loot_dt	*loot_pos;

	loot_pos = loot_at_pos(&loots, pos_x, pos_y);
	if (!loot_pos)
		return ;
	loot_pos->is_looted = 1;
}

void	free_loots(t_loot_dt **loots)
{
	t_loot_dt	*tmp;

	if (!loots)
		return ;
	while (*loots)
	{
		tmp = (*loots)->loot_next;
		free(*loots);
		*loots = tmp;
	}
	*loots = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_loot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:32:13 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/02 09:17:20 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	is_area_loot(t_img_data *lst, size_t pos_x, size_t pos_y)
{
	t_img_data	*img_at_pos;
	
	img_at_pos = sl_img_at_pos(&lst, pos_x, pos_y);
	if (img_at_pos)
		return (1);
	return (0);
}

void	remove_loot(t_img_data *lst, size_t pos_x, size_t pos_y)
{
	t_img_data	*img_at_pos;
	t_img_data	*img_at_prev;
	t_img_data	*img_at_next;
	
	img_at_pos = sl_img_at_pos(&lst, pos_x, pos_y);
	if (!img_at_pos)
		return ;
	img_at_prev = img_at_pos->img_prev;
	img_at_next = img_at_pos->img_next;
	free(img_at_pos);
	if (img_at_prev && img_at_next)
	{
		img_at_next->img_prev = img_at_prev;
		img_at_prev->img_next = img_at_next;
	}
	if (!img_at_next)
		img_at_prev->img_next = NULL;
	if (!img_at_prev)
		img_at_next->img_prev = NULL;
}

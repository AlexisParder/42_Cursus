/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_imgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:31:48 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/01 15:32:28 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_img_data	*sl_imgs_last(t_img_data *lst)
{
	while (lst != NULL && lst->img_next != NULL)
		lst = lst->img_next;
	return (lst);
}

t_img_data	*sl_img_at_pos(t_img_data **lst, size_t pos_x, size_t pos_y)
{
	if (!lst)
		return (NULL);
	while (*lst)
	{
		if ((*lst)->pos_x == pos_x && (*lst)->pos_y == pos_y)
			return (*lst);
		*lst = (*lst)->img_next;
	}
	return (NULL);
}

size_t	sl_imgs_size(t_img_data *lst)
{
	size_t	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->img_next;
		i++;
	}
	return (i);
}

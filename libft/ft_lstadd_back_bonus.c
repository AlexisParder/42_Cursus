/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:41:24 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/26 08:49:30 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;
	t_list	*lst_tmp;

	if (lst && new)
	{
		tmp = NULL;
		lst_tmp = *lst;
		while (lst_tmp)
		{
			tmp = lst_tmp;
			lst_tmp = lst_tmp->next;
		}
		if (tmp)
			tmp->next = new;
		else
			*lst = new;
	}
}

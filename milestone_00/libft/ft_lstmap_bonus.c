/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:41:57 by achauvie          #+#    #+#             */
/*   Updated: 2026/01/09 08:51:11 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;
	void	*tmp_node;

	new = NULL;
	while (lst && f && del && lst->content != NULL)
	{
		tmp_node = (*f)(lst->content);
		node = ft_lstnew(tmp_node);
		if (!node)
		{
			(*del)(tmp_node);
			ft_lstclear(&new, *del);
			return (NULL);
		}
		ft_lstadd_back(&new, node);
		lst = lst->next;
	}
	return (new);
}

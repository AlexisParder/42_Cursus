/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:15:26 by achauvie          #+#    #+#             */
/*   Updated: 2026/02/23 11:57:42 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_token	*lst_tokenlast(t_token *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

t_cmd	*lst_cmdlast(t_cmd *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

t_redirs	*lst_redirlast(t_redirs *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

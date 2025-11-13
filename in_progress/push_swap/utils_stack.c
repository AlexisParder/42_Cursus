/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:17:11 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/13 11:28:17 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ps_stacklast(t_stack *lst)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

size_t	ps_stacksize(t_stack *lst)
{
	size_t	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_stack	*fill_stack(t_stack *stack, char **tab)
{
	size_t	i;
	size_t	stack_sz;
	t_stack	*tmp;
	t_stack	*stack_last;
	
	i = 0;
	while (tab && tab[i])
	{
		tmp->index = 0; // faire une fonction pour calculer l'index
		tmp->nbr = ft_atoi(tab[i]);
		tmp->next = NULL;
		tmp->prev = NULL;
		
		if (ps_stacksize(stack) > 0)
			ps_stacklast(stack)->next = tmp;
		else
			stack = tmp;		
	}
	free(tab);
}

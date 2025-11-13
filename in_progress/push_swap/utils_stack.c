/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:17:11 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/13 17:02:23 by achauvie         ###   ########.fr       */
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

#include <stdio.h>
void	fill_stack(t_stack **stack, char **tab)
{
	size_t	i;
	size_t	stack_sz;
	t_stack	*tmp;
	t_stack	*stack_last;
	
	i = 0;
	while (tab && tab[i])
	{
		tmp = malloc(sizeof(t_stack));
		stack_sz = ps_stacksize(*stack);
		tmp->index = 0; // faire une fonction pour calculer l'index
		tmp->nbr = ft_atoi(tab[i]);
		tmp->next = NULL;
		if (stack_sz > 0)
		{
			stack_last = ps_stacklast(*stack);
			tmp->prev = stack_last;
			stack_last->next = tmp;
		}
		else
			*stack = tmp;
		i++;	
		free(tmp);
		printf("%ld\n", stack_last->nbr);	
	}
	free(tab);
}

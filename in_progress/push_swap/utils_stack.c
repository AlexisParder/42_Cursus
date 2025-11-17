/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:17:11 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/17 08:34:25 by achauvie         ###   ########.fr       */
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

void	fill_stack(t_stack **stack, char **list)
{
	size_t	i;
	size_t	stack_sz;
	t_stack	*tmp;
	t_stack	*stack_last;

	i = 0;
	while (list && list[i])
	{
		tmp = malloc(sizeof(t_stack));
		stack_sz = ps_stacksize(*stack);
		tmp->index = 0;
		tmp->nbr = ft_atoi(list[i]);
		tmp->prev = NULL;
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
	}
}

void	free_stack(t_stack *stack)
{
	while (stack)
	{
		free(stack);
		stack = stack->next;
	}
}

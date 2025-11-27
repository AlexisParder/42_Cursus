/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:17:11 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/27 15:30:28 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

int	fill_stack(t_stack **stack, char **list)
{
	size_t	i;
	t_stack	*tmp;
	t_stack	*stack_last;

	i = 0;
	while (list && list[i])
	{
		tmp = ft_calloc(1, sizeof(t_stack));
		if (!tmp)
			return (1);
		tmp->nbr = ft_atoi(list[i]);
		tmp->prev = NULL;
		tmp->next = NULL;
		if (*stack)
		{
			stack_last = ps_stacklast(*stack);
			tmp->prev = stack_last;
			stack_last->next = tmp;
		}
		else
			*stack = tmp;
		i++;
	}
	return (0);
}

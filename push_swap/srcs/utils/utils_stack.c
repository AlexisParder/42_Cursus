/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:17:11 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/26 10:02:43 by achauvie         ###   ########.fr       */
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

void	free_stack(t_stack **stack, int exit_program)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	if (exit_program)
		exit(EXIT_FAILURE);
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
		if (!tmp)
			return ;
		stack_sz = ps_stacksize(*stack);
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

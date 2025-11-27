/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:21:41 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/27 14:03:39 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (b && *b)
	{
		tmp = *b;
		*b = (*b)->next;
		if (*b)
			(*b)->prev = NULL;
		tmp->next = *a;
		if (*a)
			(*a)->prev = tmp;
		tmp->prev = NULL;
		*a = tmp;
		ft_printf("pa\n");
	}
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (a && *a)
	{
		tmp = *a;
		*a = (*a)->next;
		if (*a)
			(*a)->prev = NULL;
		tmp->next = *b;
		if (*b)
			(*b)->prev = tmp;
		tmp->prev = NULL;
		*b = tmp;
		ft_printf("pb\n");
	}
}

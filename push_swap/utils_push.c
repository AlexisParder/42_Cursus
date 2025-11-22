/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:21:41 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/14 17:01:19 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		write(1, "pa\n", 3);
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
		write(1, "pb\n", 3);
	}
}

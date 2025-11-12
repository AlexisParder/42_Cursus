/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rotation_rev.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:01:48 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/12 16:20:07 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if (!a || !*a || !(*a)->next)
		return (0);
	first = *a;
	last = ps_lstlast(*a);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*a = last;
	return (1);
}

int	rrb(t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	if (!b || !*b || !(*b)->next)
		return (0);
	first = *b;
	last = ps_lstlast(*b);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*b = last;
	return (1);
}

int	rrr(t_stack **a, t_stack **b)
{
	int	res_rra;
	int	res_rrb;	

	res_rra = rra(a);
	res_rrb = rrb(b);
	if (res_rra == 0 && res_rrb == 0)
		return (0);
	return (1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:01:09 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/18 10:59:54 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack **a, int print)
{
	t_stack	*first;
	t_stack	*last;

	if (!a || !*a || !(*a)->next)
		return (0);
	first = *a;
	last = ps_stacklast(*a);
	*a = first->next;
	(*a)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (print)
		write(1, "ra\n", 3);
	return (1);
}

int	rb(t_stack **b, int print)
{
	t_stack	*first;
	t_stack	*last;

	if (!b || !*b || !(*b)->next)
		return (0);
	first = *b;
	last = ps_stacklast(*b);
	*b = first->next;
	(*b)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (print)
		write(1, "rb\n", 3);
	return (1);
}

void	rr(t_stack **a, t_stack **b)
{
	int	res_ra;
	int	res_rb;	

	res_ra = ra(a, 0);
	res_rb = rb(b, 0);
	if (res_ra && res_rb)
		write(1, "rr\n", 3);
}

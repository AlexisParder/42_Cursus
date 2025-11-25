/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:31:48 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/25 16:07:03 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_size_2(t_stack **a)
{
	long	nbr1;
	long	nbr2;

	nbr1 = (*a)->nbr;
	nbr2 = (*a)->next->nbr;
	if (nbr1 > nbr2)
		sa(a, 1);
}

void	sort_size_3(t_stack **a)
{
	long	nbr1;
	long	nbr2;
	long	nbr3;

	nbr1 = (*a)->nbr;
	nbr2 = (*a)->next->nbr;
	nbr3 = (*a)->next->next->nbr;
	if (nbr1 > nbr2 && nbr2 < nbr3 && nbr1 < nbr3)
		sa(a, 1);
	else if (nbr1 > nbr2 && nbr2 > nbr3)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (nbr1 > nbr2 && nbr2 < nbr3 && nbr1 > nbr3)
		ra(a, 1);
	else if (nbr1 < nbr2 && nbr2 > nbr3 && nbr1 < nbr3)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (nbr1 < nbr2 && nbr2 > nbr3 && nbr1 > nbr3)
		rra(a, 1);
}

void	sort_size_5(t_stack **a)
{
	t_stack	*b;
	size_t	size_a;
	size_t	size_b;

	b = NULL;
	pb(a, &b);
	pb(a, &b);
	size_a = ps_stacksize(*a);
	if (b->nbr < b->next->nbr)
		sb(&b, 1);
	if (size_a == 2)
		sort_size_2(a);
	else
		sort_size_3(a);
	size_b = ps_stacksize(b);
	while (size_b > 0)
	{
		fill_sorted_a(a, &b);
		size_b = ps_stacksize(b);
	}
}

void	last_sort_b(t_stack **b)
{
	size_t	size_b;
	size_t	pos_max_b;

	size_b = ps_stacksize(*b);
	pos_max_b = find_stack_max_pos(*b);
	while (pos_max_b != 0)
	{
		if (pos_max_b < size_b / 2)
			rb(b, 1);
		else
			rrb(b, 1);
		pos_max_b = find_stack_max_pos(*b);
	}
}

void	last_sort_a(t_stack **a)
{
	size_t	size_a;
	size_t	pos_min_a;

	size_a = ps_stacksize(*a);
	pos_min_a = find_stack_min_pos(*a);
	while (pos_min_a != 0)
	{
		if (pos_min_a < size_a / 2)
			ra(a, 1);
		else
			rra(a, 1);
		pos_min_a = find_stack_min_pos(*a);
	}
}

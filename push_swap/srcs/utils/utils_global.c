/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_global.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:35:26 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/28 09:09:24 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static t_stack	*find_best_target(t_stack *a, long b_val)
{
	t_stack	*target;
	t_stack	*tmp;

	tmp = a;
	target = NULL;
	while (tmp)
	{
		if (tmp->nbr > b_val)
		{
			if (!target || tmp->nbr < target->nbr)
			{
				target = tmp;
			}
		}
		tmp = tmp->next;
	}
	return (target);
}

size_t	find_insertion_target_pos(t_stack *a, long b_val)
{
	t_stack	*target;
	size_t	pos;

	if (!a)
		return (0);
	target = find_best_target(a, b_val);
	if (!target)
		pos = find_stack_min_pos(a);
	else
		pos = find_pos(target->nbr, a);
	return (pos);
}

void	fill_sorted_a(t_stack **a, t_stack **b)
{
	size_t	target_pos;
	size_t	size_a;
	long	b_val;

	if (!*b)
		return ;
	b_val = (*b)->nbr;
	size_a = ps_stacksize(*a);
	target_pos = find_insertion_target_pos(*a, b_val);
	while (target_pos != 0)
	{
		if (target_pos <= size_a / 2)
			ra(a, 1);
		else
			rra(a, 1);
		if (target_pos <= size_a / 2)
			target_pos--;
		else
			target_pos++;
		if (target_pos == size_a)
			target_pos = 0;
		size_a = ps_stacksize(*a);
	}
	pa(a, b);
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_calc_mv	*next_nbr;
	size_t		size_a;
	size_t		size_b;

	pb(a, b);
	pb(a, b);
	size_a = ps_stacksize(*a);
	size_b = ps_stacksize(*b);
	while (size_a > 3)
	{
		next_nbr = calc_move(*a, *b);
		if (!next_nbr)
			return ;
		make_moves(a, b, next_nbr);
		free(next_nbr);
		size_a = ps_stacksize(*a);
	}
	sort_size_3(a);
	last_sort_b(b);
	while (size_b > 0)
	{
		fill_sorted_a(a, b);
		size_b = ps_stacksize(*b);
	}
	last_sort_a(a);
}

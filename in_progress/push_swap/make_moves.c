/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:14:04 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/19 14:38:02 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	find_pos(long nbr_search, t_stack *stack)
{
	size_t	i;

	i = 0;
	while (stack)
	{
		if (stack->nbr == nbr_search)
			return (i);
		i++;
		stack = stack->next;
	}
	return (0);
}

static void	mk_rot_a(t_stack **a, size_t pos_a, size_t size_a)
{
	while (pos_a <= size_a / 2 && pos_a > 0)
	{
		ra(a, 1);
		pos_a--;
	}
	while (pos_a > size_a / 2 && pos_a < size_a)
	{
		rra(a, 1);
		pos_a++;
	}
}

static void	mk_rot_b(t_stack **b, size_t pos_b, size_t size_b)
{
	while (pos_b <= size_b / 2 && pos_b > 0)
	{
		rb(b, 1);
		pos_b--;
	}
	while (pos_b > size_b / 2 && pos_b < size_b)
	{
		rrb(b, 1);
		pos_b++;
	}
}

static void	mk_rots(t_stack **a, t_stack **b, t_calc_mv *next_nbr, t_stack *tmp)
{
	size_t		pos_a;
	size_t		pos_b;
	size_t		size_a;
	size_t		size_b;

	pos_a = find_pos(next_nbr->nbr, *a);
	pos_b = calc_pos_b(tmp, *b);
	size_a = ps_stacksize(*a);
	size_b = ps_stacksize(*b);
	while (pos_a <= size_a / 2 && pos_b <= size_b / 2 && pos_a > 0 && pos_b > 0)
	{
		rr(a, b);
		pos_a--;
		pos_b--;
	}
	while (pos_a > size_a / 2 && pos_b > size_b / 2
		&& pos_a < size_a && pos_b < size_b)
	{
		rrr(a, b);
		pos_a++;
		pos_b++;
	}
}

void	make_moves(t_stack **a, t_stack **b, t_calc_mv *next_nbr)
{
	size_t		pos_a;
	size_t		pos_b;
	size_t		size_a;
	size_t		size_b;
	t_stack		*tmp;

	tmp = *a;
	while (tmp && tmp->nbr != next_nbr->nbr)
		tmp = tmp->next;
	mk_rots(a, b, next_nbr, tmp);
	pos_a = find_pos(next_nbr->nbr, *a);
	pos_b = calc_pos_b(tmp, *b);
	size_a = ps_stacksize(*a);
	size_b = ps_stacksize(*b);
	mk_rot_a(a, pos_a, size_a);
	mk_rot_b(b, pos_b, size_b);
	pb(a, b);
}

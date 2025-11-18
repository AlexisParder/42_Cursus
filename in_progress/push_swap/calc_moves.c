/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 09:14:44 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/18 14:06:27 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	calc_pos_b(t_stack *a, t_stack *b)
{
	size_t		pos_b;
	long		max_in_b;
	long		min_in_b;
	t_stack		*tmp;

	max_in_b = find_stack_max_value(b);
	min_in_b = find_stack_min_value(b);
	if (a->nbr > max_in_b)
	{
		pos_b = find_stack_max_pos(b);
		return (pos_b);
	}
	else if (a->nbr < min_in_b)
	{
		pos_b = find_stack_min_pos(b);
		return (pos_b);
	}
	while (b->next)
	{
		if (b->nbr > a->nbr && b->next->nbr < a->nbr)
			return (pos_b + 1);
		pos_b++;
		b = b->next;
	}
	return (pos_b);
}

static size_t	calc_tmp_move(size_t pos, size_t size)
{
	size_t	tmp_move;

	if (pos <= size / 2)
		tmp_move = pos;
	else
		tmp_move = size - pos;
	return (tmp_move);
}

static size_t	get_mv(t_stack *a, t_stack *b, size_t pos_a, size_t pos_b)
{
	size_t		tmp_move_a;
	size_t		tmp_move_b;
	size_t		tmp_move_real;
	size_t		size_a;
	size_t		size_b;

	size_a = ps_stacksize(a);
	size_b = ps_stacksize(b);
	tmp_move_real = 1;
	tmp_move_a = calc_tmp_move(pos_a, size_a);
	tmp_move_b = calc_tmp_move(pos_b, size_b);
	if (pos_a <= size_a / 2 && pos_b <= size_b / 2)
		tmp_move_real += find_max(tmp_move_a, tmp_move_b);
	else if (pos_a > size_a / 2 && pos_b > size_b / 2)
		tmp_move_real += find_max(tmp_move_a, tmp_move_b);
	else if (pos_a <= size_a / 2 && pos_b > size_b / 2)
		tmp_move_real += tmp_move_a + tmp_move_b;
	else if (pos_a > size_a / 2 && pos_b <= size_b / 2)
		tmp_move_real += tmp_move_a + tmp_move_b;
	return (tmp_move_real);
}

t_calc_move	*calc_move(t_stack *a, t_stack *b)
{
	t_calc_move	*next_nbr;
	size_t		pos_a;
	size_t		pos_b;
	size_t		tmp_move_real;
	t_stack		*tmp_a;

	next_nbr = ft_calloc(1, sizeof(t_calc_move));
	if (!next_nbr)
		return (NULL);
	pos_a = 0;
	tmp_a = a;
	tmp_move_real = 0;
	while (tmp_a && tmp_move_real != 1)
	{
		pos_b = calc_pos_b(tmp_a, b);
		tmp_move_real = get_mv(a, b, pos_a, pos_b);
		if (pos_a == 0 || tmp_move_real < next_nbr->nbr_move)
		{
			next_nbr->nbr = tmp_a->nbr;
			next_nbr->nbr_move = tmp_move_real;
		}
		tmp_a = tmp_a->next;
		pos_a++;
	}
	return (next_nbr);
}

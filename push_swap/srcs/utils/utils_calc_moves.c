/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_calc_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 09:16:00 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/28 10:32:14 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

size_t	find_stack_max_pos(t_stack *stack)
{
	size_t	i;
	size_t	tmp_i;
	long	tmp_max;

	tmp_max = stack->nbr;
	i = 0;
	tmp_i = 0;
	while (stack)
	{
		if (stack->nbr > tmp_max)
		{
			tmp_max = stack->nbr;
			tmp_i = i;
		}
		i++;
		stack = stack->next;
	}
	return (tmp_i);
}

long	find_stack_max_value(t_stack *stack)
{
	long	tmp_max;

	tmp_max = stack->nbr;
	while (stack)
	{
		if (stack->nbr > tmp_max)
			tmp_max = stack->nbr;
		stack = stack->next;
	}
	return (tmp_max);
}

size_t	find_stack_min_pos(t_stack *stack)
{
	size_t	i;
	size_t	tmp_i;
	long	tmp_min;

	tmp_min = stack->nbr;
	i = 0;
	tmp_i = 0;
	while (stack)
	{
		if (stack->nbr < tmp_min)
		{
			tmp_min = stack->nbr;
			tmp_i = i;
		}
		i++;
		stack = stack->next;
	}
	return (tmp_i);
}

long	find_stack_min_value(t_stack *stack)
{
	long	tmp_min;

	tmp_min = stack->nbr;
	while (stack)
	{
		if (stack->nbr < tmp_min)
			tmp_min = stack->nbr;
		stack = stack->next;
	}
	return (tmp_min);
}

size_t	find_max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

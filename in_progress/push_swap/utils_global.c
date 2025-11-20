/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_global.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:35:26 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/20 16:21:04 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
#include <stdio.h>
void	debug_print_stack(t_stack *a, t_stack *b)
{
	t_stack	*current;

	current = a;
	printf("\n\nSTACK A\n");
	while (current != NULL)
	{
		printf("%ld\n", current->nbr);
		current = current->next;
	}
	current = b;
	printf("STACK B\n");
	while (current != NULL)
	{
		printf("%ld\n", current->nbr);
		current = current->next;
	}
}

/**
 * FIXME:
 * Ne fonctionne pas tout le temps
 * En moyenne, 2-3 elements sont mal placés
 * - Stack A bien triée, ordre croissant
 * - Stack B bien triée, ordre décroissant
 */
void	fill_sorted_a(t_stack **a, t_stack **b)
{
	size_t pos_max_a;
	size_t pos_min_a;
	size_t size_a;

	pos_max_a = find_stack_max_pos(*a);
	pos_min_a = find_stack_min_pos(*a);
	size_a = ps_stacksize(*a);
	if ((*a)->nbr > (*b)->nbr)
	{
		if ((*b)->nbr < find_stack_min_value(*a))
		{
			while (pos_min_a != 0)
			{
				if (pos_min_a < size_a / 2)
					ra(a, 1);
				else
					rra(a, 1);
				pos_min_a = find_stack_min_pos(*a);
			}
		}
		pa(a, b);
	}
	else
	{
		if ((*b)->nbr < find_stack_max_value(*a))
		{
			while (pos_max_a != 0)
			{
				if (pos_max_a < size_a / 2)
					ra(a, 1);
				else
					rra(a, 1);
				pos_max_a = find_stack_max_pos(*a);
			}
		}
		pa(a, b);
	}
}

static void	last_sort_b(t_stack **b)
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

void	push_swap(t_stack *a)
{
	t_stack		*b;
	t_calc_mv	*next_nbr;
	size_t		size_a;
	size_t		size_b;

	b = NULL;
	pb(&a, &b);
	pb(&a, &b);
	size_a = ps_stacksize(a);
	size_b = ps_stacksize(b);
	while (size_a > 3)
	{
		next_nbr = calc_move(a, b);
		make_moves(&a, &b, next_nbr);
		free(next_nbr);
		size_a = ps_stacksize(a);
	}
	sort_size_3(&a);
	last_sort_b(&b);
	// debug_print_stack(a, b);
	while (size_b > 0)
	{
		fill_sorted_a(&a, &b);
		size_b = ps_stacksize(b);
	}
	// debug_print_stack(a, b);
	// check_sort_a(&a);
}

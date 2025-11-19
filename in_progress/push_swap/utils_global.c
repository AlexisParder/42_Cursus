/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_global.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:35:26 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/19 16:38:28 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
#include <stdio.h>
void	debug_print_stack(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current != NULL)
	{
		printf("Nbr: %ld\n", current->nbr);
		current = current->next;
	}
}

static void	sort_size_3(t_stack **a)
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

static void	order_stack(t_stack **a, t_stack **b)
{
	size_t max_a_pos;

	max_a_pos = find_stack_max_pos(*a);
	if ((*a)->nbr > (*b)->nbr)
	{
		if ((*b)->nbr < find_stack_min_value(*a))
		{
			while (find_stack_min_pos(*a) != 0)
				rra(a, 1);
		}
		pa(a, b);
	}
	else
	{
		while (max_a_pos != 0)
		{
			rra(a, 1);
			max_a_pos = find_stack_max_pos(*a);
		}
		pa(a, b);
	}
}

// static void	check_order(t_stack **a)
// {
	
// }

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
	while (size_b > 0)
	{
		order_stack(&a, &b);
		size_b = ps_stacksize(b);
	}
	// check_order(&a);
}

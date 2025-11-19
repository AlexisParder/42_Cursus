/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_global.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:35:26 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/19 14:32:50 by achauvie         ###   ########.fr       */
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

void	push_swap(t_stack *a)
{
	t_stack		*b;
	t_calc_mv	*next_nbr;
	size_t		size_a;

	b = NULL;
	pb(&a, &b);
	pb(&a, &b);
	size_a = ps_stacksize(a);
	while (size_a > 3)
	{
		next_nbr = calc_move(a, b);
		make_moves(&a, &b, next_nbr);
		free(next_nbr);
		size_a = ps_stacksize(a);
	}
	// DEBUG
	ft_printf("\n\nSTACK A\n");
	debug_print_stack(a);
	ft_printf("STACK B\n");
	debug_print_stack(b);
	// 
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_global.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:35:26 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/18 10:23:52 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	make_moves(t_stack **a, t_stack **b, t_calc_move *next_nbr)
{
	// if (pos_a <= size_a / 2 && pos_b <= size_b / 2)
	// 	tmp_move_real += find_max(tmp_move_a, tmp_move_b); // faire rr
	// else if (pos_a > size_a / 2 && pos_b > size_b / 2)
	// 	tmp_move_real += find_max(tmp_move_a, tmp_move_b); // faire rrr
	// else if (pos_a <= size_a / 2 && pos_b > size_b / 2)
	// 	tmp_move_real += tmp_move_a + tmp_move_b; // faire ra et rrb
	// else if (pos_a > size_a / 2 && pos_b <= size_b / 2)
	// 	tmp_move_real += tmp_move_a + tmp_move_b; // faire rra et rb
	// return (tmp_move_real);
}

#include <stdio.h>
void	debug_print_stack(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current != NULL)
	{
		// printf("Nbr: %ld, Index: %ld\n", current->nbr, current->index);
		printf("Nbr: %ld\n", current->nbr);
		current = current->next;
	}
}

void	push_swap(t_stack *a)
{
	t_stack	*b;
	t_calc_move	*next_nbr;
	size_t	count_move;

	b = NULL;
	pb(&a, &b);
	pb(&a, &b);
	// while (ps_stacksize(a) > 3)
	// {
		next_nbr = calc_move(a, b);
		printf("\n\n\nBest move\nnbr: %ld\nnbr move: %ld", next_nbr->nbr, next_nbr->nbr_move);
		// make_moves(&a, &b, next_nbr);
		free(next_nbr);
	// }
	// ft_printf("\n\nSTACK A\n");
	// debug_print_stack(a);
	// ft_printf("STACK B\n");
	// debug_print_stack(b);
}

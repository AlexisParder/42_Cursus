/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_global.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:35:26 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/18 15:06:39 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

size_t	find_pos(t_stack *stack, long nbr_search)
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

void	make_moves(t_stack **a, t_stack **b, t_calc_move *next_nbr)
{
	size_t		pos_a;
	size_t		pos_b;
	size_t		size_a;
	size_t		size_b;
	t_stack		*tmp;

	tmp = *a;
	while (tmp && tmp->nbr != next_nbr->nbr)
		tmp = tmp->next;
	pos_a = find_pos(*a, next_nbr->nbr);
	pos_b = calc_pos_b(&tmp, *b);
	size_a = ps_stacksize(*a);
	size_b = ps_stacksize(*b);
	while (pos_a <= size_a/2 && pos_b <= size_b/2 && pos_a > 0 && pos_b > 0)
    {
        rr(a, b);
        pos_a--;
        pos_b--;
    }
    while (pos_a > size_a/2 && pos_b > size_b/2 &&
           pos_a < size_a && pos_b < size_b)
    {
        rrr(a, b);
        pos_a++;
        pos_b++;
    }
    // ROTATIONS INDIVIDUELLES A
    while (pos_a <= size_a/2 && pos_a > 0)
    {
        ra(a, 1);
        pos_a--;
    }
    while (pos_a > size_a/2 && pos_a < size_a)
    {
        rra(a, 1);
        pos_a++;
    }
    // ROTATIONS INDIVIDUELLES B
    while (pos_b <= size_b/2 && pos_b > 0)
    {
        rb(b, 1);
        pos_b--;
    }
    while (pos_b > size_b/2 && pos_b < size_b)
    {
        rrb(b, 1);
        pos_b++;
    }
    pb(a, b);
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
	size_t	size_a;

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
		// DEBUG
		// ft_printf("\n\nSTACK A\n");
		// debug_print_stack(a);
		// ft_printf("STACK B\n");
		// debug_print_stack(b);
		// 
	}
	// DEBUG
	ft_printf("\n\nAPRES WHILE\nSTACK A\n");
	debug_print_stack(a);
	ft_printf("STACK B\n");
	debug_print_stack(b);
	// 
}

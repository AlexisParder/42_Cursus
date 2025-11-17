/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_global.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:35:26 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/17 16:17:01 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

// static t_calc_move *calc_move(t_stack *a, t_stack *b)
// {
// 	t_calc_move	*next_nbr;
// 	size_t		tmp_nbr_move;
// 	size_t		i;
// 	t_stack		*last_nbr;

// 	i = 1;
// 	next_nbr = ft_calloc(1, sizeof(t_calc_move));
// 	if (!next_nbr)
// 		return (NULL);
// 	while (a)
// 	{
// 		tmp_nbr_move = i;
// 		last_nbr = ps_stacklast(b);
// 		if (a->nbr > b->nbr && a->nbr > last_nbr->nbr && last_nbr->nbr > b->nbr)
// 			tmp_nbr_move++;
// 		if (a->nbr < b->nbr && a->nbr < last_nbr->nbr)
// 		{
// 			if (last_nbr->nbr < b->nbr)
// 				tmp_nbr_move++;
// 			tmp_nbr_move++;
// 		}
// 		ft_printf("\n\nCALC move\nnbr: %d\nnbr move: %d", a->nbr, tmp_nbr_move);
// 		if (!a->prev || tmp_nbr_move < next_nbr->nbr_move)
// 		{
// 			next_nbr->nbr = a->nbr;
// 			next_nbr->nbr_move = tmp_nbr_move;
// 			if (tmp_nbr_move == 1)
// 				return (next_nbr);
// 		}
// 		a = a->next;
// 		i++;
// 	}
// 	return (next_nbr);
// }

static size_t	find_stack_max(t_stack *stack)
{
	size_t	i;
	size_t	tmp_i;
	size_t	tmp_max;

	tmp_max = stack->nbr;
	i = 0;
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
	return (i);
}

static size_t	find_stack_min(t_stack *stack)
{
	size_t	i;
	size_t	tmp_i;
	size_t	tmp_min;

	tmp_min = stack->nbr;
	i = 0;
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
	return (i);
}

static t_calc_move *calc_move(t_stack *a, t_stack *b)
{
	t_calc_move	*next_nbr;
	size_t		pos_a;
	size_t		pos_b;
	size_t		size_a;
	size_t		size_b;
	size_t		tmp_move_a;
	size_t		tmp_move_b;
	size_t		max_in_b;
	size_t		min_in_b;

	next_nbr = ft_calloc(1, sizeof(t_calc_move));
	if (!next_nbr)
		return (NULL);
	pos_a = 0;
	pos_b = 0;
	while (a)
	{
		max_in_b = find_stack_max(b);
		min_in_b = find_stack_min(b);
		size_a = ps_stacksize(a);
		size_b = ps_stacksize(b);
		if (pos_a <= size_a / 2)
			tmp_move_a = pos_a; // faire ra
		else
			tmp_move_a = size_a - pos_a; // faire rra
		if (a->nbr > max_in_b)
			pos_b = max_in_b;
		else if (a->nbr < min_in_b)
			pos_b = min_in_b;
		else
		{
			while (b->nbr > a->nbr && b->next->nbr < a->nbr)
				pos_b++;
		}
		if (pos_b <= size_b / 2)
			tmp_move_b = pos_b; // faire rb
		else
			tmp_move_b = size_b - pos_b; // faire rrb
		// if (pos_a == 0 || tmp_nbr_move < next_nbr->nbr_move)
		// {
		// 	next_nbr->nbr = a->nbr;
		// 	next_nbr->nbr_move = tmp_nbr_move;
		// 	if (tmp_nbr_move == 1)
		// 		break ;
		// }
		a = a->next;
		pos_a++;
	}
	return (next_nbr);
}

void	make_moves(t_stack **a, t_stack **b, t_calc_move *next_nbr)
{
	t_stack		*last_nbr;
	
	while ((*a)->nbr != next_nbr->nbr)
		*a = (*a)->next;
	last_nbr = ps_stacklast(*b);
	if ((*a)->nbr > (*b)->nbr && (*a)->nbr > last_nbr->nbr && last_nbr->nbr > (*b)->nbr)
	{
		rb(b);
		pb(a, b);
	}	
	else if ((*a)->nbr < (*b)->nbr && (*a)->nbr < last_nbr->nbr)
	{
		pb(a, b);
		if (last_nbr->nbr > (*b)->nbr)
			rb(b);
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
	size_t	count_move;

	b = NULL;
	pb(&a, &b);
	pb(&a, &b);
	while (ps_stacksize(a) > 3)
	{
		next_nbr = calc_move(a, b);
		make_moves(&a, &b, next_nbr);
		free(next_nbr);
	}
	// printf("\n\n\nBest move\nnbr: %ld\nnbr move: %ld",
	// 	next_nbr->nbr, next_nbr->nbr_move);
	ft_printf("\n\nSTACK A\n");
	debug_print_stack(a);
	ft_printf("STACK B\n");
	debug_print_stack(b);
}

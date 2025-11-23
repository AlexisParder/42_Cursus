/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_global.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:35:26 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/23 12:21:47 by alexis           ###   ########.fr       */
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

long find_best_target_val(t_stack *a, long b_val)
{
    long    target_val;
    t_stack *tmp;
    int     found_target;

    tmp = a;
    target_val = 0;
    found_target = 0;
    while (tmp)
    {
        if (tmp->nbr > b_val)
        {
            if (found_target == 0 || tmp->nbr < target_val)
            {
                target_val = tmp->nbr;
                found_target = 1;
            }
        }
        tmp = tmp->next;
    }
    if (found_target == 0)
        return (0);
    return (target_val);
}

size_t find_insertion_target_pos(t_stack *a, long b_val)
{
    long    target_val;
    size_t  pos;

    if (!a)
        return (0);
    target_val = find_best_target_val(a, b_val);
    if (target_val == 0)
        pos = find_stack_min_pos(a);
    else
        pos = find_pos(target_val, a);
    return (pos);
}

void	fill_sorted_a(t_stack **a, t_stack **b)
{
	size_t  target_pos;
    size_t  size_a;
    long    b_val;

    if (!*b)
        return;
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

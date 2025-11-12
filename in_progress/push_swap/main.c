/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:15:11 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/12 16:20:44 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void print_stack(const char *name, t_stack *stack)
{
    printf("%s: ", name);
    while (stack)
    {
        printf("%ld ", stack->nbr);
        stack = stack->next;
    }
    printf("\n");
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
    t_stack *a1 = malloc(sizeof(t_stack));
    t_stack *a2 = malloc(sizeof(t_stack));
    t_stack *a3 = malloc(sizeof(t_stack));
    t_stack *a4 = malloc(sizeof(t_stack));
    t_stack *a5 = malloc(sizeof(t_stack));

    a1->nbr = 1; a1->index = 1; a1->prev = NULL; a1->next = a2;
    a2->nbr = 2; a2->index = 2; a2->prev = a1;   a2->next = a3;
    a3->nbr = 3; a3->index = 3; a3->prev = a2;   a3->next = a4;
    a4->nbr = 4; a4->index = 4; a4->prev = a3;   a4->next = a5;
    a5->nbr = 5; a5->index = 5; a5->prev = a4;   a5->next = NULL;

    t_stack *a = a1;

    t_stack *b1 = malloc(sizeof(t_stack));
    t_stack *b2 = malloc(sizeof(t_stack));
    t_stack *b3 = malloc(sizeof(t_stack));
    t_stack *b4 = malloc(sizeof(t_stack));
    t_stack *b5 = malloc(sizeof(t_stack));

    b1->nbr = 6;  b1->index = 6;  b1->prev = NULL; b1->next = b2;
    b2->nbr = 7;  b2->index = 7;  b2->prev = b1;   b2->next = b3;
    b3->nbr = 8;  b3->index = 8;  b3->prev = b2;   b3->next = b4;
    b4->nbr = 9;  b4->index = 9;  b4->prev = b3;   b4->next = b5;
    b5->nbr = 10; b5->index = 10; b5->prev = b4;   b5->next = NULL;

    t_stack *b = b1;

    ft_printf("Init:\n");
    print_stack("a", a);
    print_stack("b", b);

    // pa(&a, &b);
    rrr(&a, &b);

    ft_printf("\nRA\n");
    print_stack("a", a);
    print_stack("b", b);

	// int	*a;
	// int	*b;

	// if (ac > 1)
	// {
	// 	ac--;
	// 	a = ft_calloc(ac, sizeof(int));
	// 	if (!a || !check_list(a, ac, av))
	// 	{
	// 		ft_printf("Error\n");
	// 		return (1);
	// 	}
	// 	// b = push_swap(a);
	// }
	// else
	// {
	// 	ft_printf("Error\n");
	// 	return (1);
	// }
	// return (0);
}

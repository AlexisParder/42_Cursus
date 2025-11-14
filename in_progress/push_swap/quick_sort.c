/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:43:53 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/14 14:04:45 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	quick_sort(long *list, int left, int right)
{
	size_t		i;
	size_t		j;
	long	k;
	long	tmp;

	if (left >= right)
		return ;
	i = left;
	j = right;
	k = list[(left + right) / 2];
	while (i <= j)
	{
		while (list[i] < k)
			i++;
		while (list[j] > k)
			j--;
		if (i <= j)
		{
			tmp = list[i];
			list[i++] = list[j];
			list[j--] = tmp;
		}
	}
	quick_sort(list, left, j);
	quick_sort(list, i, right);
}

static long	*calc_index(t_stack *stack, size_t stack_size)
{
	size_t	i;
	long	*list_tmp;

	list_tmp = malloc(stack_size * sizeof(long int));
	if (!list_tmp)
	{
		free_stack(stack);
		ft_error();	
	}
	i = 0;
	while (i < stack_size)
	{
		list_tmp[i] = stack->nbr;
		stack = stack->next;
		i++;
	}
	quick_sort(list_tmp, 0, stack_size - 1);
	return(list_tmp);
}

void	assign_index(t_stack *stack)
{
	size_t	i;
	size_t	stack_size;
	long	*list_tmp;
	
	stack_size = ps_stacksize(stack);
	if (stack_size > 1)
	{
		list_tmp = calc_index(stack, stack_size);
		while (stack)
		{
			i = 0;
			while (i < stack_size && list_tmp[i] != stack->nbr)
				i++;
			stack->index = i;
			stack = stack->next;
		}
		free(list_tmp);
	}
}

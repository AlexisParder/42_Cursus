/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:16:42 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/18 11:03:19 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack **a, int print)
{
	t_stack	*first;
	t_stack	*second;
	long	tmp_nbr;
	int		tmp_index;

	if (!a || !*a || !(*a)->next)
		return (0);
	first = *a;
	second = first->next;
	tmp_nbr = first->nbr;
	tmp_index = first->index;
	first->nbr = second->nbr;
	first->index = second->index;
	second->nbr = tmp_nbr;
	second->index = tmp_index;
	if (print)
		write(1, "sa\n", 3);
	return (1);
}

int	sb(t_stack **b, int print)
{
	t_stack	*first;
	t_stack	*second;
	long	tmp_nbr;
	int		tmp_index;

	if (!b || !*b || !(*b)->next)
		return (0);
	first = *b;
	second = first->next;
	tmp_nbr = first->nbr;
	tmp_index = first->index;
	first->nbr = second->nbr;
	first->index = second->index;
	second->nbr = tmp_nbr;
	second->index = tmp_index;
	if (print)
		write(1, "sb\n", 3);
	return (1);
}

void	ss(t_stack **a, t_stack **b)
{
	int	res_sa;
	int	res_sb;

	res_sa = sa(a, 0);
	res_sb = sb(b, 0);
	if (res_sa && res_sb)
		write(1, "ss\n", 3);
}

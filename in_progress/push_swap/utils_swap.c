/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:16:42 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/12 13:35:34 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack **a)
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
	return (1);
}

int	sb(t_stack **b)
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
	return (1);
}

int	ss(t_stack **a, t_stack **b)
{
	int	res_sa;
	int	res_sb;
	
	res_sa = sa(a);
	res_sb = sb(b);
	if (res_sa == 0 && res_sb == 0)
		return (0);
	return (1);
}
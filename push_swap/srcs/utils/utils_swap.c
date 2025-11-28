/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:16:42 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/28 10:32:14 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	sa(t_stack **a, int print)
{
	t_stack	*first;
	t_stack	*second;
	long	tmp_nbr;

	if (!a || !*a || !(*a)->next)
		return (0);
	first = *a;
	second = first->next;
	tmp_nbr = first->nbr;
	first->nbr = second->nbr;
	second->nbr = tmp_nbr;
	if (print)
		ft_printf("sa\n");
	return (1);
}

int	sb(t_stack **b, int print)
{
	t_stack	*first;
	t_stack	*second;
	long	tmp_nbr;

	if (!b || !*b || !(*b)->next)
		return (0);
	first = *b;
	second = first->next;
	tmp_nbr = first->nbr;
	first->nbr = second->nbr;
	second->nbr = tmp_nbr;
	if (print)
		ft_printf("sb\n");
	return (1);
}

void	ss(t_stack **a, t_stack **b)
{
	int	res_sa;
	int	res_sb;

	res_sa = sa(a, 0);
	res_sb = sb(b, 0);
	if (res_sa && res_sb)
		ft_printf("ss\n");
}

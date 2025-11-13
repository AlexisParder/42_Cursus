/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:15:57 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/13 16:16:24 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int		sa(t_stack **a);
int		sb(t_stack **b);
int		ss(t_stack **a, t_stack **b);
int		pa(t_stack **a, t_stack **b);
int		pb(t_stack **a, t_stack **b);
int		ra(t_stack **a);
int		rb(t_stack **b);
int		rr(t_stack **a, t_stack **b);
int		rra(t_stack **a);
int		rrb(t_stack **b);
int		rrr(t_stack **a, t_stack **b);
int		check_list(char **list);
int		check_arg(char *arg);

char	*ps_strjoin(char *s1, char *s2);

size_t	ps_stacksize(t_stack *lst);

t_stack	*ps_stacklast(t_stack *lst);
void	fill_stack(t_stack *stack, char **tab);

#endif
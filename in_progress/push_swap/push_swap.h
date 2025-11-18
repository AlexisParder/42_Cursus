/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:15:57 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/18 10:24:49 by achauvie         ###   ########.fr       */
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

typedef struct s_calc_move
{
	long	nbr;
	size_t	nbr_move;
}	t_calc_move;

int			sa(t_stack **a);
int			sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);
int			ra(t_stack **a);
int			rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);
int			rra(t_stack **a);
int			rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);
int			check_list(char **list);
int			check_arg(char *arg);

char		*ps_strjoin(char *s1, char *s2);

void		fill_stack(t_stack **stack, char **list);
void		assign_index(t_stack *stack);
void		ft_error(void);
void		free_stack(t_stack *stack);
void		push_swap(t_stack *a);

size_t		ps_stacksize(t_stack *lst);
size_t		find_stack_max(t_stack *stack);
size_t		find_stack_min(t_stack *stack);
size_t		find_max(size_t a, size_t b);

t_stack		*ps_stacklast(t_stack *lst);

t_calc_move	*calc_move(t_stack *a, t_stack *b);

#endif
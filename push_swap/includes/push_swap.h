/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:15:57 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/28 10:32:30 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

typedef struct s_stack
{
	long			nbr;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_calc_move
{
	long	nbr;
	size_t	nbr_move;
}	t_calc_mv;

int			sa(t_stack **a, int print);
int			sb(t_stack **b, int print);
int			ra(t_stack **a, int print);
int			rb(t_stack **b, int print);
int			rra(t_stack **a, int print);
int			rrb(t_stack **b, int print);
int			check_list(char **list);
int			check_arg(char *arg);
int			fill_stack(t_stack **stack, char **list);

void		ss(t_stack **a, t_stack **b);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rrr(t_stack **a, t_stack **b);
void		ft_error(void);
void		push_swap(t_stack **a, t_stack **b);
void		make_moves(t_stack **a, t_stack **b, t_calc_mv *next_nbr);
void		sort_size_2(t_stack **a);
void		sort_size_3(t_stack **a);
void		sort_size_5(t_stack **a, t_stack **b);
void		fill_sorted_a(t_stack **a, t_stack **b);
void		last_sort_a(t_stack **a);
void		last_sort_b(t_stack **b);
void		free_stack(t_stack **stack);
void		free_list(char **list);

char		*ps_strjoin(char *s1, char *s2);

long		find_stack_max_value(t_stack *stack);
long		find_stack_min_value(t_stack *stack);

size_t		ps_stacksize(t_stack *lst);
size_t		find_stack_max_pos(t_stack *stack);
size_t		find_stack_min_pos(t_stack *stack);
size_t		find_max(size_t a, size_t b);
size_t		calc_pos_b(t_stack *a, t_stack *b);
size_t		find_pos(long nbr_search, t_stack *stack);

t_stack		*ps_stacklast(t_stack *lst);

t_calc_mv	*calc_move(t_stack *a, t_stack *b);

#endif
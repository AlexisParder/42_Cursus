/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:15:11 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/28 09:42:36 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char	**ps_parsing(int len, char **av)
{
	int		i;
	char	*tmp_str;
	char	**list;

	i = 1;
	tmp_str = NULL;
	while (i <= len)
	{
		if (!check_arg(av[i]))
		{
			free(tmp_str);
			return (NULL);
		}
		tmp_str = ps_strjoin(tmp_str, av[i]);
		if (!tmp_str)
			return (NULL);
		i++;
	}
	list = ft_split(tmp_str, ' ');
	free(tmp_str);
	if (!list)
		return (NULL);
	return (list);
}

static void	select_sort(t_stack **a, t_stack **b)
{
	size_t	size_a;

	size_a = ps_stacksize(*a);
	if (size_a == 2)
		sort_size_2(a);
	else if (size_a == 3)
		sort_size_3(a);
	else if (size_a == 4 || size_a == 5)
		sort_size_5(a, b);
	else if (size_a > 5)
		push_swap(a, b);
}

static int	is_sorted(t_stack *stack)
{
	while (stack)
	{
		if (stack->next && stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	start_push_swap(char **list)
{
	int		err_fill;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	err_fill = fill_stack(&a, list);
	free_list(list);
	if (err_fill)
	{
		free_stack(&a);
		free_stack(&b);
		ft_error();
	}
	if (a && !is_sorted(a))
		select_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
}

int	main(int ac, char **av)
{
	char	**list;

	if (ac > 1)
	{
		ac--;
		list = ps_parsing(ac, av);
		if (!list || !check_list(list))
		{
			free_list(list);
			ft_error();
		}
		start_push_swap(list);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:15:11 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/25 15:11:41 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	free_list(char **list)
{
	size_t	i;

	i = 0;
	while (list && list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}

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
			ft_error();
		}
		tmp_str = ps_strjoin(tmp_str, av[i]);
		i++;
	}
	list = ft_split(tmp_str, ' ');
	free(tmp_str);
	if (!list)
		ft_error();
	return (list);
}

static void	select_sort(t_stack *a)
{
	size_t	size_a;

	size_a = ps_stacksize(a);
	if (size_a == 2)
		sort_size_2(&a);
	else if (size_a == 3)
		sort_size_3(&a);
	else if (size_a == 4 || size_a == 5)
		sort_size_5(&a);
	else if (size_a > 5)
		push_swap(a);
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

int	main(int ac, char **av)
{
	char	**list;
	t_stack	*a;

	if (ac > 1)
	{
		ac--;
		list = ps_parsing(ac, av);
		if (!check_list(list))
		{
			free_list(list);
			ft_error();
		}
		a = NULL;
		fill_stack(&a, list);
		free_list(list);
		if (a && !is_sorted(a))
			select_sort(a);
		free_stack(&a, 0);
	}
	return (0);
}

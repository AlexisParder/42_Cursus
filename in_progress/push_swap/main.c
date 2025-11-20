/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:15:11 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/20 09:17:56 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		// assign_index(a);
		push_swap(a);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:15:11 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/13 17:02:28 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

static char	**ps_parsing(int len, char **av)
{
	int		i;
	char	*tmp_str;
	char	**tab;

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
	tab = ft_split(tmp_str, ' ');
	free(tmp_str);
	i = 0;
	return (tab);
}

int	main(int ac, char **av)
{
	char	**tab;
	t_stack	*a;

	if (ac > 1)
	{
		ac--;
		tab = ps_parsing(ac, av);
		if (!check_list(tab))
		{
			free(tab);
			ft_error();
		}
		// a = malloc(1000000*sizeof(t_stack));
		a = NULL;
		fill_stack(&a, tab);
	}
	else
		ft_error();
	return (0);
}

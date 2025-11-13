/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:46:05 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/13 10:44:57 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_dup(char **list)
{
	int	i;
	int	k;

	i = 0;
	while (list[i])
	{
		k = i + 1;
		while (list[k])
		{
			if (list[i] == list[k])
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

static int	arg_isdigit(char *arg)
{
	int	i;

	i = 0;
	while ((arg[i] >= 9 && arg[i] <= 13) || arg[i] == 32)
		i++;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_list(char **list)
{
	int	i;

	i = 1;
	while (list && list[i])
	{
		if (!arg_isdigit(list[i]))
			return (0);
		i++;
	}
	if (find_dup(list))
		return (0);
	return (1);
}

int	check_arg(char *arg)
{
	size_t	i;

	i = 0;
	while (arg && arg[i])
	{
		if (ft_isdigit(arg[i]))
			return (1);
		i++;
	}
	return (0);
}

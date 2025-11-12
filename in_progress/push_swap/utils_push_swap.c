/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:51:19 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/12 10:27:07 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_dup(int *tab, int len)
{
	int	i;
	int	k;

	i = 0;
	while (i <= len)
	{
		k = i + 1;
		while (k < len)
		{
			if (tab[i] == tab[k])
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

int	check_list(int *tab, int len, char **list)
{
	int	i;

	i = 1;
	while (tab && list[i] && i <= len)
	{
		if (!arg_isdigit(list[i]))
			return (0);
		tab[i - 1] = ft_atoi(list[i]);
		i++;
	}
	if (!tab || find_dup(tab, len))
		return (0);
	return (1);
}

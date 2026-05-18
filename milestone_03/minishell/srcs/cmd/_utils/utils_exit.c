/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:33:28 by tjourdai          #+#    #+#             */
/*   Updated: 2026/03/27 16:37:46 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	is_overflow(const char *str)
{
	const char	*max;
	const char	*min;
	const char	*limit;
	size_t		i;

	max = "9223372036854775807";
	min = "9223372036854775808";
	limit = max;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			limit = min;
		i++;
	}
	if (ft_strlen(&str[i]) != ft_strlen(limit))
	{
		if (ft_strlen(&str[i]) > ft_strlen(limit))
			return (1);
		return (0);
	}
	if (ft_strncmp(&str[i], limit, ft_strlen(limit)) > 0)
		return (1);
	return (0);
}

int	arg_is_digit(char *arg)
{
	size_t	i;
	size_t	start;

	i = 0;
	if (!arg || !arg[0])
		return (0);
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	start = i;
	if (!arg[i])
		return (0);
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	if ((i - start) > 19 || is_overflow(arg))
		return (0);
	return (1);
}

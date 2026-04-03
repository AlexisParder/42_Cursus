/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_shlvl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 09:18:55 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/03 09:59:07 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	shlvlv_check_overflow(const char *str)
{
	const char	*max;
	const char	*limit;
	size_t		i;

	max = "9223372036854775807";
	limit = max;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (1);
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

static int	shlvlv_check_digit(char *arg)
{
	size_t	i;
	size_t	start;

	i = 0;
	if (!arg || !arg[0])
		return (0);
	if (arg[i] == '+')
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
	if ((i - start) > 19 || shlvlv_check_overflow(arg))
		return (0);
	return (1);
}

int	manage_shlvl(t_minishell *data)
{
	long	current_value_long;
	char	*current_value_str;

	current_value_str = get_envp(data->envp, "SHLVL");
	if (!current_value_str || !shlvlv_check_digit(current_value_str))
		current_value_long = 1;
	else
	{
		current_value_long = ft_atol(current_value_str);
		if (current_value_long < 1)
			current_value_long = 1;
		else
			current_value_long++;
	}
	current_value_str = ft_itoa(current_value_long);
	if (!current_value_str)
	{
		current_value_str = ft_strdup("1");
		if (!current_value_str)
			return (1);
	}
	data->exports = set_envp(data->exports, "SHLVL", current_value_str, 1);
	data->envp = set_envp(data->envp, "SHLVL", current_value_str, 1);
	free(current_value_str);
	return (0);
}

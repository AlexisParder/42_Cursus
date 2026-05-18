/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:50:37 by achauvie          #+#    #+#             */
/*   Updated: 2026/03/27 13:26:35 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	is_valid_identifier(char *cmd_name, char *identifier, char *value)
{
	size_t	i;

	if (!ft_isalpha(identifier[0]) && !ft_strchr("_$", identifier[0]))
	{
		ft_dprintf(2, "minishell: %s: `%s", cmd_name, identifier);
		if (value)
			ft_dprintf(2, "=");
		ft_dprintf(2, "': not a valid identifier\n");
		return (0);
	}
	i = 1;
	while (identifier[i])
	{
		if (!ft_isalnum(identifier[i]) && identifier[i] != '_')
		{
			ft_dprintf(2, "minishell: %s: `%s", cmd_name, identifier);
			if (value)
				ft_dprintf(2, "=");
			ft_dprintf(2, "': not a valid identifier\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static void	fill_key_value(char **arr, char *var)
{
	int	i;

	i = 0;
	arr[0] = NULL;
	arr[1] = NULL;
	while (var[i])
	{
		if (i > 0
			&& var[i] == '+' && var[i + 1] && var[i + 1] == '=' && !arr[0])
			arr[0] = ft_substr(var, 0, i);
		if (var[i] == '=')
		{
			if (!arr[0])
				arr[0] = ft_substr(var, 0, i);
			if (!arr[1])
				arr[1] = ft_strdup(&var[i + 1]);
			break ;
		}
		if (!arr[0] && !ft_isalnum(var[i]) && var[i] != '_')
			break ;
		i++;
	}
	if (!arr[0])
		arr[0] = ft_strdup(var);
}

char	**separate_key_value(char *var)
{
	char	**arr;

	if (!var || !var[0] || var[0] == '=')
	{
		ft_dprintf(2, "minishell: export: `%s': not a valid identifier\n",
			var);
		return (NULL);
	}
	arr = ft_calloc(3, sizeof(char *));
	if (!arr)
		return (NULL);
	fill_key_value(arr, var);
	return (arr);
}

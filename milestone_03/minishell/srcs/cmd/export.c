/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 08:48:34 by achauvie          #+#    #+#             */
/*   Updated: 2026/03/30 10:55:51 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	set_envp_and_exports(t_minishell *data, char **tmp, char *operator)
{
	if (operator)
	{
		data->exports = set_envp(data->exports, tmp[0], tmp[1], 1);
		data->envp = set_envp(data->envp, tmp[0], tmp[1], 1);
	}
	else if (!get_envp(data->envp, tmp[0]))
		data->exports = set_envp(data->exports, tmp[0], NULL, 0);
}

static void	fill_arrays(t_minishell *data, char *arg, int *err)
{
	char	**tmp;
	char	*old;

	tmp = separate_key_value(arg);
	if (!tmp)
	{
		*err = 1;
		return ;
	}
	if (ft_strlen(tmp[0]) == 1 && !ft_strncmp(tmp[0], "_", 2))
		return ;
	if (tmp[0] && is_valid_identifier("export", tmp[0], tmp[1]))
	{
		if (ft_strnstr(arg, "+=", ft_strlen(arg)))
		{
			old = tmp[1];
			tmp[1] = ft_strjoin(get_envp(data->envp, tmp[0]), tmp[1]);
			free(old);
		}
		set_envp_and_exports(data, tmp, ft_strchr(arg, '='));
	}
	else
		*err = 1;
	ft_free_arr(tmp);
}

int	cmd_export(t_minishell *data, t_cmd *cmd)
{
	int		err;
	size_t	i;

	err = 0;
	i = 1;
	if (cmd->nb_args == 1 || (cmd->nb_args == 2 && !cmd->args[1]))
	{
		display_exports(data, cmd);
		return (0);
	}
	while (cmd->args[i])
	{
		fill_arrays(data, cmd->args[i], &err);
		i++;
	}
	return (err);
}

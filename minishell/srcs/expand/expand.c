/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 09:36:31 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/01 09:49:51 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*manage_arg(t_minishell *data, t_cmd *cmd, size_t *j, size_t arg_i)
{
	char	*tmp;

	if (cmd->args[arg_i][*j + 1] == '?')
	{
		tmp = ft_itoa(data->return_code);
		(*j) += 2;
		return (tmp);
	}
	else if (cmd->args[arg_i][*j] == '~')
	{
		tmp = get_envp(data->envp, "HOME");
		(*j)++;
		return (tmp);
	}
	else if (cmd->args[arg_i][*j + 1] && (ft_isalpha(cmd->args[arg_i][*j + 1])
		|| cmd->args[arg_i][*j + 1] == '_'))
	{
		tmp = get_var(data, cmd->args[arg_i], j);
		return (tmp);
	}
	else
		(*j) += 2;
	return (NULL);
}

static char	*get_value(t_minishell *data, t_cmd *cmd, size_t *j, size_t arg_i)
{
	char	*tmp;
	char	c;

	if (cmd->args[arg_i][*j] == '$' && cmd->args[arg_i][*j + 1]
		&& !ft_isspace(cmd->args[arg_i][*j + 1]))
	{
		tmp = manage_arg(data, cmd, j, arg_i);
		if (tmp && cmd->args[arg_i][*j - 1] != '?')
			tmp = ft_strdup(tmp);
		return (tmp);
	}
	else if (cmd->args[arg_i][*j] == '~')
	{
		tmp = manage_arg(data, cmd, j, arg_i);
		if (tmp)
			tmp = ft_strdup(tmp);
		return (tmp);
	}
	c = cmd->args[arg_i][*j];
	(*j)++;
	tmp = ft_calloc(2, sizeof(char));
	if (!tmp)
		return (NULL);
	tmp[0] = c;
	return (tmp);
}

static void	expand(t_minishell *data, t_cmd *cmd, size_t arg_i)
{
	size_t	j;
	char	*tmp;
	char	*expanded_arg;

	j = 0;
	expanded_arg = NULL;
	while (cmd->args[arg_i][j])
	{
		tmp = get_value(data, cmd, &j, arg_i);
		if (!tmp)
			continue ;
		expanded_arg = ft_strjoin_free(expanded_arg, tmp);
		free(tmp);
	}
	free(cmd->args[arg_i]);
	cmd->args[arg_i] = NULL;
	if (expanded_arg)
		cmd->args[arg_i] = ft_strdup(expanded_arg);
	else if (cmd->quotes[arg_i])
		cmd->args[arg_i] = ft_strdup("");
	free(expanded_arg);
}

void	expand_and_reorganize(t_minishell *data)
{
	size_t	i;
	t_cmd	*current_cmd;

	current_cmd = data->cmds;
	while (current_cmd)
	{
		i = 0;
		while (current_cmd->args[i])
		{
			if (current_cmd->quotes[i] != '\'')
				expand(data, current_cmd, i);
			i++;
		}
		expand_redirs(data, current_cmd);
		reorganize_args(current_cmd);
		current_cmd = current_cmd->next;
	}
}

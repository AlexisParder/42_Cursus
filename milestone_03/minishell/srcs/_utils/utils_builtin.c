/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:28:43 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/03 10:22:45 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	is_builtin(t_cmd *cmd)
{
	if (!cmd || !cmd->args[0])
		return (0);
	if (!ft_strncmp(cmd->args[0], "pwd", 4))
		return (1);
	else if (!ft_strncmp(cmd->args[0], "env", 3))
		return (1);
	else if (!ft_strncmp(cmd->args[0], "echo", 5))
		return (1);
	else if (!ft_strncmp(cmd->args[0], "exit", 5))
		return (1);
	else if (!ft_strncmp(cmd->args[0], "cd", 3))
		return (1);
	else if (!ft_strncmp(cmd->args[0], "export", 7))
		return (1);
	else if (!ft_strncmp(cmd->args[0], "unset", 6))
		return (1);
	else
		return (0);
}

void	exec_builtin(t_minishell *data, t_cmd *cmd)
{
	if (!ft_strncmp(cmd->args[0], "pwd", 4))
		data->return_code = cmd_pwd(data);
	else if (!ft_strncmp(cmd->args[0], "env", 3))
		data->return_code = cmd_env(data);
	else if (!ft_strncmp(cmd->args[0], "echo", 5))
		data->return_code = cmd_echo(data, cmd);
	else if (!ft_strncmp(cmd->args[0], "exit", 5))
		data->return_code = cmd_exit(data, cmd);
	else if (!ft_strncmp(cmd->args[0], "cd", 3))
		data->return_code = cmd_cd(data, cmd);
	else if (!ft_strncmp(cmd->args[0], "export", 7))
		data->return_code = cmd_export(data, cmd);
	else if (!ft_strncmp(cmd->args[0], "unset", 6))
		data->return_code = cmd_unset(data, cmd);
	if (data->nb_cmds > 1)
	{
		clean_main(data, NULL);
		exit(data->return_code);
	}
}

int	exec_builtin_with_redirs(t_minishell *data, t_cmd *cmd)
{
	if (save_fd(data) < 0)
		return (1);
	if (apply_redirs(cmd->redirs) < 0)
	{
		if (restore_fd(data))
			return (1);
		return (0);
	}
	exec_builtin(data, cmd);
	if (restore_fd(data))
		return (1);
	return (0);
}

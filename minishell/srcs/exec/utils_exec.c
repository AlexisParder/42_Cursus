/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 08:43:10 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/01 15:33:23 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	err_path(t_minishell *data, t_cmd *cmd)
{
	data->return_code = 126;
	if (cmd->err_path == ERR_CMD_NOT_FOUND)
	{
		ft_dprintf(2, "%s: command not found\n", cmd->args[0]);
		data->return_code = 127;
	}
	else if (cmd->err_path == ERR_CMD_NO_SUCH)
	{
		ft_dprintf(2, "%s: No such file or directory\n", cmd->args[0]);
		data->return_code = 127;
	}
	else if (cmd->err_path == ERR_CMD_IS_DIR)
		ft_dprintf(2, "%s: Is a directory\n", cmd->args[0]);
	else if (cmd->err_path == ERR_CMD_PERMISSION)
		ft_dprintf(2, "%s: Permission denied\n", cmd->args[0]);
	else
		perror(cmd->args[0]);
	ft_free_arr(data->envp);
	ft_free_arr(data->exports);
	free_all(data);
	rl_clear_history();
	exit(data->return_code);
}

static void	close_all_pipes(t_minishell *data)
{
	size_t	i;

	i = 0;
	while (i < data->nb_cmds - 1)
	{
		close(data->pipefd[i][0]);
		close(data->pipefd[i][1]);
		i++;
	}
}

int	create_pipes(t_minishell *data, size_t cmd_nb)
{
	int	res;

	res = 0;
	if (cmd_nb == 0 && data->nb_cmds > 1)
		res = dup2(data->pipefd[cmd_nb][1], STDOUT_FILENO);
	else if (cmd_nb == data->nb_cmds - 1 && data->nb_cmds > 1)
		res = dup2(data->pipefd[cmd_nb - 1][0], STDIN_FILENO);
	else if (data->nb_cmds > 1)
	{
		res = dup2(data->pipefd[cmd_nb - 1][0], STDIN_FILENO);
		if (res < 0)
		{
			perror("minishell: dup");
			return (-1);
		}
		res = dup2(data->pipefd[cmd_nb][1], STDOUT_FILENO);
	}
	if (res < 0)
	{
		perror("minishell: dup");
		return (-1);
	}
	close_all_pipes(data);
	return (0);
}

int	save_fd(t_minishell *data)
{
	data->stdin_dup = dup(STDIN_FILENO);
	if (data->stdin_dup < 0)
	{
		perror("minishell: dup stdin");
		return (-1);
	}
	data->stdout_dup = dup(STDOUT_FILENO);
	if (data->stdout_dup < 0)
	{
		perror("minishell: dup stdout");
		close(data->stdin_dup);
		return (-1);
	}
	return (0);
}

void	restore_fd(t_minishell *data)
{
	if (data->stdin_dup >= 0)
	{
		dup2(data->stdin_dup, STDIN_FILENO);
		close(data->stdin_dup);
		data->stdin_dup = -1;
	}
	if (data->stdout_dup >= 0)
	{
		dup2(data->stdout_dup, STDOUT_FILENO);
		close(data->stdout_dup);
		data->stdout_dup = -1;
	}
}

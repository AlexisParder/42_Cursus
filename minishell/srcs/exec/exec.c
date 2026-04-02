/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:24:25 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/01 09:13:56 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	exec_cmd(t_minishell *data, t_cmd *cmd)
{
	if (!cmd->args[0])
	{
		clean_main(data, NULL);
		exit(0);
	}
	if (is_builtin(cmd))
		exec_builtin(data, cmd);
	else
	{
		cmd->err_path = check_access_cmd(data, cmd);
		if (cmd->err_path)
			err_path(data, cmd);
		execve(cmd->path, cmd->args, data->envp);
		ft_dprintf(2, "%s: command not found\n", cmd->args[0]);
		data->return_code = 127;
		clean_main(data, NULL);
		exit(127);
	}
}

static void	exec_child(t_minishell *data, size_t cmd_nb, t_cmd *cmd)
{
	data->pid[cmd_nb] = fork();
	if (data->pid[cmd_nb] < 0)
	{
		perror("fork");
		return ;
	}
	if (data->pid[cmd_nb] == 0)
	{
		exec_child_signals(cmd);
		if (create_pipes(data, cmd_nb) < 0)
		{
			clean_main(data, NULL);
			exit(1);
		}
		close_other_heredocs(data, cmd);
		if (apply_redirs(cmd->redirs) < 0)
		{
			clean_main(data, NULL);
			exit(1);
		}
		exec_cmd(data, cmd);
	}
}

static void	close_parent_pipes(t_minishell *data, size_t cmd_nb)
{
	if (cmd_nb > 0)
		close(data->pipefd[cmd_nb - 1][0]);
	if (cmd_nb < data->nb_cmds - 1)
		close(data->pipefd[cmd_nb][1]);
}

static void	wait_children(t_minishell *data)
{
	size_t	i;
	pid_t	wpid;
	int		status;

	i = 0;
	while (i < data->nb_cmds)
	{
		wpid = waitpid(-1, &status, 0);
		if (wpid == data->pid[data->nb_cmds - 1])
		{
			data->status[data->nb_cmds - 1] = status;
			if (WIFSIGNALED(status))
			{
				if (WTERMSIG(status) == SIGINT)
					write(1, "\n", 1);
				else if (WTERMSIG(status) == SIGQUIT)
					write(1, "Quit\n", 5);
				else if (WTERMSIG(status) == SIGPIPE)
					data->return_code = 141;
			}
		}
		i++;
	}
}

int	exec_parent(t_minishell *data)
{
	t_cmd	*current_cmd;
	size_t	i;

	i = 0;
	while (i < data->nb_cmds - 1)
	{
		if (pipe(data->pipefd[i]) < 0)
			return (1);
		i++;
	}
	manage_signals_exec_parent();
	current_cmd = data->cmds;
	i = 0;
	while (current_cmd)
	{
		exec_child(data, i, current_cmd);
		close_parent_pipes(data, i);
		close_parent_heredocs(current_cmd);
		current_cmd = current_cmd->next;
		i++;
	}
	wait_children(data);
	if (WIFEXITED(data->status[data->nb_cmds - 1]))
		return (WEXITSTATUS(data->status[data->nb_cmds - 1]));
	return (1);
}

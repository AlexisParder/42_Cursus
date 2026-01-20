/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_parent_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:43:55 by achauvie          #+#    #+#             */
/*   Updated: 2026/01/20 10:28:44 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

static void	exec_cmd(t_pipex *data, size_t cmd_nb)
{
	int	nb_cmds;

	nb_cmds = data->argc - 3 - data->here_doc;
	data->cmds[cmd_nb].err_path = check_access_cmd(data,
			data->argv[cmd_nb + 2 + data->here_doc], cmd_nb);
	if (data->cmds[cmd_nb].err_path)
		err_path(data, cmd_nb);
	execve(data->cmds[cmd_nb].path, data->cmds[cmd_nb].args, data->envp);
	ft_putstr_fd(data->cmds[cmd_nb].name, 2);
	ft_putstr_fd(": command not found\n", 2);
	free_all(data);
	exit(127);
}

static void	exec_child(t_pipex *data, size_t cmd_nb)
{
	int	nb_cmds;

	nb_cmds = data->argc - 3 - data->here_doc;
	data->pid[cmd_nb] = fork();
	if (data->pid[cmd_nb] < 0)
		return ;
	if (data->pid[cmd_nb] == 0)
	{
		if (cmd_nb == 0)
			infile_to_pipe(data);
		else if (cmd_nb == (size_t)nb_cmds - 1)
			pipe_to_outfile(data, cmd_nb);
		else
			pipe_to_pipe(data, cmd_nb);
		exec_cmd(data, cmd_nb);
	}
}

static void	close_parent_pipes(t_pipex *data, size_t cmd_nb)
{
	if (cmd_nb > 0)
	{
		close(data->pipefd[cmd_nb - 1][0]);
		close(data->pipefd[cmd_nb - 1][1]);
	}
}

int	exec_parent(t_pipex *data)
{
	size_t	i;

	i = 0;
	while (i < (size_t)data->argc - 3 - data->here_doc)
	{
		if (i < (size_t)data->argc - 4 - data->here_doc)
		{
			if (pipe(data->pipefd[i]) < 0)
				return (1);
		}
		exec_child(data, i);
		close_parent_pipes(data, i);
		i++;
	}
	i = 0;
	while (i < (size_t)data->argc - 3 - data->here_doc)
	{
		waitpid(data->pid[i], &data->status[i], 0);
		i++;
	}
	if (WIFEXITED(data->status[data->argc - 4 - data->here_doc]))
		return (WEXITSTATUS(data->status[data->argc - 4 - data->here_doc]));
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_parent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:43:55 by achauvie          #+#    #+#             */
/*   Updated: 2026/01/16 10:44:18 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	exec_child1(t_pipex *data)
{
	int		fd;

	data->pid[0] = fork();
	if (data->pid[0] == 0)
	{
		close(data->pipefd[0][0]);
		fd = open_file(data, data->argv[1], 1);
		dup2(fd, STDIN_FILENO);
		close(fd);
		data->cmds[0].err_path = check_access_cmd(data, data->argv[2], 0);
		if (data->cmds[0].err_path)
			err_path(data, 0, data->pipefd[0][1], -1);
		else
		{
			dup2(data->pipefd[0][1], STDOUT_FILENO);
			close(data->pipefd[0][1]);
			execve(data->cmds[0].path, data->cmds[0].args, data->envp);
			ft_putstr_fd(data->cmds[0].name, 2);
			ft_putstr_fd(": command not found\n", 2);
			free_all(data);
			exit(127);
		}
	}
}

static void	exec_child2(t_pipex *data)
{
	int		fd;

	data->pid[1] = fork();
	if (data->pid[1] == 0)
	{
		close(data->pipefd[0][1]);
		fd = open_file(data, data->argv[4], 0);
		data->cmds[1].err_path = check_access_cmd(data, data->argv[3], 1);
		if (data->cmds[1].err_path)
			err_path(data, 1, fd, data->pipefd[0][0]);
		else
		{
			dup2(data->pipefd[0][0], STDIN_FILENO);
			close(data->pipefd[0][0]);
			dup2(fd, STDOUT_FILENO);
			close(fd);
			execve(data->cmds[1].path, data->cmds[1].args, data->envp);
			ft_putstr_fd(data->cmds[1].name, 2);
			ft_putstr_fd(": command not found\n", 2);
			free_all(data);
			exit(127);
		}
	}
}

static void	close_pipes(t_pipex *data)
{
	long	i;

	i = 0;
	while (i < data->argc - 4)
	{
		close(data->pipefd[i][0]);
		close(data->pipefd[i][1]);
		i++;
	}
}

int	exec_parent(t_pipex *data)
{
	long	i;

	i = 0;
	while (i < data->argc - 4)
	{
		if (pipe(data->pipefd[i]) < 0)
			return (1);
		i++;
	}
	exec_child1(data);
	exec_child2(data);
	close_pipes(data);
	i = 0;
	while (i < data->argc - 3)
	{
		waitpid(data->pid[i], &data->status[i], 0);
		i++;
	}
	if (WIFEXITED(data->status[data->argc - 4]))
		return (WEXITSTATUS(data->status[data->argc - 4]));
	return (1);
}

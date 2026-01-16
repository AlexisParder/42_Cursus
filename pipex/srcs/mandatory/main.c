/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:56:30 by achauvie          #+#    #+#             */
/*   Updated: 2026/01/16 10:27:40 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	exec_cmd1(t_pipex *data)
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

void	exec_cmd2(t_pipex *data)
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

int	exec_cmds(t_pipex *data)
{
	if (pipe(data->pipefd[0]) < 0)
		return (1);
	exec_cmd1(data);
	exec_cmd2(data);
	close(data->pipefd[0][0]);
	close(data->pipefd[0][1]);
	waitpid(data->pid[0], &data->status[0], 0);
	waitpid(data->pid[1], &data->status[1], 0);
	if (WIFEXITED(data->status[1]))
		return (WEXITSTATUS(data->status[1]));
	return (1);
}

static int	init_data(t_pipex *data, int ac, char **av, char **envp)
{
	long	i;

	data->argc = ac;
	data->argv = av;
	data->envp = envp;
	data->status = ft_calloc(data->argc - 3, sizeof(int));
	if (!data->status)
		return (1);
	data->pid = ft_calloc(data->argc - 3, sizeof(int));
	if (!data->pid)
		return (1);
	data->pipefd = ft_calloc(data->argc - 3, sizeof(int *));
	if (!data->pipefd)
		return (1);
	i = 0;
	while (i < data->argc - 4)
	{
		data->pipefd[i] = ft_calloc(2, sizeof(int));
		if (!data->pipefd[i])
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	data;
	int		err;

	if (ac != 5)
	{
		ft_putstr_fd("Error usage: ./pipex file1 cmd1 cmd2 file2\n", 2);
		return (1);
	}
	err = init_data(&data, ac, av, envp);
	if (!err)
		err = fill_cmds(&data);
	if (!err)
		err = exec_cmds(&data);
	free_all(&data);
	return (err);
}

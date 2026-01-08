/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:56:30 by achauvie          #+#    #+#             */
/*   Updated: 2026/01/08 10:06:58 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	open_file(char *file, int rd_only)
{
	int	fd;

	if (rd_only)
		fd = open(file, O_RDONLY);
	else
		fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(file);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	exec_cmd1(t_pipex *data)
{
	int		fd;
	char	*path;

	data->pid1 = fork();
	if (data->pid1 == 0)
	{
		close(data->pipefd[0]);
		fd = open_file(data->argv[1], 1);
		dup2(fd, STDIN_FILENO);
		close(fd);
		path = check_access_cmd(data, data->argv[2]);
		if (!path)
		{
			perror(data->cmds[0].name);
			exit(127);
		}
		dup2(data->pipefd[1], STDOUT_FILENO);
		close(data->pipefd[1]);
		execve(path, data->cmds[0].args, data->envp);
		perror(data->cmds[0].name);
		exit(EXIT_FAILURE);
	}
}

void	exec_cmd2(t_pipex *data)
{
	int		fd;
	char	*path;

	data->pid2 = fork();
	if (data->pid2 == 0)
	{
		close(data->pipefd[1]);
		fd = open_file(data->argv[4], 0);
		dup2(data->pipefd[0], STDIN_FILENO);
		close(data->pipefd[0]);
		path = check_access_cmd(data, data->argv[3]);
		if (!path)
		{
			perror(data->cmds[1].name);
			exit(127);
		}
		dup2(fd, STDOUT_FILENO);
		close(fd);
		execve(path, data->cmds[1].args, data->envp);
		perror(data->cmds[1].name);
		exit(EXIT_FAILURE);
	}
}

int	exec_cmds(t_pipex *data)
{
	if (pipe(data->pipefd) < 0)
		return (1);
	exec_cmd1(data);
	exec_cmd2(data);
	close(data->pipefd[0]);
	close(data->pipefd[1]);
	waitpid(data->pid1, &data->status1, 0);
	waitpid(data->pid2, &data->status2, 0);
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
	data.argc = ac;
	data.argv = av;
	data.envp = envp;
	err = fill_cmds(&data);
	if (err)
		free_cmds(&data, EXIT_FAILURE);
	exec_cmds(&data);
	free_cmds(&data, EXIT_SUCCESS);
	return (0);
}

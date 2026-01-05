/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:56:30 by achauvie          #+#    #+#             */
/*   Updated: 2026/01/05 14:32:01 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	exec_cmd1(t_pipex *data)
{
	data->pid1 = fork();
	if (data->pid1 < 0)
		return ;
	if (data->pid1 == 0)
	{
		int		fd;
		char	**argv;
		char	*path;

		close(data->pipefd[0]);
		fd = open(data->argv[1], O_RDONLY);
		if (fd < 0)
		{
			perror(data->argv[1]);
			exit(EXIT_FAILURE);
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
		path = check_access_cmd(data, data->argv[2]);
		if (!path)
		{
			perror(path);
			exit(EXIT_FAILURE);
		}
		dup2(data->pipefd[1], STDOUT_FILENO);
		close(data->pipefd[1]);
		argv = ft_split(data->argv[2], ' ');
		execve(path, argv, data->envp);
				perror("execve");
		free(path);
		exit(EXIT_FAILURE);
	}
}

void	exec_cmd2(t_pipex *data)
{
	data->pid2 = fork();
	if (data->pid2 < 0)
		return ;
	if (data->pid2 == 0)
	{
		int		fd;
		char	**argv;
		char	*path;
		
		fd = open(data->argv[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
		if (fd < 0)
		{
			perror(data->argv[4]);
			exit(EXIT_FAILURE);
		}
		dup2(data->pipefd[0], STDIN_FILENO);
		close(data->pipefd[0]);
		close(data->pipefd[1]);
		path = check_access_cmd(data, data->argv[3]);
		if (!path)
		{
			perror(path);
			exit(EXIT_FAILURE);
		}
		dup2(fd, STDOUT_FILENO);
		close(fd);
		argv = ft_split(data->argv[3], ' ');
		execve(path, argv, data->envp);
		perror("execve");
		free(path);
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

int main(int ac, char **av, char **envp)
{
	t_pipex	data;

	if (ac != 5)
	{
		ft_putstr_fd("Error usage: ./pipex file1 cmd1 cmd2 file2\n", 2);
		return (1);
	}
	data.argv = av;
	data.envp = envp;
	exec_cmds(&data);
	return 0;
}

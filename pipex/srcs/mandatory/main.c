/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:56:30 by achauvie          #+#    #+#             */
/*   Updated: 2026/01/05 12:31:41 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	exec_cmds(t_pipex data)
{
	int		status1;
	int		status2;
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(pipefd) < 0)
		return (1);
	pid1 = fork();
	if (pid1 < 0)
		return (1);
	if (pid1 == 0)
	{
		int fd;
		char	*path;
		char	**argv;

		close(pipefd[0]);
		fd = open(data.argv[1], O_RDONLY);
		if (fd < 0)
		{
			perror(data.argv[1]);
			exit(EXIT_FAILURE);
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
		path = check_access_cmd(data, data.argv[2]);
		if (!path)
		{
			perror(path);
			exit(EXIT_FAILURE);
		}
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		argv = ft_split(data.argv[2], ' ');
		execve(path, argv, data.envp);
	}
	pid2 = fork();
	if (pid2 < 0)
		return (1);
	if (pid2 == 0)
	{
		int fd;
		char	*path;
		char	**argv;
		
		fd = open(data.argv[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
		if (fd < 0)
		{
			perror(data.argv[4]);
			exit(EXIT_FAILURE);
		}
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);

		path = check_access_cmd(data, data.argv[3]);
		if (!path)
		{
			perror(path);
			exit(EXIT_FAILURE);
		}
		dup2(fd, STDOUT_FILENO);
		close(fd);
		argv = ft_split(data.argv[3], ' ');
		execve(path, argv, data.envp);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
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
	exec_cmds(data);
	return 0;
}

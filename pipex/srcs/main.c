/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:56:30 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/18 08:47:00 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int main(int ac, char **av)
{
	int		fd1;
	int		pipefd[2];
	pid_t	pid1;

	if (ac != 5)
	{
		ft_putstr_fd("Error usage: ./pipex file1 cmd1 cmd2 file2\n", 2);
		return (1);
	}
	if (access(av[2], F_OK | X_OK))
		perror(av[2]);
	if (access(av[3], F_OK | X_OK))
		perror(av[3]);
	// pipe(pipefd);
	// pid1 = fork();
	// fd1 = open(av[1], O_RDONLY);
	// if (fd1 < 0)
	// 	perror(av[1]);
	// dup2(fd1, STDIN_FILENO);
	// close(fd1);
	return 0;
}

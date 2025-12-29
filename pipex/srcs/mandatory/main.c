/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:56:30 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/29 12:48:00 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	fork_with_wait()
{
	pid_t pid = fork();
	int	n;
	int status;
	
	// Defini n = 1 pour l'enfant et n = 5 pour le parent
	if (pid == 0)
		n = 1;
	else
		n = 6;

	// Si on est dans le programme parent, on attend la fin du programme enfant
	if (pid != 0)
		waitpid(pid, &status, 0);
		
	int i = n;
	while (i < n + 5)
	{
		ft_printf("%d\n", i);
		i++;
	}
}

int	fork_pipe()
{
	int	fd[2];
	// fd[0] - Read
	// fd[1] - Write
	int	pid;
	
	if (pipe(fd) == -1)
	{
		ft_printf("An error ocurred with opening the pipe\n");
		return (1);
	}
	pid = fork();
	if (pid == -1)
	{
		ft_printf("An error occured with fork\n");
		return (1);
	}
	if (pid == 0)
	{
		int	x;
		
		close(fd[0]); // On ne fait qu'ecrire donc pas besoin du fd pour lire
		ft_printf("Input a number: ");
		scanf("%d", &x);
		if (write(fd[1], &x, sizeof(int)) == -1)
		{
			ft_printf("An error occured with writing to the pipe\n");
			return (1);
		}
		close(fd[1]);
	}
	else 
	{
		int	y;

		close(fd[1]); // On ne fait que lire donc pas besoin du fd pour ecrire
		if (read(fd[0], &y, sizeof(int)) == -1)
		{
			ft_printf("An error occured with reading from the pipe\n");
			return (1);
		}
		close(fd[0]);
		ft_printf("Got from child process %d\n", y);
	}
	return (0);
}

int	sum_with_pipe()
{
	int	arr[] = {1, 2, 3, 4, 1, 2, 7, 7};
	int	arrSize = sizeof(arr) / sizeof(int);
	int	start, end;
	int	fd[2];
	int	pid;
	int status;

	if (pipe(fd) == -1)
	{
		ft_printf("An error ocurred with opening the pipe\n");
		return (1);
	}

	pid = fork();
	if (pid == -1)
	{
		ft_printf("An error occured with fork\n");
		return (1);
	}
	
	if (pid == 0)
	{
		start = 0;
		end = arrSize / 2;
	}
	else
	{
		start = arrSize / 2;
		end = arrSize;
	}

	int sum = 0;
	int i;
	i = start;
	while (i < end)
	{
		sum += arr[i];
		i++;
	}

	printf("Calculated partial sum: %d\n", sum);

	if (pid == 0)
	{
		close(fd[0]);
		if (write(fd[1], &sum, sizeof(sum)) == -1)
		{
			ft_printf("An error occured with writing to the pipe\n");
			return (1);
		}
		close(fd[1]);
	}
	else
	{
		int sumFromChild;
		close(fd[1]);
		if (read(fd[0], &sumFromChild, sizeof(sumFromChild)) == -1)
		{
			ft_printf("An error occured with reading from the pipe\n");
			return (1);
		}
		close(fd[0]);
		sum += sumFromChild;
		printf("Total sum is %d\n", sum);
		waitpid(pid, &status, 0);
	}
	return (0);
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	// fork_with_wait();
	// fork_pipe();
	sum_with_pipe();
	// int		fd1;
	// int		pipefd[2];
	// pid_t	pid1;

	// if (ac != 5)
	// {
	// 	ft_putstr_fd("Error usage: ./pipex file1 cmd1 cmd2 file2\n", 2);
	// 	return (1);
	// }
	// if (access(av[2], F_OK | X_OK))
	// 	perror(av[2]);
	// if (access(av[3], F_OK | X_OK))
	// 	perror(av[3]);
	// pipe(pipefd);
	// pid1 = fork();
	// fd1 = open(av[1], O_RDONLY);
	// if (fd1 < 0)
	// 	perror(av[1]);
	// dup2(fd1, STDIN_FILENO);
	// close(fd1);
	return 0;
}

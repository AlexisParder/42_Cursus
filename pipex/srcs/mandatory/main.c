/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:56:30 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/30 12:46:52 by achauvie         ###   ########.fr       */
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

#include <time.h> // a retirer
int	communication_between_processes()
{
	int	fd1[2]; // C => P
	int	fd2[2]; // P => C
	pid_t	pid;
	
	if (pipe(fd1) == -1)
		return (1);
	if (pipe(fd2) == -1)
		return (1);
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		// Child process
		// Lire sur fd2
		// Ecrire sur fd1
		int	x;

		close (fd1[0]);
		close (fd2[1]);
		if (read(fd2[0], &x, sizeof(x)) == -1)
			return (1);
		printf("Received %d\n", x);
		x *= 4;
		if (write(fd1[1], &x, sizeof(x)) == -1)
			return (1);
		printf("Wrote %d\n", x);
		close (fd1[1]);
		close (fd2[0]);
	}
	else
	{
		// Parent process
		// Lire sur fd1
		// Ecrire sur fd2
		close (fd1[1]);
		close (fd2[0]);
		srand(time(NULL));
		int	y = rand() % 10;
		int	status;
		if (write(fd2[1], &y, sizeof(y)) == -1)
			return (1);
		if (read(fd1[0], &y, sizeof(y)) == -1)
			return (1);
		printf("Result is %d\n", y);
		close (fd1[0]);
		close (fd2[1]);
		waitpid(pid, &status, 0);
	}
	return (0);
}

int	exec_cmd()
{
	int pid;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		// Child process
		char *argv[] = {"ping", "-c", "3", "google.com", NULL};
		// char *argv[] = {"ping", "-c", "3", "googleeeqwewqedsadfa.com", NULL}; // simuler une err
    	char *envp[] = {NULL};
		int	err;

		// Redirecting standard output
		// int file;
		
		// file = open("pingRes.txt", O_WRONLY | O_CREAT, 0777);
		// if (file < 0)
		// 	return (1);
		
		// dup2(file, STDOUT_FILENO);
		// close(file);
		// 
    	err = execve("/bin/ping", argv, envp);
		// Si on met du code apres, il ne sera jamais execute car execve devient le nouveau programme SAUF si execve n'a pas fonctionne.
		if (err == -1)
		{
			ft_printf("Could not find program to execute\n");
			return (1);
		}
	}
	else
	{
		// Parent process
		int status;
		
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			int	statusCode;
			
			statusCode = WEXITSTATUS(status);
			if (statusCode == 0)
				ft_printf("Success!\n");
			else
				ft_printf("Failure with status code %d\n", statusCode);
		}
		ft_printf("Some post processing goes here!\n");
	}
	return (0);
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	// fork_with_wait();
	// fork_pipe();
	// sum_with_pipe();
	// communication_between_processes();
	exec_cmd();
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

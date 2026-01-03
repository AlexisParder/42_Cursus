/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:56:30 by achauvie          #+#    #+#             */
/*   Updated: 2026/01/03 14:12:20 by achauvie         ###   ########.fr       */
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
	if (pid < 0)
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
	if (pid < 0)
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
	if (pid < 0)
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

int	pipe_send_arr()
{
	pid_t	pid;
	int		pipefd[2];
	int		status;

	if (pipe(pipefd) == -1)
		return (1);
	pid = fork();
	if (pid < 0)
		return (1);
	if (pid == 0)
	{
		// Child
		int n;
		int i;
		int	arr[10];
		
		close (pipefd[0]);
		srand(time(NULL));
		n = rand() % 10 + 1;
		i = 0;
		while (i < n)
		{
			arr[i] = rand() % 11;
			i++;
		}
		// en premier, il faut envoyer n pour que le parent connaisse la taille de arr
		if (write(pipefd[1], &n, sizeof(int)) < 0)
			return (1);
		ft_printf("n sent is %d\n", n);
		if (write(pipefd[1], arr, sizeof(int) * n) < 0)
			return (1);
		close(pipefd[1]);
	}
	else
	{
		// Parent
		int n;
		int i;
		int sum;
		int	arr[10];
		
		close (pipefd[1]);
		if (read(pipefd[0], &n, sizeof(int)) < 0)
			return (1);
		if (read(pipefd[0], arr, sizeof(int) * n) < 0)
			return (1);
		close (pipefd[0]);
		sum = 0;
		i = 0;
		ft_printf("n received is %d\n", n);
		while (i < n)
		{
			ft_printf("arr[i] is %d\n", arr[i]);
			sum += arr[i];
			i++;
		}
		ft_printf("Result is %d\n", sum);
		waitpid(pid, &status, 0);
	}
	return (0);
}

int	pipe_send_str()
{
	pid_t	pid;
	int		pipefd[2];
	int		status;

	if (pipe(pipefd) == -1)
		return (1);
	pid = fork();
	if (pid < 0)
		return (1);
	if (pid == 0)
	{
		// Child
		char str[200];
		int		str_len;


		close(pipefd[0]);
		ft_printf("Input string: ");
		fgets(str, 200, stdin);
		str[ft_strlen(str) - 1] = '\0';
		str_len = ft_strlen(str) + 1;
		// en premier, il faut envoyer strlen pour que le parent connaisse la taille de str
		if (write(pipefd[1], &str_len, sizeof(int)) < 0)
			return (1);
		if (write(pipefd[1], str, sizeof(char) * str_len) < 0)
			return (1);
		ft_printf("Sent: %s\n", str);
		close(pipefd[1]);
	}
	else 
	{
		// Parent
		char	str[200];
		int		str_len;

		close(pipefd[1]);
		if (read(pipefd[0], &str_len, sizeof(int)) < 0)
			return (1);
		if (read(pipefd[0], str, sizeof(char) * str_len) < 0)
			return (1);
		close(pipefd[0]);
		ft_printf("Received: %s\n", str);
		waitpid(pid, &status, 0);
	}
	return (0);
}

int	exec_cmd()
{
	int pid;

	pid = fork();
	if (pid < 0)
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

int	simulate_pipe()
{
	int		pipefd[2];
	int		status1;
	int		status2;
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(pipefd) == -1)
		return (1);
	pid1 = fork();
	if (pid1 < 0)
		return (1);
	if (pid1 == 0)
	{
		// Child 1 (ping)
		char *argv[] = {"ping", "-c", "3", "google.com", NULL};
    	char *envp[] = {NULL};

		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
    	execve("/bin/ping", argv, envp);
	}
	pid2 = fork();
	if (pid2 < 0)
		return (1);
	if (pid2 == 0)
	{
		// Child 1 (grep)
		char *argv[] = {"grep", "rtt", NULL};
    	char *envp[] = {NULL};

		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
    	execve("/bin/grep", argv, envp);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
	return (0);
}

/**
 * Pour cette exemple
 * Parent => initialise x = 0
 * Child1 => reçoit x et envoie x + 5 à Child2
 * Child2 => reçoit x + 5 et envoie x + 5 à Parent
 * Parent => reçoit le total soit x + 10 et l'affiche
 * 
 * Pipes
 * pipefd[0] => Communication P -> Child1
 * pipefd[1] => Communication Child1 -> Child2
 * pipefd[2] => Communication Child2 -> P
 */
int	three_pipes()
{
	int		pipefd[3][2];
	int		i;
	int		status1;
	int		status2;
	pid_t	pid1;
	pid_t	pid2;

	i = 0;
	while (i < 3)
	{
		if (pipe(pipefd[i]) < 0)
			// il faudrait fermer les pipes deja creer 
			return (1);
		i++;
	}

	pid1 = fork();
	if (pid1 < 0)
		return (1);
	if (pid1 == 0)
	{
		// Child1
		int	x;
		
		close(pipefd[0][1]);
		close(pipefd[1][0]);
		close(pipefd[2][0]);
		close(pipefd[2][1]);
		if (read(pipefd[0][0], &x, sizeof(int)) < 0)
			return (1);
		x += 5;
		if (write(pipefd[1][1], &x, sizeof(int)) < 0)
			return (1);
		close(pipefd[0][0]);
		close(pipefd[1][1]);
		return (0); // Pour que Child1 ne fasse plus rien apres
	}

	pid2 = fork();
	if (pid2 < 0)
		return (1);
	if (pid2 == 0)
	{
		// Child2
		int	x;
		
		close(pipefd[0][0]);
		close(pipefd[0][1]);
		close(pipefd[1][1]);
		close(pipefd[2][0]);
		if (read(pipefd[1][0], &x, sizeof(int)) < 0)
			return (1);
		x += 5;
		if (write(pipefd[2][1], &x, sizeof(int)) < 0)
			return (1);
		close(pipefd[1][0]);
		close(pipefd[2][1]);
		return (0); // Pour que Child2 ne fasse plus rien apres
	}
	
	// Parent
	int	x;

	close(pipefd[0][0]);
	close(pipefd[1][0]);
	close(pipefd[1][1]);
	close(pipefd[2][1]);
	x = 0;
	if (write(pipefd[0][1], &x, sizeof(int)) < 0)
		return (1);
	if (read(pipefd[2][0], &x, sizeof(int)) < 0)
			return (1);
	ft_printf("Result is %d\n", x);
	close(pipefd[0][1]);
	close(pipefd[2][0]);
	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
	return (0);
}

/**
 * Pour cette exemple
 * Parent => initialise x = 5
 * Child1 => reçoit x et envoie x + 1 à Child2
 * Child2 => reçoit x + 1 et envoie x + 1 à Child3
 * etc...
 * puis a la fin
 * Parent => reçoit le total soit x + (1 * nchild) et l'affiche
 * 
 * PROBLEME, la façon dont c'est fait ne permet pas de depasser 509 pipes.
 * il faudra modif le code pour fermer les pipes plutot et creer que ceux necessaire
 * pas tous d'un coup.
 */

# define PROCESS_NUM 500 // simuler x proccess mais il faudra calculer ce nombre pour l'avoir dynamiquement
int multiple_pipes()
{
	pid_t	pids[PROCESS_NUM];
	int		pipefd[PROCESS_NUM + 1][2];
	int		status[PROCESS_NUM];
	int		i;
	
	i = 0;
	while (i < PROCESS_NUM + 1)
	{
		if (pipe(pipefd[i]) == -1)
		{
			ft_printf("Error with creating pipe i = %d\n", i);
			return (1);
		}
		i++;
	}

	i = 0;
	while (i < PROCESS_NUM)
	{
		pids[i] = fork();
		if (pids[i] < 0)
		{
			ft_printf("Error with creating process i = %d\n", i);
			return (1);
		}
		if (pids[i] == 0)
		{
			// Child Process
			int j;
			
			j = 0;
			while (j < PROCESS_NUM + 1)
			{
				if (i != j)
					close(pipefd[j][0]);
				if (i + 1 != j)
					close(pipefd[j][1]);
				j++;
			}
			
			int	x;
			
			if (read(pipefd[i][0], &x, sizeof(int)) < 0)
			{
				ft_printf("Error at reading\n");
				return (1);
			}
			printf("(%d) Got %d\n", i, x);
			x++;
			if (write(pipefd[i + 1][1], &x, sizeof(int)) < 0)
			{
				ft_printf("Error at writing\n");
				return (1);
			}
			printf("(%d) Sent %d\n", i, x);
			close(pipefd[i][0]);
			close(pipefd[i + 1][1]);
			return (0);
		}
		i++;
	}

	// Parent
	int	y;
	int j;
			
	j = 0;
	while (j < PROCESS_NUM + 1)
	{
		if (j != PROCESS_NUM)
			close(pipefd[j][0]);
		if (j != 0)
			close(pipefd[j][1]);
		j++;
	}
	y = 5;
	printf("Main process sent %d\n", y);
	if (write(pipefd[0][1], &y, sizeof(int)) < 0)
	{
		ft_printf("Error at writing\n");
		return (1);
	}
	if (read(pipefd[PROCESS_NUM][0], &y, sizeof(int)) < 0)
	{
		ft_printf("Error at reading\n");
		return (1);
	}
	close(pipefd[0][1]);
	close(pipefd[PROCESS_NUM][0]);
	printf("The final result is %d\n", y);
	
	i = 0;
	while (i < PROCESS_NUM)
	{
		waitpid(pids[i], &status[i], 0);
		i++;
	}
	return (0);
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	multiple_pipes();

	// if (ac != 5)
	// {
	// 	ft_putstr_fd("Error usage: ./pipex file1 cmd1 cmd2 file2\n", 2);
	// 	return (1);
	// }
	// if (access(av[2], F_OK | X_OK))
	// 	perror(av[2]);
	// if (access(av[3], F_OK | X_OK))
	// 	perror(av[3]);
	return 0;
}

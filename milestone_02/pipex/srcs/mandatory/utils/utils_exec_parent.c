/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec_parent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:40:20 by achauvie          #+#    #+#             */
/*   Updated: 2026/01/19 11:13:31 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	infile_to_pipe(t_pipex *data)
{
	int	fd;

	close(data->pipefd[0][0]);
	dup2(data->pipefd[0][1], STDOUT_FILENO);
	close(data->pipefd[0][1]);
	fd = open_file(data, data->argv[1], 1);
	if (fd >= 0)
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
}

void	pipe_to_pipe(t_pipex *data, size_t cmd_nb)
{
	close(data->pipefd[cmd_nb - 1][1]);
	close(data->pipefd[cmd_nb][0]);
	dup2(data->pipefd[cmd_nb - 1][0], STDIN_FILENO);
	close(data->pipefd[cmd_nb - 1][0]);
	dup2(data->pipefd[cmd_nb][1], STDOUT_FILENO);
	close(data->pipefd[cmd_nb][1]);
}

void	pipe_to_outfile(t_pipex *data, size_t cmd_nb)
{
	int	fd;

	close(data->pipefd[cmd_nb - 1][1]);
	dup2(data->pipefd[cmd_nb - 1][0], STDIN_FILENO);
	close(data->pipefd[cmd_nb - 1][0]);
	fd = open_file(data, data->argv[data->argc - 1], 0);
	if (fd >= 0)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
}

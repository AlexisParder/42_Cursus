/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 11:01:48 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/03 11:01:59 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	init_heredoc_part_2(t_redirs *redir, int *pipe_fd, int fd_stdin_b)
{
	if (dup2(fd_stdin_b, STDIN_FILENO) < 0)
	{
		err_close_fd(fd_stdin_b, pipe_fd);
		return (1);
	}
	manage_signals();
	close(fd_stdin_b);
	close(pipe_fd[1]);
	redir->heredoc_fd = pipe_fd[0];
	return (0);
}

int	init_heredoc(t_minishell *data, t_redirs *redir)
{
	int	pipe_fd[2];
	int	fd_stdin_backup;

	if (pipe(pipe_fd) < 0)
	{
		perror("minishell: pipe");
		return (1);
	}
	fd_stdin_backup = dup(STDIN_FILENO);
	if (fd_stdin_backup < 0)
		err_close_fd(fd_stdin_backup, pipe_fd);
	if (fd_stdin_backup < 0)
		return (1);
	manage_signals_heredoc();
	write_heredoc(data, pipe_fd[1], redir->file, redir->quote);
	if (init_heredoc_part_2(redir, pipe_fd, fd_stdin_backup))
		return (1);
	if (data->return_code == 130)
		return (1);
	return (0);
}

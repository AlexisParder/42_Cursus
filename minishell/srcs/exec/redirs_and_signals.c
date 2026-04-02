/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs_and_signals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 09:22:50 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/01 09:15:08 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	open_file(t_redirs *redir)
{
	int	fd;

	if (redir->type == REDIR_IN)
		fd = open(redir->file, O_RDONLY);
	else if (redir->type == REDIR_OUT)
		fd = open(redir->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(redir->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
	{
		perror(redir->file);
		return (-1);
	}
	return (fd);
}

static int	create_redir_heredoc(t_redirs *redir)
{
	if (dup2(redir->heredoc_fd, STDIN_FILENO) < 0)
	{
		close(redir->heredoc_fd);
		return (-1);
	}
	close(redir->heredoc_fd);
	return (0);
}

static int	create_redir(t_redirs *redir)
{
	int	fd;
	int	fd2;
	int	res;

	if (redir->type == HEREDOC)
	{
		res = create_redir_heredoc(redir);
		return (res);
	}
	fd = open_file(redir);
	fd2 = -1;
	if (fd < 0)
		return (fd);
	if (redir->type == REDIR_IN)
		fd2 = STDIN_FILENO;
	else if (redir->type == REDIR_OUT || redir->type == REDIR_APPEND)
		fd2 = STDOUT_FILENO;
	if (fd2 < 0 || dup2(fd, fd2) < 0)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}

int	apply_redirs(t_redirs *redirs)
{
	t_redirs	*current;

	current = redirs;
	while (current)
	{
		if (create_redir(current) < 0)
			return (-1);
		current = current->next;
	}
	return (0);
}

void	exec_child_signals(t_cmd *cmd)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (is_builtin(cmd))
		signal(SIGPIPE, SIG_IGN);
	else
		signal(SIGPIPE, SIG_DFL);
}

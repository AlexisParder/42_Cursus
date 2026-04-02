/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:00:50 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/01 12:50:37 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	write_heredoc(t_minishell *data, int fd, char *limiter, char quote)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (g_signal == 130 || !line)
		{
			manage_err_sig(data, line, limiter);
			break ;
		}
		if (!ft_strncmp(line, limiter, ft_strlen(limiter) + 1))
		{
			free(line);
			break ;
		}
		if (quote)
			ft_putstr_fd(line, fd);
		else
			expand_heredoc(data, line, fd);
		ft_putstr_fd("\n", fd);
		free(line);
	}
}

static int	init_heredoc(t_minishell *data, t_redirs *redir)
{
	int	pipe_fd[2];
	int	fd_stdin_backup;

	if (pipe(pipe_fd) < 0)
	{
		perror("minishell: pipe");
		return (1);
	}
	fd_stdin_backup = dup(STDIN_FILENO);
	manage_signals_heredoc();
	write_heredoc(data, pipe_fd[1], redir->file, redir->quote);
	dup2(fd_stdin_backup, STDIN_FILENO);
	manage_signals();
	close(fd_stdin_backup);
	close(pipe_fd[1]);
	redir->heredoc_fd = pipe_fd[0];
	if (data->return_code == 130)
		return (1);
	return (0);
}

int	create_heredoc(t_minishell *data)
{
	t_cmd		*current_cmd;
	t_redirs	*current_redir;

	current_cmd = data->cmds;
	while (current_cmd)
	{
		current_redir = current_cmd->redirs;
		while (current_redir)
		{
			if (current_redir->type == HEREDOC)
			{
				if (init_heredoc(data, current_redir))
				{
					close(current_redir->heredoc_fd);
					return (-1);
				}
			}
			current_redir = current_redir->next;
		}
		current_cmd = current_cmd->next;
	}
	return (0);
}

void	close_other_heredocs(t_minishell *data, t_cmd *current_cmd)
{
	t_cmd		*cmd;
	t_redirs	*redir;

	cmd = data->cmds;
	while (cmd)
	{
		redir = cmd->redirs;
		while (redir)
		{
			if (redir->type == HEREDOC && redir->heredoc_fd >= 0
				&& cmd != current_cmd)
			{
				close(redir->heredoc_fd);
				redir->heredoc_fd = -1;
			}
			redir = redir->next;
		}
		cmd = cmd->next;
	}
}

void	close_parent_heredocs(t_cmd *cmd)
{
	t_redirs	*redir;

	redir = cmd->redirs;
	while (redir)
	{
		if (redir->type == HEREDOC && redir->heredoc_fd >= 0)
		{
			close(redir->heredoc_fd);
			redir->heredoc_fd = -1;
		}
		redir = redir->next;
	}
}

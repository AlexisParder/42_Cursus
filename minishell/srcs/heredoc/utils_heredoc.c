/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 13:56:49 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/03 10:41:47 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*manage_arg(t_minishell *data, char *line, size_t *i)
{
	char	*tmp;

	if (line[*i + 1] == '?')
	{
		tmp = ft_itoa(data->return_code);
		(*i) += 2;
		return (tmp);
	}
	else if (line[*i + 1] && (ft_isalnum(line[*i + 1])
			|| line[*i + 1] == '_'))
	{
		tmp = get_var(data, line, i);
		return (tmp);
	}
	else
		(*i)++;
	return (NULL);
}

static char	*get_value(t_minishell *data, char *line, size_t *i)
{
	char	*tmp;
	char	c;

	if (line[*i] == '$' && line[*i + 1]
		&& !ft_isspace(line[*i + 1]))
	{
		tmp = manage_arg(data, line, i);
		if (tmp && line[*i - 1] != '?')
			tmp = ft_strdup(tmp);
		return (tmp);
	}
	c = line[*i];
	(*i)++;
	tmp = ft_calloc(2, sizeof(char));
	if (!tmp)
		return (NULL);
	tmp[0] = c;
	return (tmp);
}

void	expand_heredoc(t_minishell *data, char *line, int fd)
{
	size_t	i;
	char	*tmp;
	char	*expanded_arg;

	i = 0;
	expanded_arg = NULL;
	while (line[i])
	{
		tmp = get_value(data, line, &i);
		if (!tmp)
			continue ;
		expanded_arg = ft_strjoin_free(expanded_arg, tmp);
		free(tmp);
	}
	ft_putstr_fd(expanded_arg, fd);
	free(expanded_arg);
}

void	manage_err_sig(t_minishell *data, char *line, char *limiter)
{
	if (!line && g_signal != 130)
	{
		ft_dprintf(2, "minishell: warning: here-document delimited");
		ft_dprintf(2, " by end-of-file (wanted `%s`)\n", limiter);
	}
	data->return_code = g_signal;
}

void	err_close_fd(int fd_stdin_backup, int *pipe_fd)
{
	if (fd_stdin_backup >= 0)
		close(fd_stdin_backup);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:23:52 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/01 13:30:16 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	free_tokens(t_minishell *data)
{
	t_token	*tmp;

	if (!data->tokens)
		return ;
	while (data->tokens)
	{
		tmp = data->tokens->next;
		free(data->tokens->value);
		free(data->tokens);
		data->tokens = tmp;
	}
	data->tokens = NULL;
}

void	free_cmds(t_minishell *data)
{
	t_cmd		*tmp_cmd;
	t_redirs	*tmp_redir;

	if (!data->cmds)
		return ;
	while (data->cmds)
	{
		tmp_cmd = data->cmds->next;
		while (data->cmds->redirs)
		{
			tmp_redir = data->cmds->redirs->next;
			free(data->cmds->redirs->file);
			free(data->cmds->redirs);
			data->cmds->redirs = tmp_redir;
		}
		ft_free_arr(data->cmds->args);
		ft_free_arr(data->cmds->args_backup);
		free(data->cmds->quotes);
		free(data->cmds->separators);
		free(data->cmds->path);
		free(data->cmds);
		data->cmds = tmp_cmd;
	}
	data->cmds = NULL;
}

void	free_all(t_minishell *data)
{
	size_t	i;

	if (!data)
		return ;
	free_tokens(data);
	free_cmds(data);
	if (data->status)
		free(data->status);
	data->status = NULL;
	if (data->pid)
		free(data->pid);
	data->pid = NULL;
	i = 0;
	if (data->pipefd)
	{
		while (i < (data->nb_cmds - 1) && data->pipefd[i])
		{
			free(data->pipefd[i]);
			i++;
		}
		free(data->pipefd);
		data->pipefd = NULL;
	}
}

void	clean_main(t_minishell *data, char *line)
{
	if (data->dev_null_fd != -1)
		close(data->dev_null_fd);
	free(line);
	rl_clear_history();
	ft_free_arr(data->envp);
	ft_free_arr(data->exports);
	free_all(data);
}

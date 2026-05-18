/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 08:52:51 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/02 15:29:47 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static size_t	count_args(t_token *start)
{
	size_t	count;
	t_token	*current;

	count = 0;
	current = start;
	while (current && current->type != PIPE)
	{
		if (current->type == WORD)
			count++;
		else if (current->type >= REDIR_IN && current->type <= HEREDOC)
			current = current->next;
		if (current)
			current = current->next;
	}
	return (count);
}

static int	cmd_alloc_sep(t_cmd *tmp_cmd, size_t nb_args)
{
	tmp_cmd->separators = ft_calloc(nb_args + 1, sizeof(int));
	if (!tmp_cmd->separators)
	{
		free(tmp_cmd->args);
		free(tmp_cmd->args_backup);
		free(tmp_cmd->quotes);
		free(tmp_cmd);
		return (1);
	}
	return (0);
}

static	void	err_free(t_cmd *tmp_cmd)
{
	free(tmp_cmd->args);
	free(tmp_cmd->args_backup);
	free(tmp_cmd);
}

static t_cmd	*cmd_alloc(t_token	*tmp_token)
{
	t_cmd	*tmp_cmd;
	size_t	nb_args;

	tmp_cmd = ft_calloc(1, sizeof(t_cmd));
	if (!tmp_cmd)
		return (NULL);
	nb_args = count_args(tmp_token);
	tmp_cmd->args = ft_calloc(nb_args + 1, sizeof(char *));
	tmp_cmd->args_backup = ft_calloc(nb_args + 1, sizeof(char *));
	if (!tmp_cmd->args || !tmp_cmd->args_backup)
	{
		err_free(tmp_cmd);
		return (NULL);
	}
	tmp_cmd->quotes = ft_calloc(nb_args + 1, sizeof(char));
	if (!tmp_cmd->quotes)
	{
		err_free(tmp_cmd);
		return (NULL);
	}
	if (cmd_alloc_sep(tmp_cmd, nb_args))
		return (NULL);
	return (tmp_cmd);
}

int	fill_cmds(t_minishell *data)
{
	t_cmd	*tmp_cmd;
	t_token	*tmp_token;
	t_cmd	*last_cmd;

	tmp_token = data->tokens;
	data->nb_cmds = 0;
	while (tmp_token)
	{
		tmp_cmd = cmd_alloc(tmp_token);
		if (!tmp_cmd)
			return (1);
		if (add_cmd(tmp_cmd, tmp_token))
			return (1);
		last_cmd = lst_cmdlast(data->cmds);
		if (last_cmd)
			last_cmd->next = tmp_cmd;
		else
			data->cmds = tmp_cmd;
		while (tmp_token && tmp_token->type != PIPE)
			tmp_token = tmp_token->next;
		if (tmp_token && tmp_token->type == PIPE)
			tmp_token = tmp_token->next;
		data->nb_cmds++;
	}
	return (0);
}

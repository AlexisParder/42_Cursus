/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fill_cmds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 09:28:01 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/01 15:31:46 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	free_tmp_cmd(t_cmd *tmp_cmd)
{
	free(tmp_cmd->quotes);
	free(tmp_cmd->separators);
	ft_free_arr(tmp_cmd->args);
	ft_free_arr(tmp_cmd->args_backup);
	free(tmp_cmd);
}

static int	build_file_name(t_cmd *cmd, t_redirs *redir, t_token **token)
{
	char	*file;

	file = ft_strdup((*token)->value);
	if (!file)
	{
		free_tmp_cmd(cmd);
		free(redir);
		return (1);
	}
	while ((*token)->next && !(*token)->sep && (*token)->next->type == WORD)
	{
		*token = (*token)->next;
		file = ft_strjoin_free(file, (*token)->value);
		if (!file)
		{
			free_tmp_cmd(cmd);
			free(redir);
			return (1);
		}
	}
	redir->file = file;
	return (0);
}

static int	add_redir(t_cmd *cmd, t_token **token)
{
	t_redirs	*tmp_redir;
	t_redirs	*last_redir;

	tmp_redir = ft_calloc(1, sizeof(t_redirs));
	if (!tmp_redir || !*token || !(*token)->next)
	{
		free_tmp_cmd(cmd);
		free(tmp_redir);
		return (1);
	}
	tmp_redir->type = (*token)->type;
	*token = (*token)->next;
	tmp_redir->quote = (*token)->quote;
	if (build_file_name(cmd, tmp_redir, token))
		return (1);
	tmp_redir->heredoc_fd = -1;
	tmp_redir->next = NULL;
	last_redir = lst_redirlast(cmd->redirs);
	if (last_redir)
		last_redir->next = tmp_redir;
	else
		cmd->redirs = tmp_redir;
	return (0);
}

static int	add_arg(t_cmd *cmd, t_token *token, size_t *index)
{
	cmd->args[*index] = ft_strdup(token->value);
	cmd->args_backup[*index] = ft_strdup(token->value);
	if (!cmd->args[*index] || !cmd->args_backup[*index])
	{
		free_tmp_cmd(cmd);
		return (1);
	}
	cmd->quotes[*index] = token->quote;
	cmd->separators[*index] = token->sep;
	cmd->nb_args++;
	cmd->err_path = 0;
	cmd->path = NULL;
	(*index)++;
	return (0);
}

int	add_cmd(t_cmd *cmd, t_token *token)
{
	size_t	i;
	t_token	*tmp_token;

	i = 0;
	tmp_token = token;
	cmd->redirs = NULL;
	cmd->nb_args = 0;
	cmd->next = NULL;
	while (tmp_token && tmp_token->type != PIPE)
	{
		if (tmp_token->type == WORD)
		{
			if (add_arg(cmd, tmp_token, &i))
				return (1);
		}
		else if (tmp_token->type >= REDIR_IN && tmp_token->type <= HEREDOC)
		{
			if (add_redir(cmd, &tmp_token))
				return (1);
		}
		tmp_token = tmp_token->next;
	}
	return (0);
}

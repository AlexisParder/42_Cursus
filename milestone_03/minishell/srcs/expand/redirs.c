/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 15:01:44 by tjourdai          #+#    #+#             */
/*   Updated: 2026/04/02 16:38:56 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*expand_dollar(t_minishell *data, char *file, size_t *j)
{
	char	*tmp;

	if (file[*j + 1] == '?')
	{
		tmp = ft_itoa(data->return_code);
		*j += 2;
	}
	else if (ft_isalnum(file[*j + 1]) || file[*j + 1] == '_')
	{
		tmp = get_var(data, file, j);
		if (tmp)
			tmp = ft_strdup(tmp);
	}
	else
	{
		(*j)++;
		tmp = NULL;
	}
	return (tmp);
}

static char	*build_expanded(char *file, size_t *j, char *exp, char *tmp)
{
	tmp = ft_calloc(2, sizeof(char));
	if (!tmp)
		return (NULL);
	if (tmp)
	{
		tmp[0] = file[*j];
		(*j)++;
	}
	if (tmp)
	{
		exp = ft_strjoin_free(exp, tmp);
		free(tmp);
	}
	return (exp);
}

static void	updt_redir_file(char *expand, t_redirs *redir)
{
	free(redir->file);
	if (!expand)
		redir->file = ft_strdup("");
	else
		redir->file = ft_strdup(expand);
	free(expand);
}

static int	expand_redir_file(t_minishell *data, t_redirs *redir, char *expand)
{
	size_t	j;
	char	*tmp;

	j = 0;
	while (redir->file[j])
	{
		if (redir->file[j] == '$' && redir->file[j + 1]
			&& !ft_isspace(redir->file[j + 1]))
		{
			tmp = expand_dollar(data, redir->file, &j);
			if (tmp)
			{
				expand = ft_strjoin_free(expand, tmp);
				free(tmp);
			}
		}
		else
		{
			expand = build_expanded(redir->file, &j, expand, NULL);
			if (!expand)
				return (1);
		}
	}
	updt_redir_file(expand, redir);
	return (0);
}

int	expand_redirs(t_minishell *data, t_cmd *cmd)
{
	t_redirs	*redir;
	char		*expand;

	redir = cmd->redirs;
	expand = NULL;
	while (redir)
	{
		if (redir->type != HEREDOC && redir->file)
		{
			if (expand_redir_file(data, redir, expand))
				return (1);
		}
		redir = redir->next;
	}
	return (0);
}

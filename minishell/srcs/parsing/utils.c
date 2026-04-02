/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:00:36 by tjourdai          #+#    #+#             */
/*   Updated: 2026/04/01 15:29:59 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	is_quote(char c)
{
	if (c == '"' || c == '\'')
		return (c);
	return (0);
}

static t_type	get_type(char *str, char c)
{
	size_t	len;

	len = ft_strlen(str);
	if (len > 0 && ft_strncmp(str, "|", len) == 0 && !c)
		return (PIPE);
	else if (len > 0 && ft_strncmp(str, "<", len) == 0 && !c)
		return (REDIR_IN);
	else if (len > 0 && ft_strncmp(str, ">", len) == 0 && !c)
		return (REDIR_OUT);
	else if (len > 0 && ft_strncmp(str, ">>", len) == 0 && !c)
		return (REDIR_APPEND);
	else if (len > 0 && ft_strncmp(str, "<<", len) == 0 && !c)
		return (HEREDOC);
	return (WORD);
}

int	is_operator(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

int	get_operator_len(char *str, size_t i)
{
	if ((str[i] == '<' && str[i + 1] == '<')
		|| (str[i] == '>' && str[i + 1] == '>'))
		return (2);
	if (is_operator(str[i]))
		return (1);
	return (0);
}

int	new_token(t_minishell *data, char *value, char quote, int sep)
{
	t_token	*last;
	t_token	*node;

	node = malloc(sizeof(t_token));
	if (!node)
	{
		free(value);
		free_tokens(data);
		return (0);
	}
	node->type = get_type(value, quote);
	node->value = value;
	node->quote = quote;
	node->sep = sep;
	node->next = NULL;
	if (!data->tokens)
		data->tokens = node;
	else
	{
		last = lst_tokenlast(data->tokens);
		last->next = node;
	}
	return (1);
}

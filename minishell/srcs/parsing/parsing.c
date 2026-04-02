/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:17:15 by tjourdai          #+#    #+#             */
/*   Updated: 2026/03/27 13:26:35 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	handle_special_start(char *str, size_t *i)
{
	size_t	start;
	char	quote;

	if (str[*i] == '$')
	{
		(*i)++;
		while (str[*i]
			&& (ft_isalnum(str[*i]) || str[*i] == '_' || str[*i] == '?'))
			(*i)++;
		return (1);
	}
	if (is_quote(str[*i]))
	{
		start = *i;
		quote = str[*i];
		*i = skip_quoted_section(str, *i);
		if (quote == '"' && start + 1 < *i && str[start + 1] == '$')
			return (1);
		return (0);
	}
	return (0);
}

static int	extract_token(char *str, char **value, size_t i, size_t j)
{
	int		op_len;

	op_len = get_operator_len(str, i);
	if (op_len > 0)
	{
		*value = ft_substr(str, i, op_len);
		return (i + op_len);
	}
	if (handle_special_start(str, &i))
	{
		*value = ft_substr(str, j, i - j);
		return (i);
	}
	while (str[i] && !ft_isspace(str[i]) && !is_operator(str[i]))
	{
		if (str[i] == '$')
			break ;
		i = skip_quoted_section(str, i);
	}
	*value = ft_substr(str, j, i - j);
	return (i);
}

static void	tokenize_line(t_minishell *data, char *str)
{
	size_t	i;
	size_t	j;
	char	*value;

	i = 0;
	value = NULL;
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (!str[i])
			return ;
		j = i;
		i = extract_token(str, &value, i, j);
		if (!value)
		{
			free_tokens(data);
			return ;
		}
		value = remove_quotes(value);
		if (!new_token(data, value, is_quote(str[i - 1]), ft_isspace(str[i])))
			break ;
	}
}

static void	validate_token_sequence(t_minishell *data, t_token *lst)
{
	if (lst->type == REDIR_IN && (!lst->next || lst->type == REDIR_OUT))
	{
		ft_dprintf(2,
			"minishell: syntax error near unexpected token `newline'\n");
		free_tokens(data);
	}
	while (lst && lst->next)
	{
		if ((lst->type != WORD && lst->type != PIPE && lst->next->type != WORD)
			|| (lst->type != WORD && lst->type == lst->next->type))
		{
			ft_dprintf(2,
				"minishell: syntax error near unexpected token `%s`\n",
				lst->next->value);
			free_tokens(data);
			return ;
		}
		lst = lst->next;
	}
	if (lst && lst->type != WORD)
	{
		ft_dprintf(2,
			"minishell: syntax error near unexpected token `newline'\n");
		free_tokens(data);
	}
}

void	pars_line(t_minishell *data, char *str)
{
	t_token	*lst;

	if (!quote_is_valid(str))
		return ;
	tokenize_line(data, str);
	lst = data->tokens;
	if (lst && lst->type == PIPE)
	{
		ft_dprintf(2, "minishell: syntax error near unexpected token `|`\n");
		free_tokens(data);
		return ;
	}
	validate_token_sequence(data, lst);
}

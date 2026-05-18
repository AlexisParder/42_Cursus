/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:42:34 by tjourdai          #+#    #+#             */
/*   Updated: 2026/03/27 13:26:35 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	quote_is_valid(char *str)
{
	size_t	i;
	char	quote;
	char	select_quote;

	i = 0;
	quote = 0;
	select_quote = 0;
	while (str[i])
	{
		quote = is_quote(str[i]);
		if (quote && select_quote == 0)
			select_quote = quote;
		else if (quote && select_quote == quote)
			select_quote = 0;
		i++;
	}
	if (select_quote)
		ft_dprintf(2, "minishell: syntax error unclosed quote\n");
	return (!select_quote);
}

char	*remove_quotes(char *str)
{
	char	quote;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		quote = is_quote(str[i]);
		if (str[i] == quote)
		{
			i++;
			while (str[i] && str[i] != quote)
				str[j++] = str[i++];
			if (str[i])
				i++;
		}
		else
			str[j++] = str[i++];
	}
	str[j] = '\0';
	return (str);
}

int	skip_quoted_section(char *str, size_t i)
{
	char	quote;

	quote = is_quote(str[i]);
	if (quote)
	{
		i++;
		while (str[i] && str[i] != quote)
			i++;
		if (str[i] == quote)
			i++;
	}
	else
		i++;
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_with_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:40:21 by achauvie          #+#    #+#             */
/*   Updated: 2026/01/13 12:22:08 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	sz_substr(char const *s, size_t start, size_t in_quote, char c)
{
	size_t	i;

	i = 0;
	while (!in_quote && s[start + i] && !ft_isspace(s[start + i]))
		i++;
	while (in_quote && s[start + i] && s[start + i] != c)
		i++;
	return (i);
}

static size_t	count_set(char const *src)
{
	size_t	i;
	size_t	count;
	size_t	s_len;

	i = 0;
	count = 0;
	if (src == NULL)
		return (1);
	s_len = ft_strlen(src);
	while (src[i] && i <= s_len)
	{
		if (!ft_isspace(src[i]) && src[i] != '"' && src[i] != '\'')
		{
			count++;
			i += sz_substr(src, i, 0, 0) - 1;
		}
		else if (src[i] == '"' || src[i] == '\'')
		{
			count++;
			i += sz_substr(src, i, 1, src[i]) + 1;
		}
		i++;
	}
	return (count);
}

static size_t	check_arr(char **arr, size_t k)
{
	size_t	i;

	if (arr[k] == NULL)
	{
		i = 0;
		while (arr[i])
			free(arr[i++]);
		free(arr);
		return (0);
	}
	return (1);
}

static void	parse_word(char const *s, char **arr, size_t *i, size_t *k)
{
	int		in_quote;
	char	quote_char;

	in_quote = 0;
	quote_char = 0;
	if (s[*i] == '"' || s[*i] == '\'')
	{
		in_quote = 1;
		quote_char = s[*i];
		(*i)++;
	}
	arr[*k] = ft_substr(s, *i, sz_substr(s, *i, in_quote, quote_char));
	if (!check_arr(arr, *k))
		return ;
	(*k)++;
	*i += sz_substr(s, *i, in_quote, quote_char);
	if (in_quote && (s[*i] == '"' || s[*i] == '\''))
		(*i)++;
}

char	**split_with_quote(char const *s)
{
	size_t	nb_rep;
	size_t	i;
	size_t	k;
	char	**arr;

	nb_rep = count_set(s);
	arr = ft_calloc((nb_rep + 1), sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	k = 0;
	while (s && s[i])
	{
		if (!ft_isspace(s[i]))
			parse_word(s, arr, &i, &k);
		else
			i++;
	}
	return (arr);
}

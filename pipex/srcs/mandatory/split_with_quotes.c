/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_with_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:40:21 by achauvie          #+#    #+#             */
/*   Updated: 2026/01/12 10:20:55 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_substr(char const *s, unsigned int start, int in_quote, char c)
{
	int	i;

	i = 0;
	while (!in_quote && s[start + i] && !ft_isspace(s[start + i]))
		i++;
	while (in_quote && s[start + i] && s[start + i] != c)
		i++;
	return (i);
}

static int	count_set(char const *src)
{
	int	i;
	int	count;
	int	s_len;

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
			i += size_substr(src, i, 0, 0) - 1;
		}
		else if (src[i] == '"' || src[i] == '\'')
		{
			count++;
			i += size_substr(src, i, 1, src[i]) + 1;
		}
		i++;
	}
	return (count);
}

static int	check_arr(char **arr, int k)
{
	int	i;

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

char	**split_with_quote(char const *s)
{
	int		nb_rep;
	int		i;
	int		k;
	char	**arr;

	nb_rep = count_set(s);
	arr = malloc((nb_rep + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr[nb_rep] = NULL;
	i = 0;
	k = 0;
	while (s != NULL && s[i])
	{
		if (!ft_isspace(s[i]) && s[i] != '"' && s[i] != '\'')
		{
			arr[k] = ft_substr(s, i, size_substr(s, i, 0, 0));
			if (!check_arr(arr, k))
				return (NULL);
			k++;
			i += size_substr(s, i, 0, 0) - 1;
		}
		else if (s[i] == '"' || s[i] == '\'')
		{
			i++;
			arr[k] = ft_substr(s, i, size_substr(s, i, 1, s[i - 1]));
			if (!check_arr(arr, k))
				return (NULL);
			k++;
			i += size_substr(s, i, 1, s[i - 1]);
		}
		i++;
	}
	return (arr);
}

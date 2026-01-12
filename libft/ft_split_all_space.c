/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_all_space.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:40:21 by achauvie          #+#    #+#             */
/*   Updated: 2026/01/12 10:52:15 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	size_substr(char const *s, size_t start)
{
	size_t	i;

	i = 0;
	while (s[start + i] && !ft_isspace(s[start + i]))
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
		if (!ft_isspace(src[i]))
		{
			count++;
			i += size_substr(src, i) - 1;
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

char	**ft_split_all_space(char const *s)
{
	size_t	nb_rep;
	size_t	i;
	size_t	k;
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
		if (!ft_isspace(s[i]))
		{
			arr[k] = ft_substr(s, i, size_substr(s, i));
			if (!check_arr(arr, k))
				return (NULL);
			k++;
			i += size_substr(s, i) - 1;
		}
		i++;
	}
	return (arr);
}

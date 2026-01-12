/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_all_space.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:40:21 by achauvie          #+#    #+#             */
/*   Updated: 2026/01/12 10:22:00 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_substr(char const *s, unsigned int start)
{
	int	i;

	i = 0;
	while (s[start + i] && !ft_isspace(s[start + i]))
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
		if (!ft_isspace(src[i]))
		{
			count++;
			i += size_substr(src, i) - 1;
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

char	**ft_split_all_space(char const *s)
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

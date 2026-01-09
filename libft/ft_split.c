/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:40:21 by achauvie          #+#    #+#             */
/*   Updated: 2026/01/09 08:51:11 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_substr(char const *s, unsigned int start, char sep)
{
	int	i;

	i = 0;
	while (s[start + i] && s[start + i] != sep)
		i++;
	return (i);
}

static int	count_set(char const *src, char set)
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
		if (src[i] != set)
		{
			count++;
			i += size_substr(src, i, set) - 1;
		}
		i++;
	}
	return (count);
}

static int	check_tab(char **tab, int k)
{
	int	i;

	if (tab[k] == NULL)
	{
		i = 0;
		while (tab[i])
			free(tab[i++]);
		free(tab);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		nb_rep;
	int		i;
	int		k;
	char	**tab;

	nb_rep = count_set(s, c);
	tab = malloc((nb_rep + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab[nb_rep] = NULL;
	i = 0;
	k = 0;
	while (s != NULL && s[i])
	{
		if (s[i] != c)
		{
			tab[k] = ft_substr(s, i, size_substr(s, i, c));
			if (!check_tab(tab, k))
				return (NULL);
			k++;
			i += size_substr(s, i, c) - 1;
		}
		i++;
	}
	return (tab);
}

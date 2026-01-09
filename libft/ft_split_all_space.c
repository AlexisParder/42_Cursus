/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_all_space.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:40:21 by achauvie          #+#    #+#             */
/*   Updated: 2026/01/09 08:38:17 by achauvie         ###   ########.fr       */
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

char	**ft_split_all_space(char const *s)
{
	int		nb_rep;
	int		i;
	int		k;
	char	**tab;

	nb_rep = count_set(s);
	tab = malloc((nb_rep + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab[nb_rep] = NULL;
	i = 0;
	k = 0;
	while (s != NULL && s[i])
	{
		if (!ft_isspace(s[i]))
		{
			tab[k] = ft_substr(s, i, size_substr(s, i));
			if (!check_tab(tab, k))
				return (NULL);
			k++;
			i += size_substr(s, i) - 1;
		}
		i++;
	}
	return (tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:39:48 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/29 09:01:45 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_sz(char const *s, unsigned int start, size_t len, size_t s_len)
{
	unsigned int	count;
	unsigned int	i;

	count = 0;
	if (len > s_len)
		len = s_len;
	if ((int)len <= 0 || start >= s_len)
		return (1);
	i = start;
	while (s[i])
	{
		count++;
		i++;
	}
	if (len > count)
		len = count;
	return (len + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	s_len;
	unsigned int	real_len;
	unsigned int	i;
	char			*subs;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	real_len = calc_sz(s, start, len, s_len);
	subs = malloc((real_len) * sizeof(char));
	if (!subs)
		return (NULL);
	subs[0] = '\0';
	if ((int)(real_len - 1) <= 0 || start >= s_len)
		return (subs);
	i = 0;
	while (i < (real_len - 1) && s[start + i])
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

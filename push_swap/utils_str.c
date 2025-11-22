/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:51:19 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/13 09:47:03 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ps_strcat_space(char *dest, char *src1, char *src2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src1[i])
	{
		dest[i] = src1[i];
		i++;
	}
	dest[i] = ' ';
	i++;
	while (src2[j])
	{
		dest[i + j] = src2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ps_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*s3;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		s3 = ft_strdup(s2);
		return (s3);
	}
	s1_len = 0;
	s2_len = 0;
	while (s1[s1_len])
		s1_len++;
	while (s2[s2_len])
		s2_len++;
	s3 = ft_calloc((s1_len + s2_len + 2), sizeof(char));
	if (!s3)
		return (NULL);
	ps_strcat_space(s3, s1, s2);
	free(s1);
	return (s3);
}

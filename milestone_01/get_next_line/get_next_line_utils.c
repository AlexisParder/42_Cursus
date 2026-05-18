/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:15:50 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/10 11:42:06 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strcat(char *dest, char *src1, char *src2)
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
	while (src2[j])
	{
		dest[i + j] = src2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*s3;

	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return (s1);
	s1_len = 0;
	s2_len = 0;
	while (s1[s1_len])
		s1_len++;
	while (s2[s2_len])
		s2_len++;
	s3 = ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (!s3)
		return (NULL);
	ft_strcat(s3, s1, s2);
	free(s1);
	return (s3);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	if (size != 0 && (nmemb * size) / size != nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

char    *ft_strchr(const char *s, int c)
{
    int    i;

    i = 0;
    if (!s)
        return (0);
    while (s[i])
    {
        if ((unsigned char)s[i] == (unsigned char)c)
            return ((char *) &s[i]);
        i++;
    }
    return (0);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		str_len;
	char	*s_cpy;

	i = 0;
	str_len = 0;
	while (s[str_len])
		str_len++;
	s_cpy = ft_calloc((str_len + 1), sizeof(char));
	if (!s_cpy)
		return (NULL);
	while (s && s[i])
	{
		s_cpy[i] = s[i];
		i++;
	}
	s_cpy[i] = '\0';
	return (s_cpy);
}

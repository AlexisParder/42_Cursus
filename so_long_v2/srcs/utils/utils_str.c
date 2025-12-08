/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 08:40:18 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/08 13:52:19 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

char	*sl_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	int		i;
	char	*s3;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		s3 = ft_strdup(s2);
		return (s3);
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2) + 1;
	s3 = malloc((s1_len + s2_len) * sizeof(char));
	if (!s3)
		return (NULL);
	i = 0;
	ft_strlcpy(s3, s1, s1_len + 1);
	ft_strlcat(s3, s2, s1_len + s2_len);
	free (s1);
	return (s3);
}

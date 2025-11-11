/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:15:14 by achauvie          #+#    #+#             */
/*   Updated: 2025/10/22 10:54:43 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	tmp_i;
	int	is_find;

	i = ft_strlen(s);
	tmp_i = i;
	is_find = 0;
	while (i >= 0)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
		{
			tmp_i = i;
			is_find = 1;
		}
		i--;
	}
	if (is_find)
		return ((char *)&s[tmp_i]);
	return (0);
}

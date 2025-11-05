/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:15:54 by achauvie          #+#    #+#             */
/*   Updated: 2025/10/22 10:03:25 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l_len;
	size_t	b_len;

	if (!*little)
		return ((char *)big);
	b_len = ft_strlen(big);
	if ((int)len < 0 || len > b_len)
		len = b_len;
	i = 0;
	l_len = ft_strlen(little);
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			j = i;
			while (big[j] == little[j - i] && j < len)
				j++;
			if (j - i == l_len)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}

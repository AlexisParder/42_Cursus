/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:40:28 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/01 13:28:16 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_int(long nbr)
{
	size_t	i;

	i = 1;
	if (nbr < 0)
		i++;
	while (nbr / 10)
	{
		i++;
		nbr /= 10;
	}
	return (i);
}

char	*ft_itoa(long nbr)
{
	size_t	size_int;
	char	*str;

	size_int = count_int(nbr);
	str = malloc((size_int + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (nbr == 0)
		str[0] = '0';
	str[size_int] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr)
	{
		size_int--;
		str[size_int] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}

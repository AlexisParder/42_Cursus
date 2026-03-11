/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_atol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:44:59 by achauvie          #+#    #+#             */
/*   Updated: 2026/03/11 09:45:13 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

long	philo_atol(const char *nptr)
{
	size_t	i;
	long	nb;
	long	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		nb *= 10;
		nb += (nptr[i] - 48);
		i++;
	}
	return (nb * sign);
}
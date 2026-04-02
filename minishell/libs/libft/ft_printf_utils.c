/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:40:18 by tjourdai          #+#    #+#             */
/*   Updated: 2026/03/10 14:33:54 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	pf_putnbr(int fd, unsigned long nbr, char *base, unsigned int b_len)
{
	int	count;

	count = 0;
	if (nbr >= b_len)
		count += pf_putnbr(fd, nbr / b_len, base, b_len);
	write(fd, &base[nbr % b_len], 1);
	return (count + 1);
}

int	pf_putnbr_len(int fd, long nbr, char c)
{
	int				count;
	unsigned long	num;

	count = 0;
	if (c == 'p' && nbr == 0)
		return (write(fd, "(nil)", 5));
	if ((c == 'd' || c == 'i') && nbr < 0)
	{
		count += write(fd, "-", 1);
		num = -nbr;
	}
	else
		num = (unsigned long)nbr;
	if (c == 'p')
		count += write(fd, "0x", 2);
	if (c == 'X')
		count += pf_putnbr(fd, num, "0123456789ABCDEF", 16);
	else if (c == 'x' || c == 'p')
		count += pf_putnbr(fd, num, "0123456789abcdef", 16);
	else
		count += pf_putnbr(fd, num, "0123456789", 10);
	return (count);
}

int	is_arguments_valid(const char c)
{
	int			i;
	const char	*formats;

	i = 0;
	formats = "cspdiuxX%";
	while (formats[i])
	{
		if (formats[i] == c)
			return (1);
		i++;
	}
	return (0);
}

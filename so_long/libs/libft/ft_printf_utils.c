/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:39:31 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/26 08:48:51 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	count_int(long n, int base_len)
{
	int			i;

	i = 1;
	if (n < 0)
		i++;
	while (n / base_len)
	{
		i++;
		n /= base_len;
	}
	return (i);
}

static int	count_long_int(long unsigned int n, int base_len)
{
	int			i;

	i = 1;
	if (n < 0)
		i++;
	while (n / base_len)
	{
		i++;
		n /= base_len;
	}
	return (i);
}

int	long_itoa(long n)
{
	int		size_int;
	char	*str;

	size_int = count_int(n, 10);
	str = malloc((size_int + 1) * sizeof(char));
	if (!str)
		return (0);
	if (n == 0)
		str[0] = '0';
	str[size_int] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n)
	{
		size_int--;
		str[size_int] = (n % 10) + '0';
		n /= 10;
	}
	size_int = putstr_len(str);
	free(str);
	return (size_int);
}

static void	itoa_hex_cvt(long unsigned int n, char *str, int size_int, char c)
{
	char	*base;

	base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n)
	{
		size_int--;
		str[size_int] = base[n % 16];
		n /= 16;
	}
}

int	long_itoa_hex(long unsigned int n, char c)
{
	int		size_int;
	char	*str;

	if (c != 'p')
		n = (unsigned int)n;
	if (c == 'p' && n == 0)
	{
		putstr_len("(nil)");
		return (5);
	}
	size_int = count_long_int(n, 16);
	str = malloc((size_int + 1) * sizeof(char));
	if (!str)
		return (0);
	if (n == 0)
		str[0] = '0';
	str[size_int] = '\0';
	itoa_hex_cvt(n, str, size_int, c);
	size_int = 0;
	if (c == 'p')
		size_int = putstr_len("0x");
	size_int += putstr_len(str);
	free(str);
	return (size_int);
}

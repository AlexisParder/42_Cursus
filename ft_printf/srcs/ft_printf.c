/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:59:09 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/04 15:15:30 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	check_is_arg(const char c1, const char c2)
{
	const char	*check_list;
	int			i;

	check_list = "cspdiuxX%";
	i = 0;
	while (c1 == '%' && check_list[i])
	{
		if (c2 == check_list[i])
			return (1);
		i++;
	}
	return (0);
}

static int	arg_switch_type(const char c, va_list vlst)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = putchar_len(va_arg(vlst, int));
	else if (c == 's')
		count = putstr_len(va_arg(vlst, char *));
	else if (c == 'i' || c == 'd')
		count = long_itoa(va_arg(vlst, int));
	else if (c == 'u')
		count = long_itoa(va_arg(vlst, unsigned int));
	else if (c == 'x' || c == 'X')
		count = long_itoa_hex(va_arg(vlst, unsigned int), c);
	else if (c == 'p')
		count = long_itoa_hex(va_arg(vlst, long long int), c);
	else if (c == '%')
		count = putchar_len('%');
	return (count);
}

static int	odd_percent(const char *s)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s && s[i])
	{
		if (s[i] == '%')
			count++;
		i++;
	}
	return (count % 2);
}

int	ft_printf(const char *arg_s, ...)
{
	va_list	vlst;
	int		i;
	int		count;

	if (!arg_s)
		return (-1);
	va_start(vlst, arg_s);
	i = 0;
	count = 0;
	while (arg_s[i])
	{
		if (arg_s[i] == '%' && arg_s[i + 1] == '\0' && odd_percent(arg_s))
		{
			count = -1;
			break ;
		}
		if (check_is_arg(arg_s[i], arg_s[i + 1]))
			count += arg_switch_type(arg_s[++i], vlst);
		else
			count += putchar_len(arg_s[i]);
		i++;
	}
	va_end(vlst);
	return (count);
}

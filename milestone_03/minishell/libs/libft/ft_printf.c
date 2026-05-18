/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 10:33:28 by tjourdai          #+#    #+#             */
/*   Updated: 2026/03/27 13:26:35 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	pf_putchar(int fd, char c)
{
	write(fd, &c, 1);
	return (1);
}

static int	pf_putstr(int fd, char *s)
{
	int	size;

	if (!s)
		s = "(null)";
	size = ft_strlen(s);
	write(fd, s, size);
	return (size);
}

static int	ft_printf_actions(int fd, char c, va_list list)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = pf_putchar(fd, va_arg(list, int));
	else if (c == 's')
		count = pf_putstr(fd, va_arg(list, char *));
	else if (c == '%')
		count = pf_putstr(fd, "%");
	else if (c == 'd' || c == 'i')
		count = pf_putnbr_len(fd, va_arg(list, int), c);
	else if (c == 'u' || c == 'x' || c == 'X')
		count = pf_putnbr_len(fd, va_arg(list, unsigned int), c);
	else if (c == 'p')
		count += pf_putnbr_len(fd, va_arg(list, long long int), c);
	return (count);
}

int	ft_dprintf(int fd, const char *args, ...)
{
	int		i;
	int		count;
	va_list	list;

	if (!args)
		return (-1);
	va_start(list, args);
	i = 0;
	count = 0;
	while (args[i])
	{
		if (args[i] == '%' && is_arguments_valid(args[i + 1]))
			count += ft_printf_actions(fd, args[++i], list);
		else
			count += pf_putchar(fd, args[i]);
		i++;
	}
	va_end(list);
	return (count);
}

int	ft_printf(const char *args, ...)
{
	int		i;
	int		count;
	va_list	list;

	if (!args)
		return (-1);
	va_start(list, args);
	i = 0;
	count = 0;
	while (args[i])
	{
		if (args[i] == '%' && is_arguments_valid(args[i + 1]))
			count += ft_printf_actions(1, args[++i], list);
		else
			count += pf_putchar(1, args[i]);
		i++;
	}
	va_end(list);
	return (count);
}

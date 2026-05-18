/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:41:04 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/04 13:50:32 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	putchar_len(char c)
{
	write(1, &c, 1);
	return (1);
}

int	putstr_len(char *s)
{
	int	s_len;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	s_len = ft_strlen(s);
	write(1, s, s_len);
	return (s_len);
}

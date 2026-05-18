/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 09:28:13 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/03 11:52:32 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *arg_s, ...)__attribute__((format(printf, 1, 2)));
int		long_itoa(long int n);
int		long_itoa_hex(long unsigned int n, char c);
size_t	ft_strlen(const char *s);
int		putchar_len(char c);
int		putstr_len(char *s);

#endif
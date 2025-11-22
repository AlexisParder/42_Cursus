/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:41:13 by achauvie          #+#    #+#             */
/*   Updated: 2025/10/27 08:50:10 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	s_len;

	if (s && fd > -1)
	{
		s_len = ft_strlen(s);
		write(fd, s, s_len);
		write(fd, "\n", 1);
	}
}

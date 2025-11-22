/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:15:32 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/21 14:14:59 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line_multiplefd(int fd)
{
	static char	*stash[1024];
	char		*line;
	char		*tmp;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash[fd])
		stash[fd] = ft_calloc(1, sizeof(char));
	stash[fd] = get_buf_data(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	tmp = get_new_stash(stash[fd]);
	line = extract_line(stash[fd]);
	free(stash[fd]);
	stash[fd] = tmp;
	return (line);
}

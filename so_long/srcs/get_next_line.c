/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:15:32 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/10 11:21:24 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static char	*new_get_buf_data(int fd, char *stash)
{
	long int	buffer;
	char		*buff;

	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff || !stash)
		return (NULL);
	buffer = 1;
	while (buffer > 0 && !ft_strchr(stash, '\n'))
	{
		buffer = read(fd, buff, BUFFER_SIZE);
		if (buffer < 0)
		{
			free(buff);
			free(stash);
			return (NULL);
		}
		buff[buffer] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	free(buff);
	return (stash);
}

static char	*new_get_new_stash(char *stash)
{
	char	*cut;
	size_t	i;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i] || !stash[i + 1])
		return (NULL);
	cut = ft_strdup(&stash[i + 1]);
	if (!cut)
		return (NULL);
	stash[i + 1] = '\0';
	return (cut);
}

static char	*new_extract_line(char *stash)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		stash[i + 1] = '\0';
	line = ft_strdup(stash);
	return (line);
}

char	*new_get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = ft_calloc(1, sizeof(char));
	stash = new_get_buf_data(fd, stash);
	if (!stash)
		return (NULL);
	tmp = new_get_new_stash(stash);
	line = new_extract_line(stash);
	free(stash);
	stash = tmp;
	return (line);
}

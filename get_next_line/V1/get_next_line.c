/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:15:32 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/06 13:00:54 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*get_buf_data(int fd)
{
	long int	buffer;
	char		*buf;
	char		*str;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	str = ft_calloc(1, sizeof(char));
	if (!str)
		return (NULL);
	buffer = 1;
	while (buffer > 0 && !ft_strchr(buf, '\n'))
	{
		buffer = read(fd, buf, BUFFER_SIZE);
		if (buffer < 0)
		{
			free(buf);
			free(str);
			return (NULL);
		}
		buf[buffer] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

static char	*get_rest(char *stash)
{
	char	*cut;
	size_t	i;

	i = 0;
	cut = NULL;
	if (!stash)
		return (NULL);
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			if (stash[i + 1])
			{
				cut = ft_strdup(&stash[i + 1]);
				stash[i + 1] = '\0';
			}
			break ;
		}
		i++;
	}
	return (cut);
}

static char	*extract_line(char **stash, char *line, int fd)
{
	char		*tmp;

	tmp = NULL;
	if (!*stash)
		*stash = get_buf_data(fd);
	if (*stash)
	{
		if (!ft_strchr(*stash, '\n'))
		{
			line = ft_strjoin(line, *stash);
			free(*stash);
			*stash = get_buf_data(fd);
		}
		tmp = get_rest(*stash);
		line = ft_strjoin(line, *stash);
		free(*stash);
		*stash = tmp;
	}
	if (!*stash && line[0] == '\0')
	{
		free(line);
		line = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
	{
		stash = NULL;
		return (NULL);
	}
	line = ft_calloc(1, sizeof(char));
	if (!line)
		return (NULL);
	line = extract_line(&stash, line, fd);
	return (line);
}

// int	main(void)
// {
// 	int	fd;
// 	char *s;

// 	fd = open("read_error.txt", O_RDONLY);
// 	if (fd > -1)
// 	{
// 		s = get_next_line(fd);
// 		printf("%s", s);
// 		free(s);

// 		s = get_next_line(fd);
// 		printf("%s", s);
// 		free(s);

// 		if (BUFFER_SIZE > 100) {
// 			char *temp;
// 			do {
// 				temp = get_next_line(fd);
// 				free(temp);
// 			} while (temp != NULL);
// 		}

// 		s = get_next_line(fd);
// 		printf("%s", s);
// 		free(s);

// 		s = get_next_line(fd);
// 		printf("%s", s);
// 		free(s);

// 		s = get_next_line(fd);
// 		printf("%s", s);
// 		free(s);

// 		s = get_next_line(fd);
// 		printf("%s", s);
// 		free(s);
// 	}
// 	close(fd);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:15:32 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/06 16:25:38 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*get_buf_data(int fd, char *stash)
{
	long int	buffer;
	char		*buff;

	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
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

static char	*get_new_stash(char *stash)
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

static char	*extract_line(char *stash)
{
	
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;
	char		*tmp;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = get_buf_data(fd, stash);
	if(!stash)
		return (NULL);
	tmp = get_new_stash(stash);
	line = extract_line(stash);
	free(stash);
	stash = tmp;
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

// 		// if (BUFFER_SIZE > 100) {
// 		// 	char *temp;
// 		// 	do {
// 		// 		temp = get_next_line(fd);
// 		// 		free(temp);
// 		// 	} while (temp != NULL);
// 		// }

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

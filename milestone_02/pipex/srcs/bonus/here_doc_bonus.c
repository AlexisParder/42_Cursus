/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 09:43:52 by achauvie          #+#    #+#             */
/*   Updated: 2026/01/20 10:28:46 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

static void	write_to_pipe(int pipefd, char *limiter)
{
	char	*line;
	size_t	limiter_len;

	limiter_len = ft_strlen(limiter);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (ft_strlen(line) == limiter_len + 1
			&& !ft_strncmp(line, limiter, limiter_len)
			&& line[limiter_len] == '\n')
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, pipefd);
		free(line);
	}
}

void	handle_here_doc(t_pipex *data)
{
	int	pipefd[2];

	if (pipe(pipefd) < 0)
	{
		free_all(data);
		exit(EXIT_FAILURE);
	}
	write_to_pipe(pipefd[1], data->limiter);
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
}

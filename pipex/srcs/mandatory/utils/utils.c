/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:19:50 by achauvie          #+#    #+#             */
/*   Updated: 2026/01/13 11:06:40 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	err_path(t_pipex *data, size_t cmd_nb, int fd, int pipefd)
{
	ft_putstr_fd(data->cmds[cmd_nb].name, 2);
	ft_putstr_fd(": command not found\n", 2);
	if (fd >= 0)
		close(fd);
	if (pipefd >= 0)
		close(pipefd);
	free_all_cmds(data);
	exit(127);
}

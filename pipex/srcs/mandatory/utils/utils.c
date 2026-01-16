/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:19:50 by achauvie          #+#    #+#             */
/*   Updated: 2026/01/16 08:44:33 by achauvie         ###   ########.fr       */
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
	if (data->cmds[cmd_nb].err_path == 1 || data->cmds[cmd_nb].err_path == 3)
	{
		ft_putstr_fd(data->cmds[cmd_nb].name, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	else
		perror(data->cmds[cmd_nb].name);
	if (fd >= 0)
		close(fd);
	if (pipefd >= 0)
		close(pipefd);
	free_all(data);
	exit(127);
}

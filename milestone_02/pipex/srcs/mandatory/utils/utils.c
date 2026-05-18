/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:19:50 by achauvie          #+#    #+#             */
/*   Updated: 2026/01/21 12:58:54 by achauvie         ###   ########.fr       */
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

void	err_path(t_pipex *data, size_t cmd_nb)
{
	if (data->cmds[cmd_nb].err_path == 1 || data->cmds[cmd_nb].err_path == 3)
	{
		ft_putstr_fd(data->cmds[cmd_nb].name, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	else if (data->cmds[cmd_nb].err_path == 4)
	{
		ft_putstr_fd(data->cmds[cmd_nb].name, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	else if (data->cmds[cmd_nb].err_path == 5)
	{
		ft_putstr_fd(data->cmds[cmd_nb].name, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		free_all(data);
		exit(126);
	}
	else
		perror(data->cmds[cmd_nb].name);
	free_all(data);
	exit(127);
}

int	check_without_path(t_pipex *data, int cmd_nb, char *cmd_tmp)
{
	if (!access(cmd_tmp, F_OK))
	{
		if (!access(cmd_tmp, X_OK))
			data->cmds[cmd_nb].path = ft_strdup(cmd_tmp);
		else
			return (5);
	}
	else
		return (4);
	return (0);
}

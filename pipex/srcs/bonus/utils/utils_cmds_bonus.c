/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cmds_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 09:22:58 by achauvie          #+#    #+#             */
/*   Updated: 2026/01/20 10:31:37 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

int	fill_cmds(t_pipex *data)
{
	long	i;
	size_t	j;
	size_t	k;

	data->cmds = ft_calloc(data->argc - 2 - data->here_doc, sizeof(t_cmd_data));
	if (!data->cmds)
		return (1);
	i = 2 + data->here_doc;
	j = 0;
	while (i < data->argc - 1)
	{
		k = 0;
		while (data->argv[i][k] && !ft_isspace(data->argv[i][k]))
			k++;
		data->cmds[j].name = ft_calloc(k + 1, sizeof(char));
		data->cmds[j].err_path = 0;
		data->cmds[j].path = NULL;
		if (!data->cmds[j].name)
			return (1);
		ft_strlcpy(data->cmds[j].name, data->argv[i], k + 1);
		data->cmds[j].args = split_with_quote(data->argv[i]);
		i++;
		j++;
	}
	return (0);
}

static void	free_cmd(t_pipex *data)
{
	size_t	i;

	i = 0;
	if (data->cmds)
	{
		while (data->cmds[i].name)
		{
			free(data->cmds[i].name);
			free(data->cmds[i].path);
			free_arr(data->cmds[i].args);
			i++;
		}
		free(data->cmds);
		data->cmds = NULL;
	}
}

void	free_all(t_pipex *data)
{
	size_t	i;

	if (!data)
		return ;
	free_cmd(data);
	if (data->status)
		free(data->status);
	data->status = NULL;
	if (data->pid)
		free(data->pid);
	data->pid = NULL;
	i = 0;
	if (data->pipefd)
	{
		while (i < ((size_t)data->argc - 4 - data->here_doc)
			&& data->pipefd[i])
		{
			free(data->pipefd[i]);
			i++;
		}
		free(data->pipefd);
		data->pipefd = NULL;
	}
}

int	open_file(t_pipex *data, char *file, int rd_only)
{
	int	fd;

	if (rd_only)
		fd = open(file, O_RDONLY);
	else
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(file);
		free_all(data);
		exit(1);
	}
	return (fd);
}

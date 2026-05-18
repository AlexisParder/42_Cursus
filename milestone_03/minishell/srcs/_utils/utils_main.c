/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 10:57:50 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/03 11:07:22 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	create_necessary_var(t_minishell *data)
{
	char	*tmp;

	if (!data)
		return ;
	tmp = getcwd(NULL, 0);
	if (tmp)
	{
		data->envp = set_envp(data->envp, "PWD", tmp, 1);
		data->exports = set_envp(data->exports, "PWD", tmp, 1);
		free(tmp);
	}
	data->envp = set_envp(data->envp, "PATH", default_path(), 1);
	data->exports = set_envp(data->exports, "PATH", default_path(), 1);
	data->exports = set_envp(data->exports, "OLDPWD", NULL, 0);
}

int	init_data(t_minishell *data, char **envp)
{
	data->envp = dup_envp(envp);
	data->exports = dup_envp(envp);
	if (!data->envp || !data->exports)
	{
		clean_err_init(data);
		return (2);
	}
	data->tokens = NULL;
	data->cmds = NULL;
	data->return_code = 0;
	data->status = NULL;
	data->pid = NULL;
	data->pipefd = NULL;
	data->nb_cmds = 0;
	if (!data->envp[0] && !data->exports[0])
		create_necessary_var(data);
	if (manage_shlvl(data))
	{
		clean_err_init(data);
		return (2);
	}
	return (0);
}

int	init_exec(t_minishell *data)
{
	size_t	i;

	data->status = ft_calloc(data->nb_cmds, sizeof(int));
	if (!data->status)
		return (1);
	data->pid = ft_calloc(data->nb_cmds, sizeof(pid_t));
	if (!data->pid)
		return (1);
	data->pipefd = ft_calloc(data->nb_cmds - 1, sizeof(int *));
	if (!data->pipefd)
		return (1);
	i = 0;
	while (i < data->nb_cmds - 1)
	{
		data->pipefd[i] = ft_calloc(2, sizeof(int));
		if (!data->pipefd[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_line_isspace(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (0);
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 10:57:50 by achauvie          #+#    #+#             */
/*   Updated: 2026/03/26 15:31:28 by achauvie         ###   ########.fr       */
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
	tmp = ft_strdup("/.nix-profile/bin:/nix/var/nix/profiles/default/bin:");
	if (tmp)
	{
		tmp = ft_strjoin_free(tmp, "/usr/local/sbin:/usr/local/bin:/usr/sbin:");
		if (!tmp)
			return ;
		tmp = ft_strjoin_free(tmp, "/usr/bin:/sbin:/bin");
		if (!tmp)
			return ;
		data->envp = set_envp(data->envp, "PATH", tmp, 1);
		data->exports = set_envp(data->exports, "PATH", tmp, 1);
		free(tmp);
	}
	data->exports = set_envp(data->exports, "OLDPWD", NULL, 0);
}

int	init_data(t_minishell *data, char **envp)
{
	data->envp = dup_envp(envp);
	data->exports = dup_envp(envp);
	data->tokens = NULL;
	data->cmds = NULL;
	data->return_code = 0;
	data->status = NULL;
	data->pid = NULL;
	data->pipefd = NULL;
	data->nb_cmds = 0;
	data->dev_null_fd = -1;
	if (!data->envp[0] && !data->exports[0])
		create_necessary_var(data);
	manage_shlvl(data);
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

char	*readline_no_tty(t_minishell *data)
{
	int		saved_stderr;
	char	*line;

	if (data->dev_null_fd == -1)
		data->dev_null_fd = open("/dev/null", O_WRONLY);
	if (data->dev_null_fd == -1)
		return (NULL);
	saved_stderr = dup(STDERR_FILENO);
	if (saved_stderr == -1)
		return (NULL);
	if (dup2(data->dev_null_fd, STDERR_FILENO) == -1)
	{
		close(saved_stderr);
		return (NULL);
	}
	rl_outstream = stderr;
	line = readline("");
	dup2(saved_stderr, STDERR_FILENO);
	close(saved_stderr);
	rl_outstream = stdout;
	return (line);
}

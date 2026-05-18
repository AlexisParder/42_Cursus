/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:11:58 by achauvie          #+#    #+#             */
/*   Updated: 2026/01/20 15:51:35 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

char	*get_env_path(char **envp)
{
	size_t	i;

	if (!envp || !envp[0] || envp[0][0] == '\0')
		return (NULL);
	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (&envp[i][5]);
		i++;
	}
	return (NULL);
}

static int	check_cmd_path(char *cmd_path, char **tmp)
{
	if (!cmd_path)
	{
		free(cmd_path);
		free_arr(tmp);
		return (0);
	}
	return (1);
}

static char	*create_cmd_path(char *cmd, char **tmp, size_t i)
{
	char	*cmd_path;

	cmd_path = ft_strjoin(tmp[i], "/");
	if (!check_cmd_path(cmd_path, tmp))
		return (NULL);
	cmd_path = ft_strjoin_free(cmd_path, cmd);
	if (!check_cmd_path(cmd_path, tmp))
		return (NULL);
	return (cmd_path);
}

static char	*check_with_path(t_pipex *data, char *cmd)
{
	char	**tmp;
	char	*path;
	char	*cmd_path;
	size_t	i;

	path = get_env_path(data->envp);
	if (!path)
		return (NULL);
	tmp = ft_split(path, ':');
	if (!tmp)
		return (NULL);
	i = 0;
	while (tmp && tmp[i])
	{
		cmd_path = create_cmd_path(cmd, tmp, i);
		if (!cmd_path)
			return (NULL);
		if (access(cmd_path, X_OK) == 0)
			break ;
		free(cmd_path);
		cmd_path = NULL;
		i++;
	}
	free_arr(tmp);
	return (cmd_path);
}

int	check_access_cmd(t_pipex *data, char *cmd, int cmd_nb)
{
	char	*cmd_tmp;
	size_t	i;
	int		err;

	if (!cmd)
		return (1);
	i = 0;
	while (cmd[i] && !ft_isspace(cmd[i]))
		i++;
	cmd_tmp = ft_calloc(i + 1, sizeof(char));
	if (!cmd_tmp)
		return (2);
	ft_strlcpy(cmd_tmp, cmd, i + 1);
	err = 0;
	if (!ft_strchr(cmd_tmp, '/'))
		data->cmds[cmd_nb].path = check_with_path(data, cmd_tmp);
	else
		err = check_without_path(data, cmd_nb, cmd_tmp);
	free(cmd_tmp);
	if (!err && data->cmds[cmd_nb].path == NULL)
		return (3);
	else if (err)
		return (err);
	return (0);
}

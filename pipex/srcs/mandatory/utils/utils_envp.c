/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:11:58 by achauvie          #+#    #+#             */
/*   Updated: 2026/01/09 08:39:23 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

char	*get_env_path(char **envp)
{
	size_t	i;

	if (!envp || envp[0][0] == '\0')
		return (NULL);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (&envp[i][5]);
		i++;
	}
	return (NULL);
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
	while (tmp[i])
	{
		cmd_path = ft_strjoin(tmp[i], "/");
		cmd_path = ft_strjoin_free(cmd_path, cmd);
		if (access(cmd_path, X_OK) == 0)
			break ;
		free(cmd_path);
		i++;
	}
	free_arr(tmp);
	return (cmd_path);
}

char	*check_access_cmd(t_pipex *data, char *cmd)
{
	char	*cmd_path;
	char	*cmd_tmp;
	size_t	i;

	if (!data->envp || data->envp[0][0] == '\0' || !cmd)
		return (NULL);
	cmd_path = NULL;
	i = 0;
	while (cmd[i] && !ft_isspace(cmd[i]))
		i++;
	cmd_tmp = ft_calloc(i + 1, sizeof(char));
	if (!cmd_tmp)
		return (NULL);
	ft_strlcpy(cmd_tmp, cmd, i + 1);
	if (!ft_strchr(cmd_tmp, '/'))
		cmd_path = check_with_path(data, cmd_tmp);
	else
	{
		if (access(cmd_tmp, X_OK) == 0)
			cmd_path = ft_strdup(cmd_tmp);
	}
	free(cmd_tmp);
	return (cmd_path);
}

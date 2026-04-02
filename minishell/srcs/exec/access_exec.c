/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 08:47:51 by achauvie          #+#    #+#             */
/*   Updated: 2026/03/30 14:24:05 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	check_cmd_path(char *cmd_path, char **tmp)
{
	if (!cmd_path)
	{
		free(cmd_path);
		ft_free_arr(tmp);
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

static char	*check_with_path(t_minishell *data, char *cmd)
{
	char	**tmp;
	char	*path;
	char	*cmd_path;
	size_t	i;

	path = get_envp(data->envp, "PATH");
	if (!path)
		return (NULL);
	tmp = ft_split(path, ':');
	if (!tmp)
		return (NULL);
	i = -1;
	cmd_path = NULL;
	while (tmp[++i])
	{
		cmd_path = create_cmd_path(cmd, tmp, i);
		if (!cmd_path)
			return (NULL);
		if (!access(cmd_path, X_OK))
			break ;
		free(cmd_path);
		cmd_path = NULL;
	}
	ft_free_arr(tmp);
	return (cmd_path);
}

static int	check_without_path(t_cmd *cmd)
{
	if (!access(cmd->args[0], F_OK))
	{
		if (!access(cmd->args[0], X_OK))
		{
			cmd->path = ft_strdup(cmd->args[0]);
			return (ERR_CMD_OK);
		}
		return (ERR_CMD_PERMISSION);
	}
	return (ERR_CMD_NO_SUCH);
}

int	check_access_cmd(t_minishell *data, t_cmd *cmd)
{
	size_t		len;
	int			res;
	struct stat	st;

	if (!cmd)
		return (ERR_CMD_NOT_FOUND);
	len = ft_strlen(cmd->args[0]);
	if (len == 1 && cmd->args[0][0] == '.')
		return (ERR_CMD_NOT_FOUND);
	if (!stat(cmd->args[0], &st) && S_ISDIR(st.st_mode)
		&& !(len == 2 && !ft_strncmp(cmd->args[0], "..", 3)))
		return (ERR_CMD_IS_DIR);
	if (!ft_strchr(cmd->args[0], '/'))
	{
		cmd->path = check_with_path(data, cmd->args[0]);
		if (cmd->path)
			return (ERR_CMD_OK);
		if (get_envp(data->envp, "PATH"))
			return (ERR_CMD_NOT_FOUND);
		res = check_without_path(cmd);
		return (res);
	}
	res = check_without_path(cmd);
	return (res);
}

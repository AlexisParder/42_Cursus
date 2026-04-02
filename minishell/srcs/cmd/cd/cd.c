/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 09:16:58 by achauvie          #+#    #+#             */
/*   Updated: 2026/03/29 14:43:19 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	updt_var(t_minishell *data, char *key, char *cwd)
{
	if (!cwd)
		cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		if (!ft_strncmp(key, "PWD", 3))
		{
			ft_dprintf(2,
				"chdir: error retrieving current directory: getcwd: cannot");
			ft_dprintf(2,
				"access parent directories: No such file or directory\n");
		}
		else
		{
			ft_dprintf(2, "minishell: cd: ");
			perror(key);
		}
		return (1);
	}
	data->envp = set_envp(data->envp, key, cwd, 1);
	data->exports = set_envp(data->exports, key, cwd, 1);
	free(cwd);
	return (0);
}

static char	*get_path(char **envp, t_cmd *cmd, size_t arg_len)
{
	char	*path;
	char	*cdpath_result;

	path = get_path_special(envp, cmd, arg_len);
	if (path || !cmd->args[1]
		|| (arg_len == 1 && !ft_strncmp(cmd->args[1], "-", 1)))
		return (path);
	if (cmd->args[1][0] != '/')
	{
		cdpath_result = search_cdpath(envp, cmd->args[1]);
		if (cdpath_result)
		{
			ft_printf("%s\n", cdpath_result);
			return (cdpath_result);
		}
	}
	path = cmd->args[1];
	return (path);
}

static int	change_dir(t_minishell *data, t_cmd *cmd)
{
	char	*path;
	size_t	arg_len;
	int		need_free;

	arg_len = 0;
	need_free = 0;
	if (cmd->args[1])
		arg_len = ft_strlen(cmd->args[1]);
	path = get_path(data->envp, cmd, arg_len);
	if (!path)
		return (1);
	if ((arg_len > 1 && cmd->args[1][0] == '~')
		|| (cmd->args[1] && cmd->args[1][0] != '/' && path != cmd->args[1]))
		need_free = 1;
	if (chdir(path) < 0)
	{
		ft_dprintf(2, "minishell: cd: ");
		perror(cmd->args[1]);
		if (need_free)
			free(path);
		return (1);
	}
	if (need_free)
		free(path);
	return (0);
}

static int	handle_pwd_update(t_minishell *data, t_cmd *cmd)
{
	char	*used_path;
	char	*arg;

	used_path = getcwd(NULL, 0);
	if (!used_path)
	{
		arg = cmd->args[1];
		if (!arg)
			arg = "";
		if (updt_pwd_manual(data, arg))
			return (1);
		return (0);
	}
	data->envp = set_envp(data->envp, "PWD", used_path, 1);
	data->exports = set_envp(data->exports, "PWD", used_path, 1);
	free(used_path);
	return (0);
}

int	cmd_cd(t_minishell *data, t_cmd *cmd)
{
	char	*old_dir;
	int		res;

	if (cmd->nb_args > 2 && cmd->args[2])
	{
		ft_dprintf(2, "minishell: cd: too many arguments\n");
		return (1);
	}
	old_dir = get_envp(data->envp, "PWD");
	if (old_dir)
		old_dir = ft_strdup(old_dir);
	if (change_dir(data, cmd))
	{
		free(old_dir);
		return (1);
	}
	if (old_dir && updt_var(data, "OLDPWD", old_dir))
		return (1);
	res = handle_pwd_update(data, cmd);
	return (res);
}

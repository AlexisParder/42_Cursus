/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:48:05 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/03 09:50:11 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*ft_strjoin_slash(char *dir, char *path)
{
	char	*tmp;
	char	*result;
	size_t	len;

	if (!dir)
		return (NULL);
	len = ft_strlen(dir);
	if (dir[len - 1] == '/')
	{
		tmp = ft_strjoin(dir, path);
		return (tmp);
	}
	tmp = ft_strjoin(dir, "/");
	if (!tmp)
		return (NULL);
	result = ft_strjoin(tmp, path);
	free(tmp);
	return (result);
}

static char	**get_dirs(char **envp)
{
	char	*cdpath;
	char	**dirs;

	cdpath = get_envp(envp, "CDPATH");
	if (!cdpath || !*cdpath)
		return (NULL);
	dirs = ft_split(cdpath, ':');
	if (!dirs)
		return (NULL);
	return (dirs);
}

char	*search_cdpath(char **envp, char *path)
{
	char	**dirs;
	char	*full_path;
	size_t	i;

	i = 0;
	dirs = get_dirs(envp);
	while (dirs && dirs[i])
	{
		if (dirs[i][0] == '\0')
		{
			i++;
			continue ;
		}
		full_path = ft_strjoin_slash(dirs[i], path);
		if (full_path && access(full_path, F_OK) == 0)
		{
			ft_free_arr(dirs);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	if (dirs)
		ft_free_arr(dirs);
	return (NULL);
}

static int	cd_check_path(char *path, int is_home_var)
{
	if (!path)
	{
		if (is_home_var)
			ft_dprintf(2, "minishell: cd: HOME not set\n");
		else
			ft_dprintf(2, "minishell: cd: OLDPWD not set\n");
		return (1);
	}
	return (0);
}

char	*get_path_special(char **envp, t_cmd *cmd, size_t arg_len)
{
	char	*path;

	if (arg_len == 1 && !ft_strncmp(cmd->args[1], "-", 1))
	{
		path = get_envp(envp, "OLDPWD");
		if (cd_check_path(path, 0))
			return (NULL);
		ft_printf("%s\n", path);
		path = ft_strdup(path);
		return (path);
	}
	return (NULL);
}

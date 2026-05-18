/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 12:06:39 by achauvie          #+#    #+#             */
/*   Updated: 2026/03/29 12:13:13 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*build_manual_pwd(t_minishell *data, char *path)
{
	char	*old_pwd;
	char	*new_pwd;
	char	*tmp;

	old_pwd = get_envp(data->envp, "PWD");
	if (!old_pwd)
		return (NULL);
	tmp = ft_strjoin(old_pwd, "/");
	if (!tmp)
		return (NULL);
	new_pwd = ft_strjoin(tmp, path);
	free(tmp);
	return (new_pwd);
}

int	updt_pwd_manual(t_minishell *data, char *path)
{
	char	*tmp;

	ft_dprintf(2,
		"chdir: error retrieving current directory: getcwd: cannot");
	ft_dprintf(2,
		"access parent directories: No such file or directory\n");
	tmp = build_manual_pwd(data, path);
	if (!tmp)
		return (1);
	data->envp = set_envp(data->envp, "PWD", tmp, 1);
	data->exports = set_envp(data->exports, "PWD", tmp, 1);
	free(tmp);
	return (0);
}

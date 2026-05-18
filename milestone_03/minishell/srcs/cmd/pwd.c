/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 09:17:18 by achauvie          #+#    #+#             */
/*   Updated: 2026/03/29 11:24:42 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	cmd_pwd(t_minishell *data)
{
	char	*cwd;
	char	*pwd_env;

	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		pwd_env = get_envp(data->envp, "PWD");
		if (pwd_env)
		{
			ft_printf("%s\n", pwd_env);
			return (0);
		}
		ft_dprintf(2, "minishell: pwd: error retrieving current directory: ");
		perror("getcwd");
		return (1);
	}
	ft_printf("%s\n", cwd);
	free(cwd);
	return (0);
}

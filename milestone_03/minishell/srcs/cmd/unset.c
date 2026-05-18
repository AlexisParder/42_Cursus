/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 08:48:43 by achauvie          #+#    #+#             */
/*   Updated: 2026/03/27 11:33:28 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	cmd_unset(t_minishell *data, t_cmd *cmd)
{
	size_t	i;

	if (cmd->nb_args == 1)
		return (0);
	i = 1;
	while (cmd->args[i])
	{
		if (is_valid_identifier("unset", cmd->args[i], NULL))
		{
			data->envp = unset_envp(data->envp, cmd->args[i]);
			data->exports = unset_envp(data->exports, cmd->args[i]);
		}
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_reorg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 15:16:48 by tjourdai          #+#    #+#             */
/*   Updated: 2026/03/23 08:48:13 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

size_t	count_new_args(t_cmd *cmd)
{
	size_t	i;
	size_t	nb_args;

	i = 0;
	nb_args = 1;
	while (cmd->args_backup[i])
	{
		if (cmd->separators[i]
			|| (cmd->args_backup[i + 1] && cmd->quotes[i + 1]))
			nb_args++;
		i++;
	}
	return (nb_args);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 16:25:33 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/02 16:42:05 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	check_init_data_token(t_minishell *data)
{
	if (!data->tokens)
	{
		free_all(data);
		return (-1);
	}
	if (data->tokens->value[0] == '\0')
	{
		ft_dprintf(2, "'': command not found\n");
		data->return_code = 127;
		return (1);
	}
	return (0);
}

void	free_and_signal(t_minishell *data, char *line)
{
	free(line);
	free_all(data);
	manage_signals();
}

int	create_new_args_part_2(t_cmd *cmd, t_reorg *reorg)
{
	reorg->quotes = ft_calloc(cmd->nb_args + 1, sizeof(char));
	if (!reorg->quotes)
	{
		free_reorg(reorg);
		return (1);
	}
	ft_memset(reorg->quotes, '\1', cmd->nb_args);
	reorg->seps = ft_calloc(cmd->nb_args + 1, sizeof(int));
	if (!reorg->seps)
	{
		free_reorg(reorg);
		return (1);
	}
	return (0);
}

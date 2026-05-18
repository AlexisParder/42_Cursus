/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reorganize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:18:25 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/02 16:46:39 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	free_reorg(t_reorg *reorg)
{
	if (reorg->args)
		ft_free_arr(reorg->args);
	if (reorg->args_b)
		ft_free_arr(reorg->args_b);
	if (reorg->quotes)
		free(reorg->quotes);
	if (reorg->seps)
		free(reorg->seps);
	reorg->args = NULL;
	reorg->args_b = NULL;
	reorg->quotes = NULL;
	reorg->seps = NULL;
}

static int	create_new_args(t_cmd *cmd, t_reorg *reorg)
{
	cmd->nb_args = count_new_args(cmd);
	reorg->quotes = NULL;
	reorg->seps = NULL;
	reorg->args = ft_calloc(cmd->nb_args + 1, sizeof(char *));
	if (!reorg->args)
		return (1);
	reorg->args_b = ft_calloc(cmd->nb_args + 1, sizeof(char *));
	if (!reorg->args_b)
	{
		free_reorg(reorg);
		return (1);
	}
	if (create_new_args_part_2(cmd, reorg))
		return (1);
	return (0);
}

static void	free_and_replace(t_cmd *cmd, t_reorg *reorg)
{
	ft_free_arr(cmd->args);
	ft_free_arr(cmd->args_backup);
	free(cmd->quotes);
	free(cmd->separators);
	cmd->args = reorg->args;
	cmd->args_backup = reorg->args_b;
	cmd->quotes = reorg->quotes;
	cmd->separators = reorg->seps;
	ft_free_arr(cmd->args_backup);
	cmd->args_backup = NULL;
}

static void	reorg_data(t_reorg *reorg, t_cmd *cmd, size_t *j, size_t i)
{
	size_t	len;
	int		had_space;
	int		k;

	k = (*j);
	had_space = (reorg->args[k] && ft_strchr(reorg->args[k], ' '));
	reorg->args[k] = ft_strjoin_free(reorg->args[k], cmd->args[i]);
	reorg->args_b[k] = ft_strjoin_free(reorg->args_b[k], cmd->args_backup[i]);
	if (!cmd->quotes[i] && !had_space)
		reorg->quotes[k] = 0;
	else if (reorg->quotes[k] == '\1')
		reorg->quotes[k] = cmd->quotes[i];
	reorg->seps[k] = cmd->separators[i];
	len = ft_strlen(cmd->args_backup[i]);
	if (cmd->separators[i]
		|| (cmd->quotes[i] && cmd->args_backup[i + 1]
			&& ft_isspace(cmd->args_backup[i][len])))
		(*j)++;
}

int	reorganize_args(t_cmd *cmd)
{
	size_t	i;
	size_t	j;
	t_reorg	reorg;

	if (create_new_args(cmd, &reorg))
		return (1);
	i = 0;
	j = 0;
	while (cmd->args_backup[i])
	{
		if ((!cmd->args[i] && !cmd->quotes[i])
			|| (cmd->args_backup[i][0] == '$' && !cmd->args_backup[i][1]
			&& !cmd->separators[i] && cmd->args_backup[i + 1]
			&& cmd->quotes[i + 1]))
		{
			i++;
			continue ;
		}
		reorg_data(&reorg, cmd, &j, i);
		i++;
	}
	free_and_replace(cmd, &reorg);
	divide_args(cmd);
	return (0);
}

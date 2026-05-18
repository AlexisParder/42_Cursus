/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 17:12:59 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/01 13:44:37 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static size_t	count_total_args(t_cmd *cmd)
{
	size_t	i;
	size_t	count;
	char	**arr;

	i = 0;
	count = 0;
	while (cmd->args[i])
	{
		if (!cmd->quotes[i])
		{
			arr = ft_split_all_space(cmd->args[i]);
			if (!arr)
				return (0);
			count += ft_arr_len(arr);
			ft_free_arr(arr);
		}
		else
			count++;
		i++;
	}
	return (count);
}

static int	fill_unquoted(char **new_args, char *new_quotes, char **arr,
	size_t *i)
{
	size_t	j;

	j = 0;
	while (j < ft_arr_len(arr))
	{
		new_quotes[*i] = 0;
		new_args[(*i)++] = ft_strdup(arr[j++]);
	}
	return (0);
}

static int	split_and_fill(char **new_args, char *new_quotes, char *arg,
	size_t *i)
{
	char	**arr;

	arr = ft_split_all_space(arg);
	if (!arr)
		return (1);
	fill_unquoted(new_args, new_quotes, arr, i);
	ft_free_arr(arr);
	return (0);
}

static int	fill_new_args(t_cmd *cmd, char **new_args, char *new_quotes)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (cmd->args[k])
	{
		if (!cmd->quotes[k])
		{
			if (split_and_fill(new_args, new_quotes, cmd->args[k], &i))
				return (1);
		}
		else
		{
			new_quotes[i] = cmd->quotes[k];
			new_args[i++] = ft_strdup(cmd->args[k]);
		}
		k++;
	}
	return (0);
}

int	divide_args(t_cmd *cmd)
{
	size_t	count;
	char	**new_args;
	char	*new_quotes;

	count = count_total_args(cmd);
	if (!count)
		return (1);
	new_args = ft_calloc(count + 1, sizeof(char *));
	if (!new_args)
		return (1);
	new_quotes = ft_calloc(count + 1, sizeof(char));
	if (!new_quotes)
	{
		ft_free_arr(new_args);
		return (1);
	}
	if (fill_new_args(cmd, new_args, new_quotes))
		return (1);
	ft_free_arr(cmd->args);
	free(cmd->quotes);
	cmd->args = new_args;
	cmd->quotes = new_quotes;
	cmd->nb_args = count;
	return (0);
}

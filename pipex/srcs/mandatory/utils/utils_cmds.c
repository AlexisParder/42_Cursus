/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 09:22:58 by achauvie          #+#    #+#             */
/*   Updated: 2026/01/09 11:03:52 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static char	**split_cmds(t_pipex *data, long arg_nb)
{
	char	**args;
	size_t	i;

	i = 0;
	while (data->argv[arg_nb][i])
	{
		if (data->argv[arg_nb][i] == '"')
			data->argv[arg_nb][i] = ' ';
		i++;
	}
	args = ft_split_all_space(data->argv[arg_nb]);
	if (!args)
	{
		args = ft_calloc(1, sizeof(char *));
		return (args);
	}
	// DEBUG
	i = 0;
	while(args[i++])
		ft_printf("%s\n", args[i]);
	// END DEBUG
	return (args);
}

int	fill_cmds(t_pipex *data)
{
	long	i;
	size_t	j;
	size_t	k;

	data->cmds = ft_calloc(data->argc - 2, sizeof(t_cmd_data));
	if (!data->cmds)
		return (1);
	i = 2;
	j = 0;
	while (i < data->argc - 1)
	{
		k = 0;
		while (data->argv[i][k] && !ft_isspace(data->argv[i][k]))
			k++;
		data->cmds[j].name = ft_calloc(k + 1, sizeof(char));
		if (!data->cmds[j].name)
			return (1);
		ft_strlcpy(data->cmds[j].name, data->argv[i], k + 1);
		data->cmds[j].args = split_cmds(data, i);
		if (!data->cmds[j].args || !data->cmds[j].args[0])
			return (1);
		i++;
		j++;
	}
	return (0);
}

void	free_cmds(t_pipex *data, int status)
{
	size_t	i;

	i = 0;
	while (data->cmds[i].name)
	{
		free(data->cmds[i].name);
		free_arr(data->cmds[i].args);
		i++;
	}
	free(data->cmds);
	data->cmds = NULL;
	exit(status);
}

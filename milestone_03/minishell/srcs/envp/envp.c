/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 09:15:15 by achauvie          #+#    #+#             */
/*   Updated: 2026/03/12 15:23:19 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*get_envp(char **envp, char *key)
{
	size_t	i;
	size_t	key_len;

	if (!envp || !key || !key[0])
		return (NULL);
	key_len = ft_strlen(key);
	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], key, key_len) && envp[i][key_len] == '=')
			return (&envp[i][key_len + 1]);
		i++;
	}
	return (NULL);
}

char	**set_envp(char **envp, char *key, char *value, int operator)
{
	long	index;
	char	*new_line;
	char	**res_new_var;

	if (!envp || !key)
		return (envp);
	index = get_envp_index(envp, key);
	if (index >= 0)
	{
		new_line = create_envp_line(key, value, operator);
		if (!new_line)
			return (envp);
		free(envp[index]);
		envp[index] = new_line;
		return (envp);
	}
	res_new_var = add_new_envp_var(envp, key, value, operator);
	if (!res_new_var)
		return (envp);
	return (res_new_var);
}

static char	**create_new_envp(char **envp, long envp_index)
{
	char	**new_envp;
	long	i;
	long	j;
	size_t	count;

	count = count_envp(envp);
	new_envp = ft_calloc(count, sizeof(char *));
	if (!new_envp)
		return (NULL);
	i = 0;
	j = 0;
	while (envp[i])
	{
		if (i == envp_index)
		{
			free(envp[i]);
			i++;
			continue ;
		}
		new_envp[j] = envp[i];
		j++;
		i++;
	}
	return (new_envp);
}

char	**unset_envp(char **envp, char *key)
{
	long	envp_index;
	char	**new_envp;

	if (!envp || !key)
		return (envp);
	envp_index = get_envp_index(envp, key);
	if (envp_index < 0)
		return (envp);
	new_envp = create_new_envp(envp, envp_index);
	if (!new_envp)
		return (envp);
	free(envp);
	return (new_envp);
}

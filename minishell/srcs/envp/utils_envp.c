/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 12:14:18 by achauvie          #+#    #+#             */
/*   Updated: 2026/03/19 09:21:32 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

size_t	count_envp(char **envp)
{
	size_t	i;

	i = 0;
	while (envp && envp[i])
		i++;
	return (i);
}

char	**dup_envp(char **envp)
{
	size_t	size;
	size_t	i;
	char	**dup_arr;

	if (!envp)
	{
		dup_arr = ft_calloc(1, sizeof(char *));
		return (dup_arr);
	}
	size = count_envp(envp);
	dup_arr = ft_calloc(size + 1, sizeof(char *));
	if (!dup_arr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dup_arr[i] = ft_strdup(envp[i]);
		if (!dup_arr[i])
		{
			ft_free_arr(dup_arr);
			return (NULL);
		}
		i++;
	}
	return (dup_arr);
}

long	get_envp_index(char **envp, char *key)
{
	size_t	i;
	size_t	key_len;

	if (!envp || !key || !key[0])
		return (-1);
	key_len = ft_strlen(key);
	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], key, key_len))
			return (i);
		i++;
	}
	return (-1);
}

char	*create_envp_line(char *key, char *value, int operator)
{
	char	*tmp;
	char	*line;

	if (!key)
		return (NULL);
	if (!operator)
		return (ft_strdup(key));
	tmp = ft_strjoin(key, "=");
	if (!tmp)
		return (NULL);
	line = ft_strjoin_free(tmp, value);
	return (line);
}

char	**add_new_envp_var(char **envp, char *key, char *val, int operator)
{
	char	**new_envp;
	size_t	count;
	size_t	i;

	count = count_envp(envp);
	new_envp = ft_calloc(count + 2, sizeof(char *));
	if (!new_envp)
		return (NULL);
	i = 0;
	while (i < count)
	{
		new_envp[i] = envp[i];
		i++;
	}
	new_envp[i] = create_envp_line(key, val, operator);
	if (!new_envp[i])
	{
		free(new_envp);
		return (NULL);
	}
	free(envp);
	return (new_envp);
}

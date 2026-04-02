/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 08:48:50 by achauvie          #+#    #+#             */
/*   Updated: 2026/03/12 14:18:09 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	cmd_env(t_minishell *data)
{
	size_t	i;

	if (!data->envp)
		return (1);
	i = 0;
	while (data->envp[i])
	{
		ft_printf("%s\n", data->envp[i]);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:55:39 by achauvie          #+#    #+#             */
/*   Updated: 2026/01/05 14:27:26 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <libft.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	char	**argv;
	char	**envp;
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status1;
	int		status2;
}	t_pipex;

char	*get_env_path(char **envp);
char	*check_access_cmd(t_pipex *data, char *cmd);

void	free_arr(char **arr);

#endif
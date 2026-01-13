/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:55:39 by achauvie          #+#    #+#             */
/*   Updated: 2026/01/13 11:10:20 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <libft.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_cmd_data
{
	char	*name;
	char	**args;
}	t_cmd_data;

typedef struct s_pipex
{
	int			argc;
	char		**argv;
	char		**envp;
	int			pipefd[2];
	pid_t		pid1;
	pid_t		pid2;
	int			status1;
	int			status2;
	t_cmd_data	*cmds;
}	t_pipex;

int		fill_cmds(t_pipex *data);

char	*get_env_path(char **envp);
char	*check_access_cmd(t_pipex *data, char *cmd);
char	**split_with_quote(char const *s);

void	free_arr(char **arr);
void	free_all_cmds(t_pipex *data);
void	err_path(t_pipex *data, size_t cmd_nb, int fd, int pipefd);

#endif
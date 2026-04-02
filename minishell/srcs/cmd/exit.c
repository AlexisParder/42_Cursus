/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 08:48:56 by achauvie          #+#    #+#             */
/*   Updated: 2026/03/27 16:37:53 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	free_cmd_exec(t_minishell *data)
{
	size_t	i;

	free_cmds(data);
	if (data->status)
		free(data->status);
	if (data->pid)
		free(data->pid);
	i = 0;
	if (data->pipefd)
	{
		while (i < ((size_t)data->nb_cmds - 1) && data->pipefd[i])
		{
			free(data->pipefd[i]);
			i++;
		}
		free(data->pipefd);
		data->pipefd = NULL;
	}
}

static void	exit_with_arg(t_minishell *data, t_cmd *cmd)
{
	long	arg_long;

	if (data->dev_null_fd != -1)
		close(data->dev_null_fd);
	rl_clear_history();
	ft_free_arr(data->envp);
	ft_free_arr(data->exports);
	free_tokens(data);
	if (arg_is_digit(cmd->args[1]))
	{
		arg_long = ft_atol(cmd->args[1]);
		free_cmd_exec(data);
		arg_long %= 256;
		exit(arg_long);
	}
	if (cmd->args[1])
		ft_dprintf(2, "minishell: exit: %s: numeric argument required\n",
			cmd->args[1]);
	free_cmd_exec(data);
	exit(2);
}

static void	free_and_close_exit(t_minishell *data, t_cmd *cmd)
{
	ft_dprintf(2, "minishell: exit: %s: numeric argument required\n",
		cmd->args[1]);
	if (data->dev_null_fd != -1)
		close(data->dev_null_fd);
	rl_clear_history();
	ft_free_arr(data->envp);
	ft_free_arr(data->exports);
	free_tokens(data);
	free_cmd_exec(data);
}

int	cmd_exit(t_minishell *data, t_cmd *cmd)
{
	if (isatty(STDIN_FILENO) && (data->nb_cmds == 1 || !cmd))
		ft_dprintf(2, "exit\n");
	if (!cmd || cmd->nb_args == 1)
	{
		if (data->dev_null_fd != -1)
			close(data->dev_null_fd);
		rl_clear_history();
		ft_free_arr(data->envp);
		ft_free_arr(data->exports);
		free_tokens(data);
		free_cmd_exec(data);
		exit(data->return_code % 256);
	}
	else if (cmd->nb_args == 2)
		exit_with_arg(data, cmd);
	else if (cmd->nb_args > 2 && cmd->args[cmd->nb_args - 1])
	{
		if (!arg_is_digit(cmd->args[1]))
		{
			free_and_close_exit(data, cmd);
			exit(2);
		}
		ft_dprintf(2, "minishell: exit: too many arguments\n");
	}
	return (1);
}

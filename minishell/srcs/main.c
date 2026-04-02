/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:09:19 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/01 13:13:45 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	initialize_minishell(t_minishell *data)
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
	if (fill_cmds(data))
	{
		ft_dprintf(2, "Error\nFailure during allocation\n");
		free_all(data);
		return (2);
	}
	if (create_heredoc(data) < 0)
	{
		data->return_code = 130;
		free_all(data);
		return (1);
	}
	expand_and_reorganize(data);
	return (0);
}

static int	execute_minishell(t_minishell *data)
{
	if (data->nb_cmds == 1 && is_builtin(data->cmds))
	{
		if (data->cmds->redirs)
			exec_builtin_with_redirs(data, data->cmds);
		else
			exec_cmd(data, data->cmds);
	}
	else
	{
		if (init_exec(data))
		{
			ft_dprintf(2, "Error\nFailure during allocation\n");
			free_all(data);
			return (2);
		}
		data->return_code = exec_parent(data);
	}
	return (0);
}

static char	*read_minishell(t_minishell *data)
{
	char	*line;

	if (!isatty(STDIN_FILENO))
		line = readline_no_tty(data);
	else
		line = readline("UNDEFINED minishell$> ");
	if (!line)
		cmd_exit(data, NULL);
	if (!*line || check_line_isspace(line))
		return (NULL);
	return (line);
}

static int	manage_minishell(t_minishell *data, char *line)
{
	int	err;

	add_history(line);
	pars_line(data, line);
	err = initialize_minishell(data);
	if (err == -1)
		data->return_code = 2;
	if (err != 0)
		return (err);
	err = execute_minishell(data);
	if (err)
		return (err);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	char		*line;
	t_minishell	data;
	int			err;

	(void)ac;
	(void)av;
	err = init_data(&data, envp);
	line = NULL;
	while (err < 2)
	{
		free(line);
		free_all(&data);
		manage_signals();
		line = read_minishell(&data);
		if (g_signal)
			data.return_code = g_signal;
		if (!line)
			continue ;
		err = manage_minishell(&data, line);
		if (err <= 1)
			continue ;
	}
	clean_main(&data, line);
	return (err);
}

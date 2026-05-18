/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:56:30 by achauvie          #+#    #+#             */
/*   Updated: 2026/01/21 09:45:42 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

static int	check_here_doc(char	**av)
{
	size_t	len;

	len = ft_strlen(av[1]);
	if (len == 8 && !ft_strncmp(av[1], "here_doc", 8))
		return (1);
	return (0);
}

static char	*get_limiter(t_pipex *data)
{
	if (!data->here_doc)
		return (NULL);
	return (data->argv[2]);
}

static int	init_data(t_pipex *data, int ac, char **av, char **envp)
{
	long	i;

	data->argc = ac;
	data->argv = av;
	data->envp = envp;
	data->status = ft_calloc(data->argc - 3 - data->here_doc, sizeof(int));
	if (!data->status)
		return (1);
	data->pid = ft_calloc(data->argc - 3 - data->here_doc, sizeof(int));
	if (!data->pid)
		return (1);
	data->pipefd = ft_calloc(data->argc - 3 - data->here_doc, sizeof(int *));
	if (!data->pipefd)
		return (1);
	i = 0;
	while (i < data->argc - 4 - data->here_doc)
	{
		data->pipefd[i] = ft_calloc(2, sizeof(int));
		if (!data->pipefd[i])
			return (1);
		i++;
	}
	data->limiter = get_limiter(data);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	data;
	int		err;

	data.here_doc = 0;
	if (ac >= 2)
		data.here_doc = check_here_doc(av);
	if ((data.here_doc && ac < 6) || (!data.here_doc && ac < 5))
	{
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 ... cmdN outfile\n", 2);
		ft_putstr_fd("Or: ./pipex here_doc LIMITER cmd1 ... cmdN outfile\n", 2);
		return (1);
	}
	err = init_data(&data, ac, av, envp);
	if (err)
		return (err);
	err = fill_cmds(&data);
	if (!err)
		err = exec_parent(&data);
	free_all(&data);
	return (err);
}

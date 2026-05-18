/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 08:47:54 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/01 13:13:44 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*get_var(t_minishell *data, char *arg, size_t *i)
{
	size_t	start;
	size_t	len;
	char	*var_name;
	char	*var_value;

	(*i)++;
	start = *i;
	while (arg[*i] && (ft_isalnum(arg[*i]) || arg[*i] == '_'))
		(*i)++;
	len = *i - start;
	if (len == 0)
		return ("$");
	var_name = ft_substr(arg, start, len);
	if (!var_name)
		return ("");
	var_value = get_envp(data->envp, var_name);
	free(var_name);
	return (var_value);
}

static int	has_valid_n_opt(char *arg)
{
	size_t	i;

	if (!arg || arg[0] != '-' || arg[1] != 'n')
		return (0);
	i = 2;
	while (arg[i])
	{
		if (arg[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

static void	skip_n_opt(t_cmd *cmd, size_t *i, int *print_newline)
{
	while (cmd->args[*i] && has_valid_n_opt(cmd->args[*i]))
	{
		(*print_newline) = 0;
		(*i)++;
	}
}

static int	arg_has_output(t_minishell *data, t_cmd *cmd, size_t i)
{
	char	*arg;
	char	*val;

	arg = cmd->args[i];
	if (cmd->quotes[i])
		return (1);
	i = 0;
	while (arg[i])
	{
		if (arg[i] == '$' && arg[i + 1]
			&& (ft_isalnum(arg[i + 1]) || arg[i + 1] == '_'))
		{
			val = get_var(data, arg, &i);
			if (val && val[0])
				return (1);
		}
		else if (arg[i] == '$' && arg[i + 1] == '?')
			return (1);
		else
			return (1);
	}
	return (0);
}

int	cmd_echo(t_minishell *data, t_cmd *cmd)
{
	size_t	i;
	int		print_newline;

	print_newline = 1;
	i = 1;
	skip_n_opt(cmd, &i, &print_newline);
	while (cmd->args[i])
	{
		ft_printf("%s", cmd->args[i]);
		if (arg_has_output(data, cmd, i)
			&& cmd->args[i + 1] && arg_has_output(data, cmd, i + 1))
			ft_printf(" ");
		i++;
	}
	if (print_newline)
		ft_printf("\n");
	return (0);
}

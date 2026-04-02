/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 09:58:35 by tjourdai          #+#    #+#             */
/*   Updated: 2026/03/27 11:45:55 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	g_signal = 0;

static void	handle_sigint(int sig)
{
	(void)sig;
	g_signal = 130;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

static void	handle_sigint_heredoc(int sig)
{
	(void)sig;
	g_signal = 130;
	write(1, "\n", 1);
	close(STDIN_FILENO);
}

void	manage_signals(void)
{
	g_signal = 0;
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
}

void	manage_signals_heredoc(void)
{
	signal(SIGINT, handle_sigint_heredoc);
	signal(SIGQUIT, SIG_IGN);
}

void	manage_signals_exec_parent(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

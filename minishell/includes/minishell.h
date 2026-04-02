/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:18:57 by tjourdai          #+#    #+#             */
/*   Updated: 2026/04/01 15:34:23 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <libft.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

typedef enum e_err
{
	ERR_CMD_OK,
	ERR_CMD_NOT_FOUND,
	ERR_CMD_NO_SUCH,
	ERR_CMD_IS_DIR,
	ERR_CMD_PERMISSION
}	t_err;

typedef enum e_type
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	HEREDOC
}	t_type;

typedef struct s_token
{
	t_type			type;
	char			*value;
	char			quote;
	int				sep;
	struct s_token	*next;
}	t_token;

typedef struct s_redirs
{
	t_type			type;
	char			*file;
	int				heredoc_fd;
	char			quote;
	struct s_redirs	*next;
}	t_redirs;

typedef struct s_cmd
{
	char			**args;
	char			**args_backup;
	size_t			nb_args;
	t_redirs		*redirs;
	char			*quotes;
	int				*separators;
	char			*path;
	int				err_path;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_minishell
{
	t_token			*tokens;
	t_cmd			*cmds;
	char			**envp;
	char			**exports;
	size_t			nb_cmds;
	int				stdin_dup;
	int				stdout_dup;
	int				**pipefd;
	pid_t			*pid;
	int				*status;
	long			return_code;
	int				dev_null_fd;
}	t_minishell;

typedef struct s_reorg
{
	int		*seps;
	char	*quotes;
	char	**args;
	char	**args_b;
}	t_reorg;

extern int	g_signal;

int			fill_cmds(t_minishell *data);
int			add_cmd(t_cmd *cmd, t_token *token);

int			init_data(t_minishell *data, char **envp);
int			init_exec(t_minishell *data);
int			check_line_isspace(char *line);
int			cmd_pwd(t_minishell *data);
int			cmd_env(t_minishell *data);
int			cmd_exit(t_minishell *data, t_cmd *cmd);
int			cmd_echo(t_minishell *data, t_cmd *cmd);
int			cmd_cd(t_minishell *data, t_cmd *cmd);
int			cmd_export(t_minishell *data, t_cmd *cmd);
int			cmd_unset(t_minishell *data, t_cmd *cmd);
int			check_access_cmd(t_minishell *data, t_cmd *cmd);
int			exec_parent(t_minishell *data);
int			is_builtin(t_cmd *cmd);
int			apply_redirs(t_redirs *redirs);
int			save_fd(t_minishell *data);
int			create_pipes(t_minishell *data, size_t cmd_nb);
int			create_heredoc(t_minishell *data);
int			updt_pwd_manual(t_minishell *data, char *path);
int			divide_args(t_cmd *cmd);

char		*get_envp(char **envp, char *key);
long		get_envp_index(char **envp, char *key);
char		*create_envp_line(char *key, char *value, int operator);
char		**add_new_envp_var(char **envp, char *key, char *val, int operator);
char		**set_envp(char **envp, char *key, char *value, int operator);
char		**unset_envp(char **envp, char *key);
char		**dup_envp(char **envp);
size_t		count_envp(char **envp);

char		is_quote(char c);
int			is_operator(char c);
int			get_operator_len(char *str, size_t i);
int			new_token(t_minishell *data, char *value, char quote, int sep);

int			quote_is_valid(char *str);
char		*remove_quotes(char *str);
int			skip_quoted_section(char *str, size_t i);
void		pars_line(t_minishell *data, char *str);

void		manage_signals(void);
void		manage_signals_heredoc(void);
void		manage_signals_exec_parent(void);

void		free_tokens(t_minishell *data);
void		free_cmds(t_minishell *data);
void		free_all(t_minishell *data);
void		err_path(t_minishell *data, t_cmd *cmd);
void		close_other_heredocs(t_minishell *data, t_cmd *current_cmd);
void		close_parent_heredocs(t_cmd *cmd);
void		expand_and_reorganize(t_minishell *data);
void		expand_redirs(t_minishell *data, t_cmd *cmd);
void		exec_cmd(t_minishell *data, t_cmd *cmd);
void		exec_builtin(t_minishell *data, t_cmd *cmd);
void		exec_builtin_with_redirs(t_minishell *data, t_cmd *cmd);
void		restore_fd(t_minishell *data);
void		reorganize_args(t_cmd *cmd);
size_t		count_new_args(t_cmd *cmd);
void		expand_heredoc(t_minishell *data, char *line, int fd);
void		clean_main(t_minishell *data, char *line);
void		manage_shlvl(t_minishell *data);
void		exec_child_signals(t_cmd *cmd);

char		*search_cdpath(char **envp, char *path);
char		*get_path_special(char **envp, t_cmd *cmd, size_t arg_len);

t_cmd		*lst_cmdlast(t_cmd *lst);
t_token		*lst_tokenlast(t_token *lst);
t_redirs	*lst_redirlast(t_redirs *lst);

int			is_valid_identifier(char *cmd_name, char *identifier, char *value);
char		**separate_key_value(char *var);

void		display_exports(t_minishell *data, t_cmd *cmd);

char		*get_var(t_minishell *data, char *arg, size_t *i);
char		*readline_no_tty(t_minishell *data);

void		manage_err_sig(t_minishell *data, char *line, char *limiter);

int			is_overflow(const char *str);
int			arg_is_digit(char *arg);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:48:12 by sdestann          #+#    #+#             */
/*   Updated: 2023/06/30 09:33:48 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"

// to access, chdir, close, dup, dup2, execve, fork, getcwd, isatty, pipe,
// read, ttyname, ttyslot, unlink, write

# include <unistd.h>

// to add_history

# include <readline/history.h>

// to closedir, opendir

# include <sys/types.h>

// to readdir

# include <dirent.h>

// to exit, free, getenv, malloc

# include <stdlib.h>

// to fstat, lstat, stat

# include <sys/stat.h>

// to ioctl

# include <sys/ioctl.h>

// to kill, sigaction, sigaddset, signal, sigemptyset

# include <signal.h>

// to open

# include <fcntl.h>

// to perror, printf

# include <stdio.h>

// to readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay

# include <readline/readline.h>
# include <readline/history.h>

// to strerror

# include <string.h>

// to tcsetattr, tcgetattr

# include <termios.h>

// to tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs

# include <curses.h>
# include <term.h>

// to wait, wait3, wait4, waitpid

# include <sys/wait.h>

// command stocke sert au parsing des commandes.

typedef struct s_command
{
	char	*quote;
	char	*str;
	char	*word;
	char	*commands[100];
	size_t	num_words;
	size_t	i;
	int		brk;
	int		lvl;
}				t_command;

// liste chainee pour envp

typedef struct s_envp {
	struct s_envp	*next;
	char	*str;
}	t_envp;

// data contient les elements structurels, les regles principales.

typedef struct s_data
{
	char		*str_temp;
	char		*str_temp2;
	char		*str_to_unset;
	char		**cmd_paths;
	char		**cmd_args;
	//int			cmd_nbr;
	t_envp		*env;
	pid_t		pid;
	t_command	*commands;
}				t_data;


// execute.c

void	execute_command(t_data *data, char **envp);

// export.c

void	ft_add_new_arg_env(t_data *data);
void	verif_args (t_data *data);
void	ft_export (t_data *data);

// free.c

void	ft_free_args(t_data *data);
void	ft_free_paths(t_data *data);
void	ft_free_str_temp(int i, t_data *data);
void	ft_free_all(int i, t_data *data);

// main.c

char	*get_cmd(char **paths, char *cmd);
void	shell_loop(t_data *data, char **envp);
int		find_builtin(t_data *data);
int		main(int argc, char **argv, char **envp);

// parse.c

void	ft_quote(t_command *var);
void	ft_space(t_command *var);
void	tokening(t_command *var);
char	**parse(char *s);

// print.c

void	ft_show_env(t_data *data);
void	ft_echo(t_data *data);
void	msg_error(char *err);

// signals.c

void	handle_signal(int signal);

// token_and_lvl.c

void	ft_single_token(t_command *var);
void	ft_double_token(t_command *var);
void	ft_parenthese(t_command *var);

// utils.c

char	*delete_last_char(char *str);
char	*find_path(char *s, t_envp *env);
void	add_str_endlst(t_envp *env, char *str);
void	init_env(t_data *data, char **envp);
void	init_minishell(t_data *data, char **envp);

// unset.c

void    ft_delete_arg_env(t_data *data);
void    ft_unset(t_data *data);

/*echo et l’option -n
◦ cd uniquement avec un chemin relatif ou absolu
◦ pwd sans aucune option
◦ export sans aucune option
◦ unset sans aucune option
◦ env sans aucune option ni argument
◦ exit sans aucune option*/

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:48:12 by sdestann          #+#    #+#             */
/*   Updated: 2023/06/22 12:03:07 by sdestann         ###   ########.fr       */
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

// data contient les elements structurels, les regles principales.

typedef struct s_data
{
	char	*str_temp;
	char	*str_temp2;
	char	**cmd_paths;
	char	**cmd_args;
	pid_t	pid;
}				t_data;

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

// echo.c

void	ft_echo(t_data *data);

// env.c

void	ft_env(char **envp);

// error.c

void	msg_error(char *err);
void	ft_free(t_data *data);
void	ft_free2(t_data *data);

// init_minishell.c

char	*jenlevedernierchar(char *str);
char	*find_path(char *s, char **envp);
void	init_minishell(t_data *data, char **envp);

// main.c

char	*get_cmd(char **paths, char *cmd);
void	execute_command(t_data *data, char **envp);
void	shell_loop(t_data *data, char **envp);
int		find_builtin(t_data *data, char **envp);
int		main(int argc, char **argv, char **envp);

// parse.c

void	ft_quote(t_command *var);
void	ft_space(t_command *var);
void	ft_parenthese(t_command *var);
void	tokening(t_command *var);
char	**parse(char *s);

// signals.c

void	handle_signal(int signal);

/*echo et l’option -n
◦ cd uniquement avec un chemin relatif ou absolu
◦ pwd sans aucune option
◦ export sans aucune option
◦ unset sans aucune option
◦ env sans aucune option ni argument
◦ exit sans aucune option*/

#endif

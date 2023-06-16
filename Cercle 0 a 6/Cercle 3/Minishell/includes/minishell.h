/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:48:12 by sdestann          #+#    #+#             */
/*   Updated: 2023/06/16 15:41:12 by sdestann         ###   ########.fr       */
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

# define MAX_COMMAND_LENGTH 100
# define MAX_ARGUMENT_LENGTH 100
# define MAX_ARGUMENTS 10

typedef struct s_data
{
	int		ac;
	char	**av;
	char	**envp;
	char	*str_temp;
	char	**cmd_paths;
	char	**cmd_args;
	pid_t	pid;
	int		cmd_nbrs;
	int		pipe_nbrs;
	int		*pipe;
}				t_data;

// error.c

void	msg_error(char *err);

// main.c

char	*get_cmd(char **paths, char *cmd);
char	*find_path(t_data *data, char *s);
int		main(int argc, char **argv, char **envp);
void	shell_loop(t_data *data);
int		find_builtin(t_data *data);
void	execute_command(t_data *data);

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
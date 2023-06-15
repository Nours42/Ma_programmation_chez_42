/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:09:36 by kaly              #+#    #+#             */
/*   Updated: 2023/06/15 16:22:52 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void handle_signal(int signal)
{
	if (signal == SIGINT)
	{
		write(1, "\nSignal SIGINT reçu. Fermeture du shell.\n", 40);
		exit(EXIT_SUCCESS);
	}
}

static char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

void execute_command(t_data *data)
{
	data->pid = fork();
	if (data->pid == 0)
	{
		//ft_printf("1 %s\n", data->cmd);
		data->cmd = get_cmd(data->cmd_paths, data->cmd);
		execve(data->cmd, data->cmd_args, data->envp);
		ft_printf("%s\n", data->cmd_args[0]);
		perror("Erreur d'exécution de la commande");
		exit(EXIT_FAILURE);
	}
	else if (data->pid < 0)
		perror("Erreur lors de la création du processus");
	else
		wait(NULL);
}

char	*find_path(t_data *data, char *s)
{
	while (ft_strncmp(s, *data->envp, ft_strlen(s)) != 0)
	{
		data->envp++;
	}
	return (*data->envp + (ft_strlen(s) + 1));
}

void shell_loop(t_data *data)
{
	data->env_paths = find_path(data, "PATH");
	data->cmd_paths = ft_split(data->env_paths, ':');
	while (1)
	{
		signal(SIGINT, handle_signal);
		signal(SIGQUIT, SIG_IGN);
		write(1, "notre magnifique minishell >> $ ", 31);

		int index = 0;
		char c;
		data->cmd = malloc(sizeof(char) * 100);
		while (read(0, &c, 1) > 0)
		{
			if (c == '\n')
			{
				data->cmd[index] = '\0';
				break;
			}
			data->cmd[index] = c;
			index++;
		}
		if (ft_strncmp("exit", data->cmd, 4) == 0)
			break;
		else if (ft_strncmp("pwd", data->cmd, 4) == 0)
			ft_printf("%s\n", getcwd(NULL, 0));
		else
			execute_command(data);
	}
}

void	msg_error(char *err)
{
	perror(err);
	exit (1);
}

int main(int argc, char **argv, char **envp)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	data->ac = argc;
	data->av = argv;
	data->envp = envp;
	
	shell_loop(data);
	return 0;
}

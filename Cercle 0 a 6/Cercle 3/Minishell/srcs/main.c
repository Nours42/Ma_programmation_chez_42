/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:09:36 by kaly              #+#    #+#             */
/*   Updated: 2023/06/23 17:04:30 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_cmd(char **paths, char *cmd)
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

void	execute_command(t_data *data)
{
	data->pid = fork();
	//ft_printf("exec command\n");
	if (data->pid == 0)
	{
		data->str_temp2 = get_cmd(data->cmd_paths, data->cmd_args[0]);
		if (data->str_temp2 != NULL)
			execve(data->str_temp2, data->cmd_args, data->envp);
		else
		{
			ft_printf("%s : commande introuvable\n", data->cmd_args[0]);
			exit(EXIT_FAILURE);
		}
		perror("Erreur d'exécution de la commande\n");
		exit(EXIT_FAILURE);
	}
	else if (data->pid < 0)
		perror("Erreur lors de la création du processus\n");
	else
		wait(NULL);
}

void	shell_loop(t_data *data)
{
	while (1)
	{
		signal(SIGQUIT, handle_signal);
		signal(SIGINT, handle_signal);
		write(1, "notre magnifique minishell >> $ ", 32);
		data->str_temp = ft_get_next_line(0);
		if (data->str_temp == NULL)
		{
			ft_printf("\n");
			ft_free_paths(data);
			exit(EXIT_FAILURE);
		}
		if (ft_strcmp("\n", data->str_temp) == 0)
		{
			ft_free_str_temp(1, data);
			shell_loop(data);
		}
		if (ft_strcmp("exit\n", data->str_temp) == 0)
		{
			//ft_printf("exit\n");
			ft_free_str_temp(1, data);
			ft_free_paths(data);
			exit(EXIT_FAILURE);
		}
		data->str_temp = delete_last_char(data->str_temp);
		data->cmd_args = parse(data->str_temp);
		if (find_builtin(data) == 0)
			execute_command(data);
	}
}

int	find_builtin(t_data *data)
{
	if (ft_strcmp("echo", data->cmd_args[0]) == 0)
		ft_echo(data);
	else if (ft_strcmp("cd", data->cmd_args[0]) == 0)
		ft_printf("cd\n");
	else if (ft_strcmp("pwd", data->cmd_args[0]) == 0)
		ft_printf("%s\n", getcwd(NULL, 0));
	else if (ft_strcmp("export", data->cmd_args[0]) == 0)
		ft_printf("export\n");
	else if (ft_strcmp("unset", data->cmd_args[0]) == 0)
		ft_printf("unset\n");
	else if (ft_strcmp("env", data->cmd_args[0]) == 0)
		ft_env(data->envp);
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	(void)argc;
	(void)argv;
	data = (t_data *)malloc(sizeof(t_data));
	data->commands = (t_command *)malloc(sizeof(t_command));
	data->envp = envp;
	init_minishell(data);
	shell_loop(data);
	return (0);
}

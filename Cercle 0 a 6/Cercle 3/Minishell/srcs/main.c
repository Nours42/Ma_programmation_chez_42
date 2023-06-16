/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:09:36 by kaly              #+#    #+#             */
/*   Updated: 2023/06/16 16:23:24 by sdestann         ###   ########.fr       */
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
	if (data->pid == 0)
	{
		data->str_temp = get_cmd(data->cmd_paths, data->str_temp);
		execve(data->str_temp, data->cmd_args, data->envp);
		ft_printf("execute command style : %s\n", data->cmd_args[0]);
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

void	shell_loop(t_data *data)
{
	data->cmd_paths = ft_split(find_path(data, "PATH"), ':');
	while (1)
	{
		signal(SIGINT, handle_signal);
		signal(SIGQUIT, SIG_IGN);
		write(1, "notre magnifique minishell >> $ ", 31);
		data->cmd_args = ft_split(ft_get_next_line(0), ' ');
		int	i = -1;
		while (data->cmd_args[i++])
			ft_printf("%s\n", data->cmd_args[i]);
		if (ft_strcmp("exit\n", data->cmd_args[0]) == 0)
			break ;
		else if (find_builtin(data) == 0)
			execute_command(data);
	}
}

int	find_builtin(t_data *data)
{
	int	i;

	i = 0;
	while (data->cmd_args[i])
	{
		if (ft_strcmp("echo", data->cmd_args[i]) == 0)
			ft_printf("echo\n");
		else if (ft_strcmp("cd\n", data->cmd_args[i]) == 0)
			ft_printf("cd\n");
		else if (ft_strcmp("pwd", data->cmd_args[i]) == 0)
			ft_printf("%s\n", getcwd(NULL, 0));
		else if (ft_strcmp("unset\n", data->cmd_args[i]) == 0)
			ft_printf("unset\n");
		else if (ft_strcmp("env\n", data->cmd_args[i]) == 0)
			ft_printf("env\n");
		i++;
	}
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	data->ac = argc;
	data->av = argv;
	data->envp = envp;
	shell_loop(data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:09:36 by kaly              #+#    #+#             */
/*   Updated: 2023/07/06 13:21:33 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	
	while (*paths)
	{
		if (ft_cmp_paths(cmd, *paths) > 4)
			return (cmd);
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

void	get_l(t_data *data)
{
	char	*tmp;

	if (data->gnl)
	{
		ft_printf("~ avec GNL ~>$ ");
		tmp = ft_get_next_line(0);
		if (!tmp)
			ft_free_all(3, data);
		data->str_temp = ft_substr(tmp, 0, ft_strlen(tmp) - 1);
		free(tmp);
	}
	else
	{
		data->str_temp = readline("~>$ ");
		if (!data->str_temp)
		{
			ft_printf("exit\n");
			ft_free_str_temp(1, data);
			ft_free_paths(data);
			exit(EXIT_FAILURE);
		}
		add_history(data->str_temp);
	}
}

void	shell_loop(t_data *data, char **envp)
{
	struct sigaction	act;
	
	ft_signal(&act, data);
	while (1)
	{
		get_l(data);
		data->cmd_args = parse(data->str_temp);
		give_me_the_money(data);
		if (find_builtin(data, envp) == 0)
			execute_command(data, envp);
	}
}

int	find_builtin(t_data *data, char **envp)
{
	data->piped = 0;
	data->fd_redirect_in = 0;
	data->fd_redirect_out = 0;
	(void)envp;
	if (ft_strcmp("", data->str_temp) == 0)
	{
		ft_free_str_temp(1, data);
		shell_loop(data, envp);
	}
	if (ft_strcmp("exit", data->str_temp) == 0)
	{
		ft_printf("exit\n");
		ft_free_str_temp(1, data);
		ft_free_paths(data);
		exit(EXIT_FAILURE);
	}
	if (ft_strcmp("echo", data->cmd_args[0]) == 0)
		ft_echo(data);
	else if (ft_strcmp("cd", data->cmd_args[0]) == 0)
		ft_cd(data);
	else if (ft_strcmp("pwd", data->cmd_args[0]) == 0)
		ft_printf("%s\n", getcwd(NULL, 0));
	else if (ft_strcmp("export", data->cmd_args[0]) == 0)
		ft_export(data, data->cmd_args[1]);
	else if (ft_strcmp("unset", data->cmd_args[0]) == 0)
		ft_unset(data, data->cmd_args[1]);
	else if (ft_strcmp("env", data->cmd_args[0]) == 0)
		ft_show_env(data);
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	data->commands = (t_command *)malloc(sizeof(t_command));
	if (argc == 2 && !ft_strncmp(argv[1], "gnl", 3)) 
		data->gnl = 1;
	init_minishell(data, envp);
	shell_loop(data, envp);
	return (0);
}

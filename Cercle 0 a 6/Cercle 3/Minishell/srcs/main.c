/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:09:36 by kaly              #+#    #+#             */
/*   Updated: 2023/07/05 15:18:09 by sdestann         ###   ########.fr       */
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

void	shell_loop(t_data *data, char **envp)
{
	//int i = 0;
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
			shell_loop(data, envp);
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
		/*ft_printf("avant\n");
		while(data->cmd_args[i])
		{
			ft_printf("ARGS numero %d : %s\n",i ,data->cmd_args[i]);
			i++;
		}*/
		give_me_the_money(data);
		/*i = 0;
		ft_printf("\napres\n");
		while(data->cmd_args[i])
		{
			ft_printf("ARGS numero %d : %s\n",i ,data->cmd_args[i]);
			i++;
		}*/
		if (find_builtin(data) == 0)
			execute_command(data, envp);
	}
}

int	find_builtin(t_data *data)
{
	int	i;

	i = -1;
	while(data->cmd_args[++i])
		ft_printf("cmd args %d : %s\n", i, data->cmd_args[i]);
//	ft_show_env(data);
	if (ft_strcmp("echo", data->cmd_args[0]) == 0)
		ft_echo(data);
	else if (ft_strcmp("cd", data->cmd_args[0]) == 0)
		ft_printf("cd\n");
	else if (ft_strcmp("pwd", data->cmd_args[0]) == 0)
		ft_printf("%s\n", getcwd(NULL, 0));
	else if (ft_strcmp("export", data->cmd_args[0]) == 0)
		ft_export(data);
	else if (ft_strcmp("unset", data->cmd_args[0]) == 0)
	{
		data->str_to_unset = data->cmd_args[1];
		ft_unset(data);
	}
	else if (ft_strcmp("env", data->cmd_args[0]) == 0)
		ft_show_env(data);
	else
		return (0);
	//ft_free_all(1, data);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	(void)argc;
	(void)argv;
	data = (t_data *)malloc(sizeof(t_data));
	data->commands = (t_command *)malloc(sizeof(t_command));
	init_minishell(data, envp);
	shell_loop(data, envp);
	return (0);
}

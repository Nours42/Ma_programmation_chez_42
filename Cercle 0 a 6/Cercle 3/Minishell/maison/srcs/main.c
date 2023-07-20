/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:09:36 by kaly              #+#    #+#             */
/*   Updated: 2023/07/11 14:21:23 by nours42          ###   ########.fr       */
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

void	get_readline(t_data *data)
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

void	shell_loop(t_data *data, char **envp)
{
	struct sigaction	act;
	int					i;

	ft_signal(&act, data);
	while (1)
	{
		get_readline(data);
		parse(data);
		give_me_the_money(data);
		i = -1;
		// il faut integrer la boucle in end ici
		/*while (++i < data->redirected)
			data->args = data->args->next;*/
		while (data->args->cmd_args[++i])
		{
			data->next_pipe = 0;
			if (ft_strncmp(data->args->cmd_args[i], "|", 1) == 0)
			{
				data->next_pipe = i;
				if (find_builtin(data, envp) == 0)
					execute_command(data, envp);
				data->args->cmd_args = data->args->cmd_args + i + 1;
				i = -1;
			}
		}
		data->next_pipe = 42;
		if (find_builtin(data, envp) == 0)
			execute_command(data, envp);
	}
}

int	find_builtin(t_data *data, char **envp)
{
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
	if (ft_strcmp("echo", data->args->cmd_args[0]) == 0)
		ft_echo(data);
	else if (ft_strcmp("cd", data->args->cmd_args[0]) == 0)
		ft_cd(data);
	else if (ft_strcmp("pwd", data->args->cmd_args[0]) == 0)
		ft_printf("%s\n", getcwd(NULL, 0));
	else if (ft_strcmp("export", data->args->cmd_args[0]) == 0)
		ft_export(data, data->args->cmd_args[1]);
	else if (ft_strcmp("unset", data->args->cmd_args[0]) == 0)
		ft_unset(data, data->args->cmd_args[1]);
	else if (ft_strcmp("env", data->args->cmd_args[0]) == 0)
		ft_show_envp(data);
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
	data->envp = (t_envp *)malloc(sizeof(t_envp));
	data->args = (t_args *)malloc(sizeof(t_args));
	data->std_in = dup(0);
	data->std_out = dup(1);
	init_minishell(data, envp);
	shell_loop(data, envp);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:09:36 by kaly              #+#    #+#             */
/*   Updated: 2023/07/20 11:21:58 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	shell_loop(t_data *data, char **envp)
{
	struct sigaction	act;

	ft_signal(&act, data);
	while (1)
	{
		//active readline et lance le prompt
		get_readline(data);
		//parse ce qui est entrer dans readline
		parsing_prompt(data);
		// recherche les $ et les correspondances dans les elements du parse
		give_me_the_money(data);
		//ft_print_args(data, data->args->cmd_args);
		// recherche les > >> < <<
		check_redirect(data, envp);
		//check_pipe(data);
		//execute_prompt(data, envp);
		data->next_pipe = 42;
		if (data->piped == 0)
			if (find_builtin(data, envp) == 0)
				execute_command(data, envp);
		data->piped = 0;
	}
}

int	find_builtin(t_data *data, char **envp)
{
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
		//ft_free_all(3, data);
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
	init_minishell(data, envp);
	shell_loop(data, envp);
	//ft_free_all(3, data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:09:36 by kaly              #+#    #+#             */
/*   Updated: 2023/07/28 10:52:54 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	if (ft_strlen(cmd) == 0)
		return (NULL);
	if (cmd)
	{
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
	}
	return (NULL);
}

void	get_readline(t_data *data)
{
	if (data->str_temp != NULL)
		ft_free_chars(data->str_temp);
	if (data->redirected != 49)
		data->str_temp = readline("~>$ ");
	else
	{
		data->str_temp = readline("");
		if (data->str_temp == NULL)
		{
			dup2(data->fd_redirect_in, STDIN_FILENO);
			close(data->fd_redirect_in);
			free(data->str_temp);
			data->redirected = 0;
			data->str_temp = readline("~>$ ");
		}
	}
	if (!data->str_temp)
	{
		ft_free_all(3, data);
		ft_printf("Minishell is closed.\nThat's the end of your life !\n");
		exit(EXIT_FAILURE);
	}
	add_history(data->str_temp);
}

void	shell_loop(t_data *data, char **envp)
{
	struct sigaction	act;

	ft_signal(&act, data);
	while (1)
	{
		get_readline(data);
		parse(data, envp);
		ft_printf("shell loop\n");
		// ft_print_args(data);
		ft_print_args_with_start_and_end(data);
		// sera ds le pipe a pres cette ligne
		// pensez a toujours garder en memoire le result du dernier pipe pour $?
		ft_printf("boucle numero %d\n", data->boucle);
		if (data->boucle == 0)
		{
			data->boucle++;
			ft_printf("premier tour\n");
			give_me_the_money(data);
			check_redirect(data, envp);
			data->next_part = 42;
			if (data->redirected == 0)
				if (find_builtin(data, envp) == 0)
					execute_command(data, envp);
			// if (data->fd_redirect_out == 0)
			// 	data->redirected = 0;
			// ft_free_cmd_args(data);
			// data->var->num_words = 0;
		}
		else if (data->boucle > 0)
		{
			ft_printf("je relance de 2\n");
			ft_printf("valeur de data->args_start avant :  %d\n", data->args_start);
			ft_printf("valeur de data->args_end avant :  %d\n", data->args_end);
			data->args_start = data->args_end + 1;
			data->args_end = 5;
			ft_printf("valeur de data->args_start apres :  %d\n", data->args_start);
			ft_printf("valeur de data->args_end apres :  %d\n", data->args_end);
			give_me_the_money(data);
			check_redirect(data, envp);
			data->next_part = 42;
			if (data->redirected == 0)
				if (find_builtin(data, envp) == 0)
					execute_command(data, envp);
			if (data->fd_redirect_out == 0)
				data->redirected = 0;
			ft_free_cmd_args(data);
			data->var->num_words = 0;
			data->boucle++;
		}
		ft_printf("c'est la fin des haricots\n");
		
		//jusque la
	}
}

int	find_builtin(t_data *data, char **envp)
{
	ft_printf("find builtin\n");
	ft_print_args_with_start_and_end(data);
	if (ft_strcmp("", data->str_temp) == 0)
		shell_loop(data, envp);
	if (ft_strcmp("exit", data->str_temp) == 0)
		ft_exit(data);
	else if (ft_strcmp("echo", data->args->cmd_args[data->args_start]) == 0)
		ft_echo(data);
	else if (ft_strcmp("cd", data->args->cmd_args[data->args_start]) == 0)
		ft_cd(data);
	else if (ft_strcmp("pwd", data->args->cmd_args[data->args_start]) == 0)
		ft_pwd();
	else if (ft_strcmp("export", data->args->cmd_args[data->args_start]) == 0)
		ft_export(data, data->args->cmd_args[data->args_start + 1]);
	else if (ft_strcmp("unset", data->args->cmd_args[data->args_start]) == 0)
		ft_unset(data, data->args->cmd_args[data->args_start + 1]);
	else if (ft_strcmp("env", data->args->cmd_args[data->args_start]) == 0)
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
	return (0);
}

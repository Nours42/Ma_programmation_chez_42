/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:09:36 by kaly              #+#    #+#             */
/*   Updated: 2023/07/31 16:53:59 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//pense bete :
// les espaces dans echo      "test" doivent n'en faire qu'un
// penser a faire $? et a stocker le result du dernier pipe
// gerer la modification de path

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
	if (data->original_prompt != NULL)
	{
		ft_free_chars(data->original_prompt);
	}
	if (data->redirected != 49)
	{
		// ft_printf("get_readline\n");
		// ft_printf("original prompt = %s\n", data->original_prompt);
		data->original_prompt = readline("~>$ ");
	}
	else
	{
		data->original_prompt = readline("");
		if (data->original_prompt == NULL)
		{
			dup2(data->fd_redirect_in, STDIN_FILENO);
			close(data->fd_redirect_in);
			free(data->original_prompt);
			data->redirected = 0;
			data->original_prompt = readline("~>$ ");
		}
	}
	if (!data->original_prompt)
	{
		ft_free_all(3, data);
		ft_printf("Minishell is closed.\nThat's the end of your life !\n");
		exit(EXIT_FAILURE);
	}
	add_history(data->original_prompt);
}

void	shell_loop(t_data *data, char **envp)
{
	struct sigaction	act;
	int					i;

	ft_signal(&act, data);
	while (1)
	{
		get_readline(data);
		parse(data, envp);
		ft_printf("shell loop\n");
		ft_print_args(data);
		give_me_the_money(data);
		how_many_pipe(data); // trouve le nombre de pipe et les enregistre
		check_redirect(data, envp);
		ft_print_args_with_start_and_end(data);
		ft_print_pipe_args(data);
		data->next_part = 42;
		if (data->redirected == 0 && data->pipe->nbr_of_pipe == 0)
		{
			if (find_builtin(data, envp) == 0)
				execute_command(data, envp);
		}
		else if (data->pipe->nbr_of_pipe > 0)
		{
			data->pipe->idx = -1;
			while (++i <= data->pipe->nbr_of_pipe)
			{
				init_minishell(data); // initialisation des valeurs avant l'execution du bloc entre pipe
				data->args_start = data->args_end[0] + 2;
				data->args_end++;
				give_me_the_money(data);
				check_redirect(data, envp);
				//fonction qui definit les dup2 entre les blocs
				data->next_part = 42;
				if (data->redirected == 0)
					if (find_builtin(data, envp) == 0)
						execute_command(data, envp);
				if (data->fd_redirect_out == 0)
					data->redirected = 0;
				ft_free_cmd_args(data);
				data->var->num_words = 0;
			}
			data->boucle++;
		}
		else
			ft_printf("c'est la fin des haricots\n");
		init_first(data, envp); //re initailise en cas de nouveau prompt
	}
}

int	find_builtin(t_data *data, char **envp)
{
	// ft_printf("find builtin\n");
	// ft_print_args_with_start_and_end(data);
	if (ft_strcmp("", data->original_prompt) == 0)
		shell_loop(data, envp);
	if (ft_strcmp("exit", data->original_prompt) == 0)
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
	init_first(data, envp);
	shell_loop(data, envp);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:09:36 by kaly              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/08/10 16:16:59 by sdestann         ###   ########.fr       */
=======
/*   Updated: 2023/08/10 13:26:21 by sdestann         ###   ########.fr       */
>>>>>>> bb6a7fbea488da8d2a8258804339c1d5318b2f78
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//pense bete :
// les espaces dans echo      "test" doivent n'en faire qu'un
<<<<<<< HEAD
// shlvl + 1
// et les leaks mais bon...
=======
// et les leaks mais bon...

int	ft_cmp_paths(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (i);
}


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
			if (ft_cmp_paths(cmd, *paths) >= 4)
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
>>>>>>> bb6a7fbea488da8d2a8258804339c1d5318b2f78

void	get_readline(t_data *data)
{
	if (data->original_prompt != NULL)
		ft_free_chars(data->original_prompt);
	if (data->redirected != 49)
	{
		free(data->original_prompt);
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
<<<<<<< HEAD
		control_d(data);
=======
	{
		ft_free_all(0, data);
		ft_printf("Minishell is closed.\nThat's the end of your life !\n");
		// free(data->var->word);
		rl_clear_history();
		exit(EXIT_FAILURE);
	}
>>>>>>> bb6a7fbea488da8d2a8258804339c1d5318b2f78
	add_history(data->original_prompt);
}

void	control_d(t_data *data)
{
	ft_free_all(0, data);
	ft_printf("Minishell is closed.\nThat's the end of your life !\n");
	rl_clear_history();
	exit(EXIT_FAILURE);
}

void	shell_loop(t_data *data, char **envp)
{
	struct sigaction	act;

	data->pipe->idx = -1;
	ft_signal(&act, data);
	while (1)
	{
		get_readline(data);
		parse(data, envp);
		give_me_the_money(data);
		how_many_pipe(data);
		data->next_part = 42;
		while (++(data->pipe->idx) < data->pipe->nbr_of_pipe)
		{
			execute_pipes(data, envp);
			if (data->pipe->nbr_of_pipe - data->pipe->idx > 1)
			{
				data->args_start = data->args_end[0] + 2;
				data->args_end[0] = data->args_end[data->pipe->idx + 1];
			}
		}
		exec_last(data, envp);
		dup2(data->pipe->infile, STDIN_FILENO);
		dup2(data->pipe->outfile, STDOUT_FILENO);
		init_first(data, envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	(void)argc;
	(void)argv;
	data = (t_data *)malloc(sizeof(t_data));
	if (envp[0] == NULL)
	{
		ft_printf("creation\n");
		init_envp_in_i(data);
	}
	data->redirected = 3;
	init_first(data, envp);
	shell_loop(data, envp);
	return (0);
}

void	init_envp_in_i(t_data *data)
{
<<<<<<< HEAD
	int		i;
	char	**envp2;
=======
	int	i;
	char **envp2;
>>>>>>> bb6a7fbea488da8d2a8258804339c1d5318b2f78

	i = 3;
	envp2 = (char **)malloc(sizeof(char *) * 3);
	envp2[0] = ft_strdup("");
<<<<<<< HEAD
	envp2[1] = ft_strdup("SHLVL=1\0");
=======
	envp2[1] = ft_strdup("SHLVL=1\0"); //ca il faut l'incrementer si minishelle dans minishell
>>>>>>> bb6a7fbea488da8d2a8258804339c1d5318b2f78
	envp2[2] = ft_strdup(getcwd(NULL, 0));
	envp2[3] = ft_strdup("");
	data->envp = (t_envp *)malloc(sizeof(t_envp));
	data->envp->next = NULL;
	data->envp->str = NULL;
	while (--i > 0)
		add_str_endlst(data->envp, envp2[i]);
	free(envp2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <kaly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:41:05 by nours42           #+#    #+#             */
/*   Updated: 2023/08/02 15:39:28 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_envp(t_data *data, char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
		add_str_endlst(data->envp, envp[i]);
}

void	init_parse(t_data *data)
{
	data->var->i = 0;
	data->var->num_words = 0;
	data->var->brk = 0;
	if (data->var->word != NULL)
		ft_free_chars(data->var->word);
	if (data->var->str != NULL)
		ft_free_chars(data->var->str);
}

void	init_first(t_data *data, char **envp)
{
	int	i;

	i = 0;
	data->boucle = 0;
	data->end = 0;
	data->envp = (t_envp *)malloc(sizeof(t_envp));
	data->envp->next = NULL;
	data->envp->str = NULL;
	init_envp(data, envp);
	if (data->var)
	{
		ft_printf("clear data->var\n");
		free_and_clear_var(data);
		ft_printf("create data->var\n");
		data->var = (t_var *)malloc(sizeof(t_var));
		while (i <= 99)
			data->var->commands[i++] = NULL;
		data->var->word = NULL;
		data->var->str = NULL;
		data->var->quote_type = 0;
		data->var->num_words = 0;
	}
	else
	{
		ft_printf("create data->var\n");
		data->var = (t_var *)malloc(sizeof(t_var));
		while (i <= 99)
			data->var->commands[i++] = NULL;
		data->var->word = NULL;
		data->var->str = NULL;
		data->var->quote_type = 0;
		data->var->num_words = 0;
	}
	if (data->args)
	{
		ft_printf("clear data->args\n");
		free_and_clear_args(data);
		ft_printf("create data->args\n");
		data->args = (t_args *)malloc(sizeof(t_args));
		data->args->cmd_paths = ft_split(find_path("PATH", data->envp), ':');
	}
	else
	{
		ft_printf("create data->args\n");
		data->args = (t_args *)malloc(sizeof(t_args));
		data->args->cmd_paths = ft_split(find_path("PATH", data->envp), ':');
	}
	data->args_start = 0;
	data->args_end = (int *)malloc(sizeof(int) * 100);
	data->args_end[0] = 0;
	data->args_max = 0;
	data->fd_redirect_out = 0;
	data->redirected = 0;
	data->next_part = 42;
	data->original_prompt = NULL;
	data->cmd_prompt = NULL;
	if (data->pipe && data->pipe->nbr_of_pipe != 0)
	{
		ft_printf("clear data->pipe\n");
		free_and_clear_pipe(data);
		ft_printf("create data->pipe\n");
		data->pipe = (t_pipe *)malloc(sizeof(t_pipe));
		data->pipe->nbr_of_pipe = 0;
		data->pipe->infile = dup(STDIN_FILENO);
		data->pipe->outfile = dup(STDOUT_FILENO);
	}
	else
	{
		ft_printf("create data->pipe\n");
		data->pipe = (t_pipe *)malloc(sizeof(t_pipe));
		data->pipe->nbr_of_pipe = 0;
		data->pipe->infile = dup(STDIN_FILENO);
		data->pipe->outfile = dup(STDOUT_FILENO);
	}
	data->pid = 0;
	data->pid_last = 0;
	ft_printf("////// fin de l'initialiation /////\n");
	// print_all(data);
}

void	init_minishell(t_data *data)
{
	free_and_clear_var(data);
	data->fd_redirect_out = 0;
	data->next_part = 42;
}

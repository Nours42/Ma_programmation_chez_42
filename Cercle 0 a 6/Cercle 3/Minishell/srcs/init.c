/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:41:05 by nours42           #+#    #+#             */
/*   Updated: 2023/07/29 18:26:49 by nours42          ###   ########.fr       */
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
	//initialiser les pipes
}

void	init_first(t_data *data, char **envp)
{
	int	i;

	i = 0;
	data->boucle = 0;
	data->envp = (t_envp *)malloc(sizeof(t_envp));
	data->envp->next = NULL;
	data->envp->str = NULL;
	init_envp(data, envp);
	data->args = (t_args *)malloc(sizeof(t_args));
	data->args->cmd_paths = ft_split(find_path("PATH", data->envp), ':');
	data->args_start = 0;
	data->args_end = (int *)malloc(sizeof(int) * 100);
	data->args_end[0] = 0;
	data->var = (t_command *)malloc(sizeof(t_command));
	while (i <= 99)
		data->var->commands[i++] = NULL;
	data->var->word = NULL;
	data->var->str = NULL;
	data->var->quote_type = 0;
	data->var->num_words = 0;
	data->fd_redirect_out = 0;
	data->redirected = 0;
	data->next_part = 42;
	data->original_prompt = NULL;
	data->cmd_prompt = NULL;
	data->pipe = (t_pipe *)malloc(sizeof(t_pipe));
	data->pipe->nbr_of_pipe = 0;
}

void	init_minishell(t_data *data)
{
	// int	i;

	// i = 0;
	// while (i <= 99)
	// 	data->var->commands[i++] = NULL;
	data->var->word = NULL;
	data->var->str = NULL;
	data->var->quote_type = 0;
	data->var->num_words = 0;
	data->fd_redirect_out = 0;
	data->redirected = 0;
	data->next_part = 42;
	// data->original_prompt = NULL;
	// data->cmd_prompt = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:41:05 by nours42           #+#    #+#             */
/*   Updated: 2023/07/27 17:34:20 by sdestann         ###   ########.fr       */
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
	//data->pipe->nbr_of_pipe = 0;
}
/*	var

	char	*commands[100];

	pipe

	char		**cmd;
	int			infile;
	int			outfile;
	int			*pipe;
	int			*pipe_idx;
	int			cmd_nbrs;
	int			nbr_of_pipe;
	int			idx;
*/

void	init_minishell(t_data *data, char **envp)
{
	int	i;

	i = 0;
	data->envp = (t_envp *)malloc(sizeof(t_envp));
	data->args = (t_args *)malloc(sizeof(t_args));
	//data->pipe = (t_pipe *)malloc(sizeof(t_pipe));
	data->envp->next = NULL;
	data->envp->str = NULL;
	init_envp(data, envp);
	data->args->cmd_paths = ft_split(find_path("PATH", data->envp), ':');
	data->str_temp = NULL;
	data->str_temp2 = NULL;
	data->fd_redirect_out = 0;
	data->redirected = 0;
	data->next_part = 42;
	data->var = (t_command *)malloc(sizeof(t_command));
	while (i <= 99)
		data->var->commands[i++] = NULL;
	data->var->word = NULL;
	data->var->str = NULL;
	data->var->quote_type = 0;
	data->var->num_words = 0;
	// data->pipe->cmd_nbrs = 1;
	// data->pipe->infile = 0;
	// data->pipe->outfile = 1;
	// data->pipe->pipe_idx = (int *)malloc(sizeof(int) * 1);
	//data->pipe->pipe_idx = (int *)malloc(sizeof(int) * 1);
	//data->pipe->pipe_idx[0] = 0;
}

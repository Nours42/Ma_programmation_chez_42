/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:00:42 by sdestann          #+#    #+#             */
/*   Updated: 2023/07/27 17:32:48 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free_cmd_args(t_data *data)
{
	int	i;

	i = -1;
	while (++i < (int)data->var->num_words)
	{
		free(data->args->cmd_args[i]);
		data->args->cmd_args[i] = NULL;
	}
}

void	ft_free_args(t_data *data)
{
	if (data->var->num_words > 0)
	{
		ft_free_cmd_args(data);
	}
	//free(data->args->cmd_args);
}

void	ft_free_paths(t_data *data)
{
	int	i;

	i = -1;
	while (data->args->cmd_paths[++i] != NULL)
		free(data->args->cmd_paths[i]);
	free(data->args->cmd_paths);
}

void	ft_free_str_temp(int i, t_data *data)
{
	if (i == 1 && data->str_temp != NULL)
		free(data->str_temp);
	else if (i == 2 && data->str_temp2 != NULL)
		free(data->str_temp2);
	else if (i == 3)
	{
		if (data->str_temp != NULL)
			free(data->str_temp);
		if (data->str_temp2 != NULL)
			free(data->str_temp2);
	}
}

void	ft_free_envp(t_data *data)
{
	t_envp	*temp;

	temp = data->envp;
	while (data->envp != NULL)
	{
		temp = data->envp;
		data->envp = data->envp->next;
		free(temp->str);
		free(temp);
	}
}

void	ft_free_command_var(t_data *data)
{
	 int	i;
	
	// if (data->var->word != NULL)
	// {
	// 	free(data->var->word);
	// 	data->var->word = NULL;
	// }
	if (data->var->str != NULL)
	{
		free(data->var->str);
		data->var->str = NULL;
	}
	i = -1;
	while (++i < (int)data->var->num_words)
		if (data->var->commands[i] != NULL)
		{
			ft_printf("data->var->commands[%d] : %s\n", i, data->var->commands[i]);
			free(data->var->commands[i]);
		}
	free(data->var);
}

void	ft_free_all(int i, t_data *data)
{
	ft_free_envp(data);
	ft_free_str_temp(i, data);
	ft_free_paths(data);
	ft_free_args(data);
	free(data->args);
	//free(data->pipe->pipe_idx);
	//free(data->pipe);
	ft_free_command_var(data);
	free(data);
}

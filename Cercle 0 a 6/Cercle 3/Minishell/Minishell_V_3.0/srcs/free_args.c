/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:50:18 by kaly              #+#    #+#             */
/*   Updated: 2023/08/11 11:53:31 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// pour info :
// 
// typedef struct s_args
// {
// 	char		**cmd_paths;
// 	char		**cmd_args;
// }				t_args;

// void	init_args(t_data *data)
// {
// 	data->args = (t_args *)malloc(sizeof(t_args));
// 	data->args->cmd_paths = ft_split(find_path("PATH", data->envp), ':');
// 	data->args_start = 0;
// 	data->args_end = (int *)malloc(sizeof(int) * 100);
// 	data->args_end[0] = 0;
// 	data->args_max = 0;
// }

void	ft_free_paths(t_data *data)
{
	int	i;

	i = -1;
	while (data->args->cmd_paths[++i] != NULL)
		free(data->args->cmd_paths[i]);
	free(data->args->cmd_paths);
}

void	ft_free_cmd_args(t_data *data)
{
	int	i;

	i = -1;
	while (++i < (int)data->var->num_words)
	{
		if (data->args->cmd_args[i] && data->args->cmd_args[i] != NULL)
		{
			data->args->cmd_args[i] = NULL;
			free(data->args->cmd_args[i]);
		}
	}
}

void	free_and_clear_args(t_data *data)
{
	ft_free_paths(data);
	// free(data->args->cmd_args[0]);
	free(data->args_end);
	free(data->args);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <kaly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:50:18 by kaly              #+#    #+#             */
/*   Updated: 2023/08/02 13:30:21 by kaly             ###   ########.fr       */
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
		free(data->args->cmd_args[i]);
		data->args->cmd_args[i] = NULL;
	}
}

void    free_and_clear_args(t_data *data)
{
	ft_free_paths(data);
	ft_free_cmd_args(data);
	// free(data->args);
}

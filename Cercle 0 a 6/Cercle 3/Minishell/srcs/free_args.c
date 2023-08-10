/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:50:18 by kaly              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/08/10 14:36:50 by sdestann         ###   ########.fr       */
=======
/*   Updated: 2023/08/09 15:05:18 by sdestann         ###   ########.fr       */
>>>>>>> bb6a7fbea488da8d2a8258804339c1d5318b2f78
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
	// ft_printf("%d\n", (int)data->var->num_words);
	// if (data->args->cmd_args[0] != NULL)
	// 	ft_printf("%s\n", data->args->cmd_args[0]);
	// if (data->args->cmd_args[1] != NULL)
	// 	ft_printf("%s\n", data->args->cmd_args[1]);
	// if (data->args->cmd_args[2] != NULL)
	// 	ft_printf("%s\n", data->args->cmd_args[2]);
	// if (data->args->cmd_args[3] != NULL)
	// 	ft_printf("%s\n", data->args->cmd_args[3]);
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
	ft_free_cmd_args(data);
	free(data->args_end);
	free(data->args);
}

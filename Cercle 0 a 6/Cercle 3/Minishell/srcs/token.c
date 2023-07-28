/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:50:42 by sdestann          #+#    #+#             */
/*   Updated: 2023/07/28 10:11:11 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_redirect(t_data *data, char **envp)
{
	int		i;

	i = data->args_start;
	while (i <= data->args_end)
	{
		//ft_printf("avant redirect\n");
		//ft_print_args(data);
		if (ft_strcmp("<", data->args->cmd_args[i]) == 0)
			redirect_simple_left(data, envp, i);
		else if (ft_strcmp("<<", data->args->cmd_args[i]) == 0)
			redirect_dobble_left(data, envp, i);
		else if (ft_strcmp(">>", data->args->cmd_args[i]) == 0)
			redirect_dobble_right(data, envp, i);
		else if (ft_strcmp(">", data->args->cmd_args[i]) == 0)
			redirect_simple_right(data, envp, i);
		else if (ft_strcmp("|", data->args->cmd_args[i]) == 0)
			child(data, envp);
		else if (ft_strcmp("$?", data->args->cmd_args[i]) == 0)
			ft_dolls_and(data, envp);
		else if (ft_strcmp("&&", data->args->cmd_args[i]) == 0)
			dobble_and(data, envp);
		i++;
		//ft_printf("apres redirect\n");
		//ft_print_args(data);
	}
}

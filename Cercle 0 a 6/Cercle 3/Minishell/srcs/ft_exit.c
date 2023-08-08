/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:12:14 by sdestann          #+#    #+#             */
/*   Updated: 2023/08/05 14:18:39 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_exit(t_data *data)
{
	int	i;

	i = -1;
	while (data->args->cmd_args[++i])
	{
		if (ft_strcmp("exit", data->args->cmd_args[i]) == 0)
			ft_exit(data);
	}
	return ;
}

void	ft_exit(t_data *data)
{
	ft_printf("exit\n");
	if (data->pid_last > 0)
		kill(data->pid_last, SIGKILL);
	ft_free_all(3, data);
	data->kill_process = 1;
	close(data->pipe->infile);
	exit(EXIT_FAILURE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:19:39 by jmetezea          #+#    #+#             */
/*   Updated: 2023/06/27 11:37:28 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_env(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
		ft_printf("%s\n", envp[i]);
}

// attention si echo n'est pas dans "" il imprime tous les args suivants.
void	ft_echo(t_data *data)
{
	if (data->cmd_args[1] != NULL)
	{
		if (ft_strcmp("-n", data->cmd_args[1]) == 0
			&& data->cmd_args[2] != NULL)
			ft_printf("%s", data->cmd_args[2]);
		else if (ft_strcmp("-n", data->cmd_args[1]) == 0)
			return ;
		else
			ft_printf("%s\n", data->cmd_args[1]);
	}
	else
		ft_printf("\n");
}

void	msg_error(char *err)
{
	perror(err);
	exit (1);
}

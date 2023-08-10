/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:35:28 by sdestann          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/08/10 14:40:45 by sdestann         ###   ########.fr       */
=======
/*   Updated: 2023/08/09 17:19:03 by sdestann         ###   ########.fr       */
>>>>>>> bb6a7fbea488da8d2a8258804339c1d5318b2f78
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	find_builtin_inside(t_data *data)
{
<<<<<<< HEAD
	if ((ft_strcmp("echo", data->args->cmd_args[data->args_start]) == 0)
		&& (ft_strcmp("$?", data->args->cmd_args[data->args_start + 1]) == 0))
=======
	// int	status;

	if ((ft_strcmp("echo", data->args->cmd_args[data->args_start]) == 0) && (ft_strcmp("$?", data->args->cmd_args[data->args_start + 1]) == 0))
>>>>>>> bb6a7fbea488da8d2a8258804339c1d5318b2f78
	{
		ft_printf("%d\n", data->error_number / 256);
		exit(EXIT_SUCCESS);
	}
	if (ft_strcmp("echo", data->args->cmd_args[data->args_start]) == 0)
		ft_echo(data);
	else if (ft_strcmp("pwd", data->args->cmd_args[data->args_start]) == 0)
		ft_pwd();
	else if (ft_strcmp("env", data->args->cmd_args[data->args_start]) == 0)
		ft_print_envp(data);
	else if (ft_strcmp("$?", data->args->cmd_args[data->args_start]) == 0)
	{
		ft_printf("%d : commande introuvable\n", data->error_number / 256);
		exit(EXIT_SUCCESS);
	}
<<<<<<< HEAD
	return ;
=======
		return ;
>>>>>>> bb6a7fbea488da8d2a8258804339c1d5318b2f78
}

int	find_builtin_outside(t_data *d)
{
	if (ft_strcmp("export", d->args->cmd_args[d->args_start]) == 0)
	{
		ft_export(d, d->args->cmd_args[d->args_start + 1]);
		return (1);
	}
	else if (ft_strcmp("unset", d->args->cmd_args[d->args_start]) == 0)
	{
		ft_unset(d, ft_strcat(d->args->cmd_args[d->args_start + 1], "="));
		return (1);
	}
	else if (ft_strcmp("cd", d->args->cmd_args[d->args_start]) == 0)
	{
		ft_cd(d);
		return (1);
	}
	else
		return (0);
}

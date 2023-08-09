/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:35:28 by sdestann          #+#    #+#             */
/*   Updated: 2023/08/09 13:34:55 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	find_builtin_inside(t_data *data)
{
	// int	status;

	if (ft_strcmp("echo", data->args->cmd_args[data->args_start]) == 0)
		ft_echo(data);
	else if (ft_strcmp("pwd", data->args->cmd_args[data->args_start]) == 0)
		ft_pwd();
	else if (ft_strcmp("env", data->args->cmd_args[data->args_start]) == 0)
		ft_print_envp(data);
	else if (ft_strcmp("$?", data->args->cmd_args[data->args_start]) == 0)
	{
		ft_printf("%d\n", data->error_number / 256);
		exit(EXIT_SUCCESS);
	}
	else
		return ;
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

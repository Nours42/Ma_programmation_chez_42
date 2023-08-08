/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:35:28 by sdestann          #+#    #+#             */
/*   Updated: 2023/08/08 14:49:08 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	find_builtin_inside(t_data *data)
{
	if (ft_strcmp("echo", data->args->cmd_args[data->args_start]) == 0)
		ft_echo(data);
	else if (ft_strcmp("pwd", data->args->cmd_args[data->args_start]) == 0)
		ft_pwd();
	else if (ft_strcmp("env", data->args->cmd_args[data->args_start]) == 0)
		ft_print_envp(data);
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

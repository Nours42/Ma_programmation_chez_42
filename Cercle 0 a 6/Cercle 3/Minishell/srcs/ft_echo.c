/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:29:56 by nours42           #+#    #+#             */
/*   Updated: 2023/08/08 16:39:05 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_echo(t_data *d)
{
	int	i;
	int	n;
	
	i = 0;
	n = 0;
	if (d->args->cmd_args[d->args_start + 1] != NULL && ft_strcmp("<", d->args->cmd_args[d->args_start + 1]) != 0)
	{
		if (ft_strcmp("-n", d->args->cmd_args[d->args_start + 1]) == 0 && d->args->cmd_args[d->args_start + 2] != NULL)
		{
			i++;
			n++;
		}
		else if (ft_strcmp("-n", d->args->cmd_args[d->args_start + 1]) == 0 && (d->args->cmd_args[d->args_start + 2] == NULL))
			return ;
		while ((d->args_start + i <= d->args_end[0]) && d->args->cmd_args[i] && d->next_part > i)
		{
			i++;
			if ((n == 0 && i == 1) || (n == 1 && i == 2))
				ft_printf("%s", d->args->cmd_args[d->args_start + i]);
			else if (((n == 0 && i > 1) || (n == 1 && i > 2)) && d->args_start + i <= d->args_end[0])
				ft_printf(" %s", d->args->cmd_args[d->args_start + i]);
		}
		if (ft_strcmp("-n", d->args->cmd_args[d->args_start + 1]) != 0)
			ft_printf("\n");
	}
	else
		ft_printf("\n");
	exit(EXIT_SUCCESS);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dobble_and.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:04:58 by kaly              #+#    #+#             */
/*   Updated: 2023/08/08 14:38:47 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// void	dobble_and(t_data *d, char **envp)
// {
// 	int	i; 

// 	i = -1;
// 	while (d->args->cmd_args[++i])
// 	{
// 		d->next_part = 0;
// 		if (ft_strncmp(d->args->cmd_args[i], "&&", 2) == 0)
// 		{
// 			d->next_part = i;
// 			if (ft_strcmp("exit", d->original_prompt) == 0)
// 				ft_exit(d);
// 			else if (ft_strcmp("export", d->args->cmd_args[d->args_start]) == 0)
// 				ft_export(d, d->args->cmd_args[d->args_start + 1]);
// 			else if (ft_strcmp("unset", d->args->cmd_args[d->args_start]) == 0)
// 				ft_unset(d, d->args->cmd_args[d->args_start + 1]);
// 			else
// 			{
// 				find_builtin(d);
// 				execute_cmd(d, envp);
// 			}
// 			d->args->cmd_args = d->args->cmd_args + i + 1;
// 			i = -1;
// 		}
// 	}
// 	d->next_part = 42;
// 	if (ft_strcmp("exit", d->original_prompt) == 0)
// 		ft_exit(d);
// 	else if (ft_strcmp("export", d->args->cmd_args[d->args_start]) == 0)
// 		ft_export(d, d->args->cmd_args[d->args_start + 1]);
// 	else if (ft_strcmp("unset", d->args->cmd_args[d->args_start]) == 0)
// 		ft_unset(d, d->args->cmd_args[d->args_start + 1]);
// 	else
// 	{
// 		find_builtin(d);
// 		execute_cmd(d, envp);
// 	}
// 	d->redirected = 1;
// }

// void	ft_dolls_and(t_data *data, char **envp)
// {
// 	data->redirected = 1;
// 	if (!envp)
// 		return ;
// 	ft_printf("faut crerr la fonction $? \n");
// }

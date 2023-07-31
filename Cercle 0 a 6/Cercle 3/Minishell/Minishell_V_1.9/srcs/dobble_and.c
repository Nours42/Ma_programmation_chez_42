/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dobble_and.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:04:58 by kaly              #+#    #+#             */
/*   Updated: 2023/07/25 00:03:17 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	dobble_and(t_data *data, char **envp)
{
	int	i; 

	i = -1;
	while (data->args->cmd_args[++i])
	{
		data->next_part = 0;
		if (ft_strncmp(data->args->cmd_args[i], "&&", 2) == 0)
		{
			data->next_part = i;
			if (find_builtin(data, envp) == 0)
				execute_command(data, envp);
			data->args->cmd_args = data->args->cmd_args + i + 1;
			i = -1;
		}
	}
	data->next_part = 42;
	if (find_builtin(data, envp) == 0)
		execute_command(data, envp);
	data->redirected = 1;
}

void	ft_dolls_and(t_data *data, char **envp)
{
	data->redirected = 1;
	if (!envp)
		return ;
	ft_printf("faut crerr la fonction $? \n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:19:39 by jmetezea          #+#    #+#             */
/*   Updated: 2023/07/06 10:27:13 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_show_env(t_data *data)//affiche la liste 
{
	int	i;
	t_envp	*show_env;
	
	show_env = data->env;
	if (!show_env)
		return ;
	i = 1;
	while (show_env != NULL)
	{
		printf("nb %d : %s\n", i, show_env->str);
		show_env = show_env->next;
		i++;
	}
}

// attention si echo n'est pas dans "" il imprime tous les args suivants.
void	ft_echo(t_data *data)
{
	int	i;
	if (data->cmd_args[1] != NULL)
	{
		if (ft_strcmp("-n", data->cmd_args[1]) == 0
			&& data->cmd_args[2] != NULL)
		{
			i = 1;
			while(data->cmd_args[++i])
				ft_printf("%s", data->cmd_args[i]);
		}
		else if (ft_strcmp("-n", data->cmd_args[1]) == 0)
			return ;
		else
		{
			i = 0;
			while(data->cmd_args[++i])
				ft_printf("%s\n", data->cmd_args[i]);
		}
	}
	else
		ft_printf("\n");
}

void	msg_error(char *err)
{
	perror(err);
	exit (1);
}
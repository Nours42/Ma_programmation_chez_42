/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:19:39 by jmetezea          #+#    #+#             */
/*   Updated: 2023/06/29 13:57:43 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_delete_arg_env(t_data *data)
{
	t_envp  *delete;
	t_envp  *temp;

	delete = data->env;
	if (ft_strncmp(data->cmd_args[1], delete->str, ft_strlen(data->cmd_args[1])) == 0)
	{
		temp = delete;
		data->env = delete->next;
	}
	else
	{
		while (ft_strncmp(data->cmd_args[1], delete->next->str, ft_strlen(data->cmd_args[1])) != 0)
			delete = delete->next;
		temp = delete->next;
		delete->next = delete->next->next;
	}
	free(temp->str);
	free(temp);
}

void	ft_unset (t_data *data)
{
	int a;
	t_envp  *list;

// rajouter un char * de la string a unset
	a = 0;
	list = data->env;
	while(list->next && a == 0 )
	{
		if (ft_strncmp(data->cmd_args[1], list->str, ft_strlen(data->cmd_args[1])) == 0)
		{
				ft_printf("la variable est trouve\n%s\n", list->str);
			ft_delete_arg_env(data);
			a = 1;
		}
		if (a != 1)
			list = list->next;
	}
//	ft_show_env(data);
	if (a == 0)
		ft_printf("la variable n'a pas ete trouve dans lenvironnement\n");
}
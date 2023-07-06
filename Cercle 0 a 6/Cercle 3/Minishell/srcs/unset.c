/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:19:39 by jmetezea          #+#    #+#             */
/*   Updated: 2023/07/06 13:38:03 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_delete_arg_env(t_data *data, char *args)
{
	t_envp  *delete;
	t_envp  *temp;

	delete = data->env;
	if (ft_strncmp(args, delete->str, ft_strlen(args)) == 0)
	{
		temp = delete;
		data->env = delete->next;
	}
	else
	{
		while (ft_strncmp(args, delete->next->str, ft_strlen(args)) != 0)
			delete = delete->next;
		temp = delete->next;
		delete->next = delete->next->next;
	}
	free(temp->str);
	free(temp);
}

void	ft_unset (t_data *data, char *args)
{
	int a;
	t_envp  *list;

	a = 0;
	list = data->env;
	while (list && a == 0)
	{
		if ((ft_strncmp(args, list->str, ft_strlen(args)) == 0) 
			&& (list->str[ft_strlen(args)] == '='))
		{
			//ft_printf("la variable %s a ete trouvee\n", list->str);
			ft_delete_arg_env(data, args);
			a = 1;
		}
		list = list->next;
	}
	if (a == 0)
		ft_printf("la variable n'a pas ete trouve dans l'environnement\n");
}
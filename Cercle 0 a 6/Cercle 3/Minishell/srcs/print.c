/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:19:39 by jmetezea          #+#    #+#             */
/*   Updated: 2023/07/07 16:19:39 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_show_envp(t_data *data)//affiche la liste 
{
	int	i;
	t_envp	*show_envp;
	
	show_envp = data->envp;
	if (!show_envp)
		return ;
	i = 1;
	while (show_envp != NULL)
	{
		printf("nb %d : %s\n", i, show_envp->str);
		show_envp = show_envp->next;
		i++;
	}
}

void	ft_print_args(t_data *data, char **args)
{
	int	i;

	i = -1;
	while(args[++i])
		ft_printf("%s \n", args[i]);
	ft_printf("next_pipe is in : %d\n", data->next_pipe);
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
			//ft_printf("echo i : %d\n", i);
			//ft_printf("data->next_pipe : %d\n", data->next_pipe);
			while(data->cmd_args[++i] && data->next_pipe > i)
				ft_printf("%s", data->cmd_args[i]);
		}
		else if (ft_strcmp("-n", data->cmd_args[1]) == 0)
			return ;
		else
		{
			i = 0;
			//ft_printf("echo i : %d\n", i);
			//ft_printf("data->next_pipe : %d\n", data->next_pipe);
			while(data->cmd_args[++i] && data->next_pipe > i)
			{
				if (i == 1)
					ft_printf("%s", data->cmd_args[i]);
				else if (i > 1)
					ft_printf(" %s", data->cmd_args[i]);
			}
			ft_printf("\n");
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
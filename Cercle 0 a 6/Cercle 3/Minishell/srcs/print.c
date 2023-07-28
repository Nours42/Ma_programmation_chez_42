/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:19:39 by jmetezea          #+#    #+#             */
/*   Updated: 2023/07/28 10:51:03 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//affiche la liste a supprimer avant le dernier push
void	ft_show_envp(t_data *data)
{
	int		i;
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

void	ft_print_args(t_data *data)
{
	int	i;

	i = -1;
	while (data->args->cmd_args[++i])
		ft_printf("d->args->cmd_args[%d] : |%s| \n", i, data->args->cmd_args[i]);
}

void	ft_print_args_with_start_and_end(t_data *data)
{
	int	i;

	i = data->args_start;
	ft_printf("data->args_start : %d\n", data->args_start);
	ft_printf("data->args_end : %d\n", data->args_end);
	while (i <= data->args_end)
	{
		ft_printf("d->args->cmd_args[%d] : |%s| \n", i, data->args->cmd_args[i]);
		i++;
	}

}

// attention si echo n'est pas dans "" il imprime tous les args suivants.
void	ft_echo(t_data *data)
{
	int	i;

	ft_printf("ft_echo\n");
	ft_print_args_with_start_and_end(data);
	if (data->args->cmd_args[data->args_start + 1] != NULL
		&& ft_strcmp("<", data->args->cmd_args[data->args_start + 1]) != 0)
	{
		if (ft_strcmp("-n", data->args->cmd_args[data->args_start + 1]) == 0
			&& data->args->cmd_args[data->args_start + 2] != NULL)
		{
			ft_printf("ft_echo -n\n");
			ft_print_args_with_start_and_end(data);
			i = 1;
			while ((data->args_start + i <= data->args_end) && data->args->cmd_args[++i] && data->next_part > i)
				ft_printf("%s", data->args->cmd_args[data->args_start + i]);
		}
		else if (ft_strcmp("-n", data->args->cmd_args[data->args_start + 1]) == 0)
			return ;
		else
		{
			ft_printf("ft_echo sans -n\n");
			ft_print_args_with_start_and_end(data);
			i = 0;
			while ((data->args_start + i <= data->args_end) && data->args->cmd_args[++i] && data->next_part > i)
			{
				if (i == 1)
					ft_printf("|%s|", data->args->cmd_args[data->args_start + i]);
				else if (i > 1)
					ft_printf("| %s|", data->args->cmd_args[data->args_start + i]);
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

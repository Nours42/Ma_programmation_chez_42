/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:19:39 by jmetezea          #+#    #+#             */
/*   Updated: 2023/08/11 08:43:52 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
	ft_printf("data->args_end[0] : %d\n", data->args_end[0]);
	while (data->args_end[i])
	{
		ft_printf("d->args->cmd_args[%d] : |%s| \n", i, data->args->cmd_args[i]);
		i++;
	}
}

void	msg_error(char *err)
{
	perror(err);
	exit(1);
}

void	print_var(t_data *data)
{
	int	i;

	i = -1;
	ft_printf("data->var (t_var)\n");
	ft_printf("quote_type : %d\n", data->var->quote_type);
	ft_printf("str = %s\n", data->var->str);
	ft_printf("word = %s\n", data->var->word);
	while (data->var->commands[++i])
		ft_printf("commands[%d] : %s\n", i, data->var->commands[i]);
	ft_printf("num_words : %d\n", (int)data->var->num_words);
	ft_printf("i : %d\n", (int)data->var->i);
	if (data->args->cmd_args)
	{
		ft_printf("data->var->cmd_args (t_args)\n");
		ft_print_args(data);
	}
}

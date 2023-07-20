/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <kaly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:50:42 by sdestann          #+#    #+#             */
/*   Updated: 2023/07/18 17:20:56 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_redirect(t_data *data, char **envp)
{
	int		i;

	i = -1;
	while (data->args->cmd_args[++i])
	{
		if (ft_strcmp("<", data->args->cmd_args[i]) == 0)
			redirect_simple_left(data, envp);
		else if (ft_strcmp("<<", data->args->cmd_args[i]) == 0)
			redirect_dobble_left(data, envp);
		else if (ft_strcmp(">>", data->args->cmd_args[i]) == 0)
			redirect_dobble_right(data, envp, i);
		else if (ft_strcmp(">", data->args->cmd_args[i]) == 0)
		{
			redirect_simple_right(data, envp, i);
			i = -1;
		}
		else if (ft_strcmp("|", data->args->cmd_args[i]) == 0)
			ft_pipe(data, envp);
		else if (ft_strcmp("$?", data->args->cmd_args[i]) == 0)
			ft_dolls_and(data, envp);
		else if (ft_strcmp("&&", data->args->cmd_args[i]) == 0)
			dobble_and(data, envp);
	}
}

/*int	check_redirect(t_data *data)
{
	int		i;

	i = 0;
	while (data->args->cmd_args[i + 1])
	{
		if (data->args->cmd_args[i][0] == '>' && data->args->cmd_args[i][1] == '<')
			return (syntax_error(data, i));
		else if (data->args->cmd_args[i][0] == '<' && data->args->cmd_args[i][1] == '>')
			return (syntax_error(data, i));
		else if ((data->args->cmd_args[i][0] == '>'
			&& data->args->cmd_args[i][1] == '>')
			|| (data->args->cmd_args[i][0] == '<' && data->args->cmd_args[i][1] == '<'))
		{
			if (!data->args->cmd_args[i + 1])
				return (syntax_error(data, i));
			else if ((data->args->cmd_args[i][2] == '<'
				|| data->args->cmd_args[i][2] == '>'
				|| data->args->cmd_args[i][2] == '|'
				|| data->args->cmd_args[i][2] == '&'))
				return (syntax_error(data, i));
			data->redirected = i;
		}
		i++;
	}
	if (data->args->cmd_args[i][0] == '>' || data->args->cmd_args[i][0] == '<')
		return (syntax_error(data, i));
	return (0);
}

int	syntax_error(t_data *data, int i)
{
	data->next_pipe = i;
	ft_putstr_fd("bash: syntax error near redirection token \n", 2);
	return (1);
}*/
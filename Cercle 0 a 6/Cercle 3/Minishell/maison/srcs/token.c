/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:50:42 by sdestann          #+#    #+#             */
/*   Updated: 2023/07/11 13:47:23 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_redirect(t_data *data)
{
	int		i;

	i = 0;
	while (data->args->cmd_args[i + 1])
	{
		if (data->args->cmd_args[i][0] == '>' && data->args->cmd_args[i][1] == '<')
			return (syntax_error(0));
		else if (data->args->cmd_args[i][0] == '<' && data->args->cmd_args[i][1] == '>')
			return (syntax_error(0));
		else if ((data->args->cmd_args[i][0] == '>'
			&& data->args->cmd_args[i][1] == '>')
			|| (data->args->cmd_args[i][0] == '<' && data->args->cmd_args[i][1] == '<'))
		{
			data->redirected = i;
			if (!data->args->cmd_args[i + 1])
				return (syntax_error(0));
			else if ((data->args->cmd_args[i][2] == '<'
				|| data->args->cmd_args[i][2] == '>'
				|| data->args->cmd_args[i][2] == '|'
				|| data->args->cmd_args[i][2] == '&'))
				return (syntax_error(0));
		}
		i++;
	}
	if (data->args->cmd_args[i][0] == '>' || data->args->cmd_args[i][0] == '<')
		return (syntax_error(0));
	return (0);
}

int	syntax_error(int i)
{
	(void)i;
	ft_putstr_fd("bash: syntax error near redirection token \n", 2);
	return (1);
}

int	ft_token(t_data *data)
{
	if (check_redirect(data))
		return (1);
	else
		return (0);
}

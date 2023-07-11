/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:50:42 by sdestann          #+#    #+#             */
/*   Updated: 2023/07/11 13:42:26 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ptd is for parse token and dollar

#include "../includes/minishell.h"

void	tokening(t_data *data)
{
	while (data->var->i < ft_strlen(data->var->str))
	{
		if (data->var->brk)
			break ;
		else if ((data->var->str[data->var->i] == '\''
				|| data->var->str[data->var->i] == '"')
			&& (data->var->str[data->var->i - 1] == ' '))
		{
			data->var->quote = ft_strchr(data->var->str + data->var->i + 1,
					data->var->str[data->var->i]);
			if (data->var->quote != NULL)
				ft_quote(data);
		}
			ft_space(data);
		data->var->i++;
	}
}

int	find_dollar(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '$' && (s[i] || s[i + 1] != '$'))
			return (i);
		i++;
	}
	return (-1);
}

void	find_and_replace(t_data *data, int i, int index_of_dollar)
{
	char		*temp;
	char		*temp2;
	char		*valeur_origine_args;
	t_envp		*copy;
	int			j;

	j = -1;
	valeur_origine_args = ft_strdup(data->args->cmd_args[i]);
	temp = ft_strndup(data->args->cmd_args[i], index_of_dollar + 1);
	temp2 = malloc(0);
	if (index_of_dollar > 0)
	{
		temp2 = (char *)malloc(sizeof(char) * index_of_dollar + 1);
		while (++j < index_of_dollar)
			temp2[j] = data->args->cmd_args[i][j];
	}
	copy = data->envp;
	while (copy)
	{
		if (ft_strncmp(temp, copy->str, ft_strlen(temp)) == 0)
			if (copy->str[ft_strlen(temp)] == '=')
				data->args->cmd_args[i] = ft_strjoin(temp2, ft_strndup(copy->str,
							ft_strlen(temp) + 1));
		copy = copy->next;
	}
	if (ft_strncmp(data->args->cmd_args[i], valeur_origine_args,
			ft_strlen(valeur_origine_args) - 1) == 0)
		data->args->cmd_args[i] = temp2;
}

void	give_me_the_money(t_data *data)
{
	int	i;
	int	index_of_dollar;

	i = -1;
	while (data->args->cmd_args[++i])
	{
		index_of_dollar = find_dollar(data->args->cmd_args[i]);
		if (index_of_dollar >= 0)
			find_and_replace(data, i, index_of_dollar);
	}
}

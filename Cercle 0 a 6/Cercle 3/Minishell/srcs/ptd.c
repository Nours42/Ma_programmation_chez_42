/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:50:42 by sdestann          #+#    #+#             */
/*   Updated: 2023/08/09 13:10:48 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ptd is for parse token and dollar

#include "../includes/minishell.h"

int	find_dollar(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '$')
			if (s[i + 1] != '$' || s[i + 1] != 63)
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
	if (index_of_dollar >= 0)
	{
		temp2 = (char *)malloc(sizeof(char) * index_of_dollar + 1);
		temp2 = NULL;
		while (++j < index_of_dollar)
			temp2[j] = data->args->cmd_args[i][j];
	}
	copy = data->envp;
	j = ft_strlen(temp);
	while (copy)
	{
		if (ft_strncmp(temp, copy->str, j) == 0)
		{
			if (copy->str[j] == '=')
			{
				data->args->cmd_args[i] = ft_strjoin(temp2,
						ft_strndup(copy->str, j + 1));
				break ;
			}
		}
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

	i = data->args_start;
	while (i <= data->args_end[0])
	{
		index_of_dollar = find_dollar(data->args->cmd_args[i]);
		if (index_of_dollar >= 0)
			if (ft_strcmp("$?", data->args->cmd_args[i]) != 0)
				find_and_replace(data, i, index_of_dollar);
		index_of_dollar = 0;
		i++;
	}
}

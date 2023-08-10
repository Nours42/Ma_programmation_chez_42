/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:50:42 by sdestann          #+#    #+#             */
/*   Updated: 2023/08/10 12:12:27 by sdestann         ###   ########.fr       */
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
	char		*temp3;
	char		*valeur_origine_args;
	t_envp		*copy;
	int			j;

	j = -1;

	// la copie de l'oirginal

	valeur_origine_args = ft_strdup(data->args->cmd_args[i]);

	// le avant $:

	temp2 = (char *)malloc(sizeof(char) * index_of_dollar + 1);
	while (++j < index_of_dollar)
		temp2[j] = data->args->cmd_args[i][j];
	temp2[j] = '\0';
	
	// le après $ a découper au premier espace
	if (data->args->cmd_args[i][index_of_dollar + 1] == 32)
		temp = NULL;
	else
		temp = ft_strndup(data->args->cmd_args[i], index_of_dollar + 1);
	
	// je stocke le reste de la phrase a partir du premier espace :

	j = ft_find_char(temp, 0, 32);
	if (j == 0)
		temp3 = NULL;
	else
	{
		temp3 = ft_strndup(temp, j);
		temp[j] = '\0';
	}
	copy = data->envp;
	j = ft_strlen(temp);
	ft_printf("temp ~~~%s~~~\n", temp);
	ft_printf("temp2 ~~~%s~~~\n", temp2);
	ft_printf("temp3 ~~~%s~~~\n", temp3);
	while (copy)
	{
		if ((ft_strncmp(temp, copy->str, j) == 0) && (copy->str[j] == '='))
		{
			free(temp);
			free(data->args->cmd_args[i]);
			temp = ft_strndup(copy->str, j + 1);
			if (index_of_dollar != 0)
			{
				if(temp && temp2)
				{
				// ft_printf("data->args->cmd_args[i] ~~~%s~~~\n", data->args->cmd_args[i]);
				// ft_printf("size ~~~%d~~~\n", (int)ft_strlen(data->args->cmd_args[i]));
					data->args->cmd_args[i] = ft_strjoin(temp2, temp);
					free(temp);
					temp = ft_strdup(data->args->cmd_args[i]);
					free(data->args->cmd_args[i]);
				}
				// ft_printf("data->args->cmd_args[i] ~~~%s~~~\n", data->args->cmd_args[i]);
				// ft_printf("size ~~~%d~~~\n", (int)ft_strlen(data->args->cmd_args[i]));
				data->args->cmd_args[i] = ft_strjoin(temp, temp3);
				// ft_printf("data->args->cmd_args[i] ~~~%s~~~\n", data->args->cmd_args[i]);
				// ft_printf("size ~~~%d~~~\n", (int)ft_strlen(data->args->cmd_args[i]));
			}
			else
				data->args->cmd_args[i] = ft_strjoin(temp, temp3);
			break ;
		}
		copy = copy->next;
	}
	if (ft_strncmp(data->args->cmd_args[i], valeur_origine_args,
			ft_strlen(valeur_origine_args) - 1) == 0)
		data->args->cmd_args[i] = ft_strjoin(temp2, temp3);
	free(valeur_origine_args);
	free(temp);
	free(temp2);
	if (temp3 != NULL)
		free(temp3);
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

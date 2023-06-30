/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:19:39 by jmetezea          #+#    #+#             */
/*   Updated: 2023/06/30 09:38:10 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_add_new_arg_env(t_data *data)
{
	t_envp	*copy;
	t_envp	*new;

	new = (t_envp *)malloc(sizeof(t_envp));
	new->str = data->cmd_args[1];
	new->next = NULL;
	copy = data->env;
	while (copy->next)
		copy = copy->next;
	copy->next = new;
}

char	*ft_before_and_equal(char *s)
{
	int		index;
	char	*before;

	index = 0;
	before = (char *)malloc(sizeof(char) * ft_strlen(s));
	while (s[index - 1] != '=')
	{
		before[index] = s[index];
		index++;
	}
	before[index] = '\0';
	return (before);
}

void	ft_export (t_data *data)
{
	char	*before;
	t_envp	*copy;

	copy = data->env;
	data->str_temp = ft_strchr(data->cmd_args[1], '=');
	if (data->str_temp != NULL)
	{
		before = ft_before_and_equal(data->cmd_args[1]);
		while (copy)
		{
			if (ft_strcmp(copy->str, before) == 0
				&& ft_isalnum(copy->str[ft_strlen(before) + 1]))
				{
					data->str_to_unset = data->cmd_args[1];
					ft_unset(data);
				}
			copy = copy->next;
		}
		ft_add_new_arg_env(data);
	}
	/*if (before != NULL)
		free (before);*/
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:19:39 by jmetezea          #+#    #+#             */
/*   Updated: 2023/08/11 08:49:08 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_add_new_arg_envp(t_data *data, char *args)
{
	t_envp	*copy;
	t_envp	*new;

	new = (t_envp *)malloc(sizeof(t_envp));
	new->str = args;
	new->next = NULL;
	copy = data->envp;
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
	while (s[index] != '=')
	{
		before[index] = s[index];
		index++;
	}
	before[index] = '\0';
	return (before);
}

void	ft_export(t_data *data, char *args)
{
	char	*before;
	char	*dup;
	t_envp	*copy;

	copy = data->envp;
	dup = ft_strchr(args, '=');
	if (data->end != 1)
		return ;
	if (dup != NULL)
	{
		before = ft_before_and_equal(args);
		while (copy)
		{
			if (ft_strncmp(copy->str, before, (int)ft_strlen(before)) == 0)
			{
				ft_unset(data, before);
				break ;
			}
			copy = copy->next;
		}
		ft_add_new_arg_envp(data, args);
		free(before);
	}
	else
		export_error(args);
}

void	export_error(char *args)
{
	ft_putstr_fd("bash: export: '", 2);
	ft_putstr_fd(args, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	free(args);
}

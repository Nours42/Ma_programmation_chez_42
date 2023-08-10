/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:45:29 by jmetezea          #+#    #+#             */
/*   Updated: 2023/08/10 13:08:30 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*delete_last_char(char *str)
{
	int		i;
	char	*new_str;

	new_str = malloc(sizeof(char) * ft_strlen(str));
	i = 0;
	while (str[i] != '\n')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = 0;
	free(str);
	return (new_str);
}

char	*find_path(char *s, t_envp *envp)
{
	t_envp	*find_pa;

	find_pa = envp;
	while (ft_strncmp(s, find_pa->str, ft_strlen(s)) != 0)
	{
		if (find_pa->next)
			find_pa = find_pa->next;
		else
			return("");
	}
	return (find_pa->str + (ft_strlen(s) + 1));
}

void	add_str_endlst(t_envp *envp, char *str)
{
	t_envp	*new;

	new = malloc(sizeof(*new));
	if (!envp || !new)
		return ;
	new->next = NULL;
	if (envp->str == NULL)
	{
		envp->str = ft_strdup(str);
		free(new);
	}
	else
	{
		new->str = ft_strdup(str);
		while (envp->next != NULL)
			envp = envp->next;
		envp->next = new;
	}
	// free(new->str);
}

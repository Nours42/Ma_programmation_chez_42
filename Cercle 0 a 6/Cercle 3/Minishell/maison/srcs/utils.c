/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:45:29 by jmetezea          #+#    #+#             */
/*   Updated: 2023/07/11 13:42:23 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_cmp_paths(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
	{
		i++;
	}
	return (i);
}

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
		find_pa = find_pa->next;
	return (find_pa->str + (ft_strlen(s) + 1));
}

void	add_str_endlst(t_envp *envp, char *str)
{
	t_envp	*new;

	new = malloc(sizeof(*new));
	if (!envp || !new)
		return ;
	new->str = ft_strdup(str);
	new->next = NULL;
	if (envp->str == NULL)
		envp->str = new->str;
	else
	{
		while (envp->next != NULL)
			envp = envp->next;
		envp->next = new;
	}
}

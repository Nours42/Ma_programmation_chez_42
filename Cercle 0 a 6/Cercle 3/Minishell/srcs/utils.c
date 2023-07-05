/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:45:29 by jmetezea          #+#    #+#             */
/*   Updated: 2023/07/05 10:31:18 by sdestann         ###   ########.fr       */
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

char	*find_path(char *s, t_envp *env)
{
	t_envp	*find_pa;

	find_pa = env;
	while (ft_strncmp(s, find_pa->str, ft_strlen(s)) != 0)
		find_pa = find_pa->next;
	return (find_pa->str + (ft_strlen(s) + 1));
}

void	add_str_endlst(t_envp *env, char *str)
{
	t_envp	*new;

	new = malloc(sizeof(*new));
	if (!env || !new)
		return ;
	new->str = ft_strdup(str);
	new->next = NULL;
	if (env->str == NULL)
		env->str = new->str;
	else
	{
		while(env->next != NULL)
			env = env->next;
		env->next = new;
	}
}

void	init_env(t_data *data, char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
	{
		add_str_endlst(data->env, envp[i]);
		//ft_printf("---------------%s\n", envp[i]);
	}
//	ft_show_env(data);
}

void	init_minishell(t_data *data, char **envp)
{
	data->env = malloc(sizeof(t_envp));
	data->env->next = NULL;
	data->env->str = NULL;
	init_env(data, envp);
	data->cmd_paths = ft_split(find_path("PATH", data->env), ':');
	data->str_temp = NULL;
	data->str_temp2 = NULL;
}

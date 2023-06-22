/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:45:29 by jmetezea          #+#    #+#             */
/*   Updated: 2023/06/22 09:19:15 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char    *jenlevedernierchar(char *str)
{
        int     i;
	char	*new_str;

	new_str = malloc(sizeof(char) * ft_strlen(str));
        i = 0;
        while (str[i] != '\n')
	{
		new_str[i] = str[i];
                i++;
	}
	new_str[i] = 0;
	printf("len de str %ld\n", ft_strlen(str));
	printf("len de new_str %ld\n", ft_strlen(new_str));
	free(str);
        return (new_str);
}

char    *find_path(char *s, char **envp)
{
        int     i;

        i = 0;
        while (ft_strncmp(s, envp[i], ft_strlen(s)) != 0)
                i++;
        return (envp[i] + (ft_strlen(s) + 1));
}

void	init_minishell(t_data *data, char **envp)
{
	data->cmd_paths = ft_split(find_path("PATH", envp), ':');
	data->str_temp = NULL;
	data->str_temp2 = NULL;
}

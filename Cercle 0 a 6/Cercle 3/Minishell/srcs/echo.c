/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:19:39 by jmetezea          #+#    #+#             */
/*   Updated: 2023/06/19 16:45:18 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    ft_echo(t_data *data)
{
        if (data->cmd_args[1] != NULL)
        {
                if (ft_strcmp("-n", data->cmd_args[1]) == 0 && data->cmd_args[2] != NULL)
                        ft_printf("%s", data->cmd_args[2]);
                else if (ft_strcmp("-n", data->cmd_args[1]) == 0)
                        return ;
                else
                        ft_printf("%s\n", data->cmd_args[1]);
        }
        else
                ft_printf("\n");
}

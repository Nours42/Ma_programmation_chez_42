/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:49:01 by nours42           #+#    #+#             */
/*   Updated: 2023/07/11 14:18:25 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_split_redirection(t_data *data)
{
	// split du cmd_args en plusieurs bouts
	// data->redirected donne l'argument auquel split.
	int		i;
	int		j;
	char	**args_backup;
	char	**args_split_zero;
	char	**args_split_one;
	t_data	*dup;

	i = -1;
	j = 0;
	dup = data;
	args_backup = (char**)malloc(sizeof(char*));
	args_split_zero = (char**)malloc(sizeof(char*));
	args_split_one = (char**)malloc(sizeof(char*));
	args_backup = data->args->cmd_args;
	while (++i < data->redirected)
		args_split_zero[i] = args_backup[i];
	i++;
	while (args_backup[i + j])
	{
		args_split_one[j] = args_backup[i + j];
		j++;
	}
	dup->args->cmd_args = args_split_zero;
	dup->args = dup->args->next;
	dup->args = (t_args *)malloc(sizeof(t_args));
	dup->args->cmd_args = args_split_one;
	data->redirected = 1;
}

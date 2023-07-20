/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <kaly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:49:01 by nours42           #+#    #+#             */
/*   Updated: 2023/07/18 16:30:51 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	redirect_simple_left(t_data *data, char **envp)
{
	data->piped = 1;
	if(!envp)
		return;
	ft_printf("faut crerr la fonction < \n");
}

void	redirect_dobble_left(t_data *data, char **envp)
{
	if(!envp)
		return;
	data->piped = 1;
	ft_printf("faut crerr la fonction << \n");
}

void	redirect_simple_right(t_data *data, char **envp, int i)
{
	int	fd;
	int stdout_fd; 

	fd = open(data->args->cmd_args[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_printf("le fichier : %s a ete cree\n", data->args->cmd_args[i + 1]);
	stdout_fd = dup(STDOUT_FILENO);
    dup2(fd, STDOUT_FILENO);
	data->next_pipe = i;
	if (find_builtin(data, envp) == 0)
        execute_command(data, envp);
	data->args->cmd_args = data->args->cmd_args + i + 1;
    dup2(stdout_fd, STDOUT_FILENO);
    close(stdout_fd);
	close(fd);
	data->piped = 1;
}

void	redirect_dobble_right(t_data *data, char **envp, int i)
{
	int	fd;
	int stdout_fd; 

	fd = open(data->args->cmd_args[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	ft_printf("le fichier : %s a ete cree\n", data->args->cmd_args[i + 1]);
	stdout_fd = dup(STDOUT_FILENO);
    dup2(fd, STDOUT_FILENO);
	data->next_pipe = i;
	if (find_builtin(data, envp) == 0)
        execute_command(data, envp);
	//data->args->cmd_args = data->args->cmd_args + i + 1;
    dup2(stdout_fd, STDOUT_FILENO);
    close(stdout_fd);
	close(fd);
	data->piped = 1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <kaly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:58:10 by sdestann          #+#    #+#             */
/*   Updated: 2023/08/02 15:00:11 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	how_many_pipe(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (data->args->cmd_args[++i])
	{
		if (ft_strcmp("|", data->args->cmd_args[i]) == 0)
		{
			data->args_end[j++] = i - 1;
			data->pipe->nbr_of_pipe++;
		}
	}
	data->args_end[j] = i - 1;
	data->args_max = data->args_end[j];
	// ft_printf("args end end %d : %d\n", j, data->args_end[j]);
	if (data->pipe->nbr_of_pipe > 0)
		data->pipe->pipe = (int *)malloc(sizeof(int) * data->pipe->nbr_of_pipe);
}

void	execute_pipes(t_data *data, char **envp)
{
	int		fd[2];

	if (ft_strcmp("", data->original_prompt) == 0)
		shell_loop(data, envp);
	if (ft_strcmp("exit", data->original_prompt) == 0)
		ft_exit(data);
	else if (ft_strcmp("export", data->args->cmd_args[data->args_start]) == 0)
		ft_export(data, data->args->cmd_args[data->args_start + 1]);
	else if (ft_strcmp("unset", data->args->cmd_args[data->args_start]) == 0)
		ft_unset(data, data->args->cmd_args[data->args_start + 1]);
	else
	{
		if (pipe(fd) == -1)
			return ;
		data->pid = fork();
		if (data->pid == -1)
			return ;
		if (!data->pid)
		{
			
			close(fd[0]);
			check_redirect(data);
			if (data->redirected != 2)
				dup2(fd[1], STDOUT_FILENO);
			execute_cmd(data, envp);
			close(fd[1]);
		}
		else
		{
			close(fd[1]);
			waitpid(data->pid, NULL, 0);
			dup2(fd[0], STDIN_FILENO);
			ft_printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			print_all(data);
			free_and_clear_var(data);
			close(fd[0]);
			ft_printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		}
	}
}

// void	redirect_out(t_data *data)
// {
// 	if (!file_out || !type_out)
// 		return ;
// 	while (data->file_out[i])
// 	{
// 		if (ft_strcmp(">>", data->args->cmd_args[i]) == 0)
// 		{
// 			redirect_dobble_right(data, envp, i);
// 			fd_in open(file[i], O_READONLY);
// 			dup2(fd_in, STDIN_FILENO);
// 		}
// 		else if (ft_strcmp(">", data->args->cmd_args[i]) == 0)
// 			{
// 			redirect_simple_right(data, envp, i);
// 			fd_in = ft_heredoc(file_in[i])
// 			dup2(fd_in, STDIN_FILENO);
// 		}
// 		i++;
// 	}
// }
// //redirect verifie s'il y a une entree ou sortie et de quoi elle est compose
// //apres l'open du redirect je fais mon dup2 

// void	redirect_in(t_data *data)
// {
// 	if (!file_in || !type_in)
// 		return ;
// 	while (data->file_in[i])
// 	{
// 		if (ft_strcmp("<", data->args->cmd_args[i]) == 0)
// 		{
// 			redirect_simple_left(data, envp, i);
// 			fd_in open(file[i], O_READONLY);
// 			dup2(fd_in, STDIN_FILENO);
// 		}
// 		else if (ft_strcmp("<<", data->args->cmd_args[i]) == 0)
// 		{
// 			redirect_dobble_left(data, envp, i);
// 			fd_in = ft_heredoc(file_in[i])
// 			dup2(fd_in, STDIN_FILENO);
// 		}
// 		i++;
// 	}
// }

void	sub_dup2(int zero, int first)
{
	dup2(zero, 0);
	dup2(first, 1);
}

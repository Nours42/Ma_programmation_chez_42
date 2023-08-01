/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:49:01 by nours42           #+#    #+#             */
/*   Updated: 2023/08/01 16:06:24 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	redirect_simple_left(t_data *data, int i)
{
	int		fd;

	fd = open(data->args->cmd_args[i + 1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(data->args->cmd_args[i + 1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return ;
	}
	dup2(data->pipe->infile, STDIN_FILENO);
	data->redirected = 1;
}

void	redirect_dobble_left(t_data *data, int i)
{
	int		fd;
	char	*tmp;

	fd = open("make.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	tmp = ft_get_next_line(0);
	if (!tmp)
		return ;
	while (strncmp(data->args->cmd_args[i + 1], tmp,
			ft_strlen(data->args->cmd_args[i + 1]))
		|| (ft_strlen(tmp) -1) > ft_strlen(data->args->cmd_args[i + 1]))
	{
		ft_putstr_fd(tmp, fd);
		free(tmp);
		tmp = ft_get_next_line(0);
	}
	free(tmp);
	close(fd);
	fd = open("make.tmp", O_RDONLY);
	data->redirected = 49;
	data->fd_redirect_out = fd;
	data->fd_redirect_in = data->pipe->infile;
	data->next_part = i;
	//data->fd_redirect_in = 1;
	dup2(fd, STDIN_FILENO);
	close(fd);
	unlink("make.tmp");
}

void	redirect_simple_right(t_data *data, int i)
{
	int	fd;

	if (data->args->cmd_args[i + 1] == NULL)
		msg_error("bash: erreur de syntaxeeeeeeeee\n");
	if (data->redirected != 1)
		data->next_part = i;
	else
	{
		unlink(data->args->cmd_args[i - 1]);
		fd = open(data->args->cmd_args[i - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		close(fd);
	}
	fd = open(data->args->cmd_args[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_printf("le fichier : %s a ete creeeeee\n", data->args->cmd_args[i + 1]);
	dup2(fd, STDOUT_FILENO);
	data->redirected = 1;
}

void	redirect_dobble_right(t_data *data, int i)
{
	int	fd;

	if (data->args->cmd_args[i + 1] == NULL)
		msg_error("bash: erreur de syntaxeeee\n");
	if (data->redirected != 1)
		data->next_part = i;
	else
	{
		ft_printf("data->args->cmd_args[i - 2] : %s\n", data->args->cmd_args[i - 2]);
		ft_printf("data->args->cmd_args[i - 3] : %s\n", data->args->cmd_args[i - 3]);
		//if (ft_strncmp(">>", data->args->cmd_args[i - 2], 2) != 0)
		{
			unlink(data->args->cmd_args[i - 1]);
			fd = open(data->args->cmd_args[i - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
			close(fd);
		}
	}
	fd = open(data->args->cmd_args[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	ft_printf("le fichier : %s a ete cree\n", data->args->cmd_args[i + 1]);
	dup2(fd, STDOUT_FILENO);
	data->redirected = 1;
}

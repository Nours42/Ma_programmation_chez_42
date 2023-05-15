/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:32:47 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/12 11:51:23 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	args_in(char *arg, t_data *data)
{
	if (arg && !ft_strncmp("here_doc", arg, 9))
	{
		data->is_heredoc = 1;
		return (6);
	}
	else
	{
		data->is_heredoc = 0;
		return (5);
	}
}

static void	get_infile(char **argv, t_data *data)
{
	if (ft_strncmp("here_doc", argv[1], 8) == 0)
		here_doc(argv[2], data);
	else
	{
		data->infile = open(argv[1], O_RDONLY);
		if (data->infile == -1)
			msg_error(argv[1]);
	}
}

static void	get_outfile(char *argv, t_data *data)
{
	if (data->is_heredoc)
		data->outfile = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		data->outfile = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->outfile == -1)
		msg_error(argv);
}

static void	open_files(int argc, char **argv, char **envp, t_data *data)
{
	get_infile(argv, data);
	get_outfile(argv[argc - 1], data);
	data->cmd_nbrs = argc - 3 - data->is_heredoc;
	data->pipe_nbrs = 2 * (data->cmd_nbrs - 1);
	data->pipe = (int *)malloc(sizeof(int) * data->pipe_nbrs);
	if (!data->pipe)
		msg_error("Error in malloc pipe process");
	data->env_paths = find_path(envp);
	data->cmd_paths = ft_split(data->env_paths, ':');
	if (!data->cmd_paths)
		pipe_free(data);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		status;

	status = 0;
	if (argc < args_in(argv[1], &data))
		return (msg_error("Usage : ./pipex file1 cmd1 cmd2 file2"), 0);
	open_files(argc, argv, envp, &data);
	creat_pipes(&data);
	data.idx = -1;
	while (++(data.idx) < data.cmd_nbrs)
		child(data, argv, envp);
	close_pipes(&data);
	waitpid(-1, &status, 0);
	status = WEXITSTATUS (status);
	if (status > 0)
		exit(status);
	parent_free(&data);
	return (0);
}

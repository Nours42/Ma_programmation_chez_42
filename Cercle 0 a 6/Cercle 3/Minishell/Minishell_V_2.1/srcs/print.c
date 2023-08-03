/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <kaly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:19:39 by jmetezea          #+#    #+#             */
/*   Updated: 2023/08/02 14:47:42 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_show_envp(t_data *data)
{
	int		i;
	t_envp	*show_envp;

	show_envp = data->envp;
	if (!show_envp)
		return ;
	i = 1;
	while (show_envp != NULL)
	{
		printf("nb %d : %s\n", i, show_envp->str);
		show_envp = show_envp->next;
		i++;
	}
}

void	ft_print_pipe_args(t_data *data)
{
	int	i;

	i = -1;
	ft_printf("d->pipe->infile : %d\n", data->pipe->infile);
	ft_printf("d->pipe->outfile : %d\n", data->pipe->outfile);
	if (data->pipe->pipe)
		while (data->pipe->pipe[++i])
			ft_printf("d->pipe->pipe[%d] : |%d| \n", i, data->pipe->pipe[i]);
	i = -1;
	ft_printf("d->pipe->cmd_nbrs : |%d| \n", data->pipe->cmd_nbrs);
	ft_printf("d->pipe->nbr_of_pipe : |%d| \n", data->pipe->nbr_of_pipe);
	ft_printf("d->pipe->idx : |%d| \n", data->pipe->idx);
}

void	ft_print_args(t_data *data)
{
	int	i;

	i = -1;
	while (data->args->cmd_args[++i])
		ft_printf("d->args->cmd_args[%d] : |%s| \n", i, data->args->cmd_args[i]);
}

void	ft_print_args_with_start_and_end(t_data *data)
{
	int	i;

	i = data->args_start;
	ft_printf("data->args_start : %d\n", data->args_start);
	ft_printf("data->args_end[0] : %d\n", data->args_end[0]);
	while (data->args_end[i])
	{
		ft_printf("d->args->cmd_args[%d] : |%s| \n", i, data->args->cmd_args[i]);
		i++;
	}
}

void	ft_echo(t_data *d)
{
	int	i;

	if (d->args->cmd_args[d->args_start + 1] != NULL
		&& ft_strcmp("<", d->args->cmd_args[d->args_start + 1]) != 0)
	{
		if (ft_strcmp("-n", d->args->cmd_args[d->args_start + 1]) == 0
			&& d->args->cmd_args[d->args_start + 2] != NULL)
		{
			i = 1;
			while ((d->args_start + i <= d->args_end[0])
				&& d->args->cmd_args[++i] && d->next_part > i)
				ft_printf("%s", d->args->cmd_args[d->args_start + i]);
		}
		else if (ft_strcmp("-n", d->args->cmd_args[d->args_start +1]) == 0)
			return ;
		else
		{
			i = 0;
			while ((d->args_start + i <= d->args_end[0]) && d->args->cmd_args[i]
				&& d->next_part > i)
			{
				i++;
				if (i == 1)
					ft_printf("%s", d->args->cmd_args[d->args_start + i]);
				else if (i > 1 && d->args_start + i <= d->args_end[0])
				{
					ft_printf(" %s", d->args->cmd_args[d->args_start + i]);
				}
			}
			ft_printf("\n");
		}
	}
	else
		ft_printf("\n");
}

void	msg_error(char *err)
{
	perror(err);
	exit (1);
}

void	print_intstar(int *i)
{
	int	j;

	j = 0;
	while (i[j])
	{
		ft_printf("valeur %d du tableau de int : %d\n", j, i[j]);
		j++;
	}
}

void	print_all(t_data *data)
{
	int	i;

	i = -1;
	if (data->var)
	{
		ft_printf("data->var (t_var)\n");
		ft_printf("quote_type : %d\n", data->var->quote_type);
		ft_printf("str = %s\n", data->var->str);
		ft_printf("word = %s\n", data->var->word);
		while (data->var->commands[++i])
			ft_printf("commands[%d] : %s\n", i, data->var->commands[i]);
		ft_printf("num_words : %d\n", (int)data->var->num_words);
		ft_printf("i : %d\n", (int)data->var->i);
		ft_printf("brk : %d\n",	data->var->brk);
		if (data->args->cmd_args)
		{
			ft_printf("data->var->cmd_args (t_args)\n");
			ft_print_args(data);
		}
	}
	if (data->pipe)
	{
		ft_printf("data->pipe (t_pipe)\n");
		ft_print_args_with_start_and_end(data);
	}
	if (data)
	{
		ft_printf("data (t_data)\n");
		ft_printf("original_prompt = %s\n", data->original_prompt);
		ft_printf("cmd_prompt = %s\n", data->cmd_prompt);
		ft_printf("redirected : %d\n", data->redirected);
		ft_printf("fd_redirect_in : %d\n", data->fd_redirect_in);
		ft_printf("fd_redirect_out : %d\n", data->fd_redirect_out);
		ft_printf("next_part : %d\n", data->next_part);
		ft_printf("args_start : %d\n", data->args_start);
		i = -1;
		while (data->args_end[++i])
			ft_printf("*args_end : %d\n", data->args_end[i]);
		ft_printf("args_max : %d\n", data->args_max);
		ft_printf("end : %d\n", data->end);
		ft_printf("boucle : %d\n", data->boucle);
	}
}
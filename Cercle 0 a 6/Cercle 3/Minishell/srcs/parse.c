/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:50:42 by sdestann          #+#    #+#             */
/*   Updated: 2023/07/27 17:49:53 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	parse(t_data *data, char **envp)
{
	//int	p;

	//p = -1;
	if (!envp)
		return ;
	init_parse(data);
	//find_pipe(data);
	//data->pipe->idx = 0;
	//while (++p < data->pipe->nbr_of_pipe)
	// {
	// 	data->pipe->cmd[p] = ft_substr(data->str_temp, data->pipe->idx, data->pipe->pipe_idx[p]);
	// 	data->pipe->idx = data->pipe->pipe_idx[p];
	// }
	// if (data->pipe->pipe_idx[1] && data->pipe->pipe_idx[1] > 0)
	// 	creat_pipes(data);
	//// while ((data->pipe->idx) < data->pipe->cmd_nbrs)
	//// 	child(data, envp);
	if (data->str_temp != NULL)
		tokening(data);
	data->args->cmd_args = data->var->commands;
}

void	find_pipe(t_data *data)
{
	int	j;

	j = -1;
	data->pipe->pipe_idx[0] = 0;
	data->pipe->cmd_nbrs = ft_strnchr(data->str_temp, '|') + 1;
	if (data->pipe->cmd_nbrs > 1)
	{
		data->pipe->pipe_idx = (int *)malloc(sizeof(int) * data->pipe->cmd_nbrs + 1);
		data->pipe->pipe = (int *)malloc(sizeof(int) * data->pipe->cmd_nbrs);
	}
	data->var->i = 1;
	while (data->var->i < ft_strlen(data->str_temp) - 1)
	{
		if (data->str_temp[data->var->i - 1] == ' ' && data->str_temp[data->var->i] == '|' && data->str_temp[data->var->i + 1] == ' ')
		{	
			data->pipe->pipe_idx[++j] = data->var->i;
		}
		data->var->i++;
	}
	data->var->i = 0;
}

void	tokening(t_data *data)
{
	while (data->var->i < ft_strlen(data->str_temp))
	{
		if ((data->str_temp[data->var->i] == '\'' || data->str_temp[data->var->i] == '"'))
		{
			data->var->quote_type = data->str_temp[data->var->i];
			ft_printf("quote_type : %d\n", data->var->quote_type);
			ft_quote(data);
		}
		else
			ft_space(data);
	}
}

size_t	ft_find_char(char *s, int start, char c)
{
	size_t i;

	i = 0;
	while (s[start + i])
	{
		if (s[start + i] == c)
			return (i);
		else
			i++;
	}
	return (0);
}

void	ft_space(t_data *data)
{
	size_t	last_index;
	int		j;

	j = 0;
	data->var->word = malloc(sizeof(char) * (ft_strlen(data->str_temp) + 1));
	ft_bzero(data->var->word, ft_strlen(data->str_temp) + 1);
	while (data->str_temp[data->var->i] && data->str_temp[data->var->i] != ' ')
	{
		if (data->str_temp[data->var->i] != data->var->quote_type)
		{
			data->var->word[j] = data->str_temp[data->var->i];
			data->var->i++;
			j++;
		}
		else
		{
			data->var->i++;
			last_index = ft_find_char(data->str_temp, data->var->i, data->var->quote_type);
			data->var->str = ft_substr(data->str_temp, data->var->i, last_index);
			data->var->word = ft_strcat(data->var->word, data->var->str);
			free(data->var->str);
			data->var->str = NULL;
			data->var->i += last_index + 1;
		}
	}
	data->var->commands[(data->var->num_words)] = data->var->word;
	data->var->num_words++;
	data->var->i++;
}

void	ft_quote(t_data *data)
{
	size_t	last_index;
	int		j;

	j = 0;
	data->var->word = malloc(sizeof(char) * (ft_strlen(data->str_temp) + 1));
	ft_bzero(data->var->word, ft_strlen(data->str_temp) + 1);
	while (data->str_temp[data->var->i] && data->str_temp[data->var->i] != ' ')
	{
		if (data->str_temp[data->var->i] != data->var->quote_type)
		{
			data->var->word[j] = data->str_temp[data->var->i];
			data->var->i++;
			j++;
		}
		else
		{
			data->var->i++;
			last_index = ft_find_char(data->str_temp, data->var->i, data->var->quote_type);
			if (last_index > 0)
			{
				data->var->str = ft_substr(data->str_temp, data->var->i, last_index);
				data->var->word = ft_strcat(data->var->word, data->var->str);
				free(data->var->str);
				data->var->str = NULL;
				data->var->i += last_index + 1;
				j += last_index;
				ft_printf("data->var->i dans ft_quote : %d\n", data->var->i);
			}
			else
			{
				data->var->i--;
				data->var->word[j] = data->str_temp[data->var->i];
				data->var->i++;
				j++;
			}
		}
	}
	data->var->commands[(data->var->num_words)] = data->var->word;
	data->var->num_words++;
	data->var->i++;
}

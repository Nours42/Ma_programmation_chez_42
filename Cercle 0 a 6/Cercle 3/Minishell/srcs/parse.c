/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:50:42 by sdestann          #+#    #+#             */
/*   Updated: 2023/07/25 11:47:33 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	parse(t_data *data, char **envp)
{
	int	p;

	p = -1;
	if (!envp)
		return ;
	data->var->i = 0;
	data->var->num_words = 0;
	data->var->brk = 0;
	find_pipe(data);
	data->var->str = data->str_temp;
	data->pipe->idx = 0;
	while (++p < data->pipe->nbr_of_pipe)
	{
		data->pipe->cmd[p] = ft_substr(data->str_temp, data->pipe->idx, data->pipe->pipe_idx[p]);
		data->pipe->idx = data->pipe->pipe_idx[p];
	}
	if (data->pipe->pipe_idx[1] && data->pipe->pipe_idx[1] > 0)
		creat_pipes(data);
	// while ((data->pipe->idx) < data->pipe->cmd_nbrs)
	// 	child(data, envp);
	tokening(data);
	data->args->cmd_args = data->var->commands;
	// ft_printf("data->var->quote : %s\n", data->var->quote);
	// ft_printf("data->var->str : %s\n", data->var->str);
	// ft_printf("data->var->word : %s\n", data->var->word);
	if (data->var->quote != NULL)
		free(data->var->quote);
	//free(data->var->str);
	//free(data->var->word);
	// ft_printf("data->var->quote : %s\n", data->var->quote);
	// ft_printf("data->var->str : %s\n", data->var->str);
	// ft_printf("data->var->word : %s\n", data->var->word);
	// ft_printf("data->var->command[0] : %s\n", data->var->commands[0]);
	// ft_printf("data->var->num_words : %d\n", data->var->num_words);
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
	while (data->var->i < ft_strlen(data->str_temp))
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
	while (data->var->i < ft_strlen(data->var->str))
	{
		if (data->var->brk)
			break ;
		else if ((data->var->str[data->var->i] == '\''
				|| data->var->str[data->var->i] == '"')
			&& (data->var->str[data->var->i - 1] == ' '))
		{
			data->var->quote = ft_strchr(data->var->str + data->var->i + 1,
					data->var->str[data->var->i]);
			if (data->var->quote != NULL)
			{
				ft_quote(data);
				data->var->i++;
			}
		}
		if (data->var->str[data->var->i] != '\0')
		{
			while (data->var->str[data->var->i] == ' ')
				data->var->i++;
			ft_space(data);
		}
		data->var->i++;
	}
}

void	ft_quote(t_data *data)
{
	int	word_length;

	word_length = data->var->quote - data->var->str - data->var->i - 1;
	data->var->word = malloc(sizeof(char) * (word_length + 1));
	ft_strncpy(data->var->word, data->var->str + data->var->i + 1, word_length);
	data->var->word[word_length] = '\0';
	data->var->commands[(data->var->num_words)] = data->var->word;
	((data->var->num_words))++;
	data->var->i += (data->var->quote - data->var->str - data->var->i);
}

void	ft_space(t_data *data)
{
	int	word_length;

	if (data->var->str + data->var->i + 1)
		data->var->quote = ft_strchr(data->var->str + data->var->i + 1, ' ');
	if (data->var->quote != NULL)
	{
		word_length = data->var->quote - data->var->str - data->var->i;
		data->var->word = malloc(sizeof(char) * (word_length + 1));
		while (*(data->var->str) + data->var->i + 1 == ' ')
			data->var->i++;
		ft_strncpy(data->var->word, data->var->str + data->var->i, word_length);
		data->var->word[word_length] = '\0';
		data->var->commands[(data->var->num_words)] = data->var->word;
		((data->var->num_words))++;
		data->var->i += (data->var->quote - data->var->str - data->var->i);
	}
	else
	{
		word_length = (ft_strlen(data->var->str) - data->var->i);
		data->var->word = malloc(sizeof(char) * (word_length + 1));
		while (*(data->var->str) + data->var->i + 1 == ' ')
			data->var->i++;
		ft_strncpy(data->var->word, data->var->str + data->var->i, word_length);
		data->var->word[word_length] = '\0';
		data->var->commands[(data->var->num_words)] = data->var->word;
		((data->var->num_words))++;
		data->var->brk = 1;
	}
}

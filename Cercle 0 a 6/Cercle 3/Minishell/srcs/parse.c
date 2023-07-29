/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:50:42 by sdestann          #+#    #+#             */
/*   Updated: 2023/07/29 18:11:18 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	parse(t_data *data, char **envp)
{
	if (!envp)
		return ;
	init_parse(data);
	if (data->original_prompt != NULL)
		tokening(data);
	data->args->cmd_args = data->var->commands;
	//premiere valeur de args_end = valeur max en cas de pas de pipe
	data->args_end[0] = data->var->num_words - 1;
	//ft_printf("parse -> data->var->num_word = %d\n", data->var->num_words);
}

void	tokening(t_data *data)
{
	while (data->var->i < ft_strlen(data->original_prompt))
	{
		if ((data->original_prompt[data->var->i] == '\'' || data->original_prompt[data->var->i] == '"'))
		{
			data->var->quote_type = data->original_prompt[data->var->i];
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
	data->var->word = malloc(sizeof(char) * (ft_strlen(data->original_prompt) + 1));
	ft_bzero(data->var->word, ft_strlen(data->original_prompt) + 1);
	while (data->original_prompt[data->var->i] && data->original_prompt[data->var->i] != ' ')
	{
		if (data->original_prompt[data->var->i] != data->var->quote_type)
		{
			data->var->word[j] = data->original_prompt[data->var->i];
			data->var->i++;
			j++;
		}
		else
		{
			data->var->i++;
			last_index = ft_find_char(data->original_prompt, data->var->i, data->var->quote_type);
			data->var->str = ft_substr(data->original_prompt, data->var->i, last_index);
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
	data->var->word = malloc(sizeof(char) * (ft_strlen(data->original_prompt) + 1));
	ft_bzero(data->var->word, ft_strlen(data->original_prompt) + 1);
	while (data->original_prompt[data->var->i] && data->original_prompt[data->var->i] != ' ')
	{
		if (data->original_prompt[data->var->i] != data->var->quote_type)
		{
			data->var->word[j] = data->original_prompt[data->var->i];
			data->var->i++;
			j++;
		}
		else
		{
			data->var->i++;
			last_index = ft_find_char(data->original_prompt, data->var->i, data->var->quote_type);
			if (last_index > 0)
			{
				data->var->str = ft_substr(data->original_prompt, data->var->i, last_index);
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
				data->var->word[j] = data->original_prompt[data->var->i];
				data->var->i++;
				j++;
			}
		}
	}
	data->var->commands[(data->var->num_words)] = data->var->word;
	data->var->num_words++;
	data->var->i++;
}

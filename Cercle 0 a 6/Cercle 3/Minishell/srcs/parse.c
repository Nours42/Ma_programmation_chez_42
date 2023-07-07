/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:50:42 by sdestann          #+#    #+#             */
/*   Updated: 2023/07/07 14:55:06 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

void	tokening(t_data *data)
{
	while (data->var->i < ft_strlen(data->var->str))
	{
		if (data->var->brk)
			break ;
		else if ((data->var->str[data->var->i] == '\'' || data->var->str[data->var->i] == '"') 
			&& (data->var->str[data->var->i - 1] == ' '))
		{
			data->var->quote = ft_strchr(data->var->str + data->var->i + 1, data->var->str[data->var->i]);
			if (data->var->quote != NULL)
				ft_quote(data);
		}
		else if (data->var->str[data->var->i] == '<' || data->var->str[data->var->i] == '>'
			|| data->var->str[data->var->i] == '&')
			ft_token(data);
		else
			ft_space(data);
		data->var->i++;
	}
}

int	find_dollar(char *s)
{
	int	i;

	i = 0;

	while (s[i])
	{
		if (s[i] == '$' && (s[i] || s[i + 1] != '$'))
			return (i);
		i++;
	}
	return (-1);
}

void	find_and_replace(t_data *data, int i, int index_of_dollar)
{
	char 		*temp;
	char		*temp2;
	char		*valeur_origine_args;
	t_envp		*copy;
	int			j;

	j = -1;
	valeur_origine_args = ft_strdup(data->cmd_args[i]);
	temp = ft_strndup(data->cmd_args[i], index_of_dollar + 1);
	temp2 = malloc(0);
	if (index_of_dollar > 0)
	{
		temp2 = (char *)malloc(sizeof(char) * index_of_dollar + 1);
		while (++j < index_of_dollar)
			temp2[j] = data->cmd_args[i][j];
	}
	copy = data->envp;
	while (copy)
	{
		if (ft_strncmp(temp, copy->str, ft_strlen(temp)) == 0)
			if (copy->str[ft_strlen(temp)] == '=')
				data->cmd_args[i] = ft_strjoin(temp2, ft_strndup(copy->str, ft_strlen(temp) + 1));
		copy = copy->next;
	}
	if (ft_strncmp(data->cmd_args[i], valeur_origine_args, ft_strlen(valeur_origine_args) - 1) == 0)
		data->cmd_args[i] = temp2;
}

void	give_me_the_money(t_data *data)
{
	int	i;
	int	index_of_dollar;

	i = -1;
	while (data->cmd_args[++i])
	{
		index_of_dollar = find_dollar(data->cmd_args[i]);
		if (index_of_dollar >= 0)
			find_and_replace(data, i, index_of_dollar);
	}
}

void	parse(t_data *data)
{
	data->var = (t_command *)malloc(sizeof(t_command) + 1);
	data->var->num_words = 0;
	data->var->str = data->str_temp;
	data->var->i = 0;
	tokening(data);
	data->cmd_args = data->var->commands;
}

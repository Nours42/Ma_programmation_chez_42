/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:50:42 by sdestann          #+#    #+#             */
/*   Updated: 2023/07/05 16:38:28 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_quote(t_command *var)
{
	int	word_length;

	word_length = var->quote - var->str - var->i - 1;
	var->word = malloc(sizeof(char) * (word_length + 1));
	ft_strncpy(var->word, var->str + var->i + 1, word_length);
	var->word[word_length] = '\0';
	var->commands[(var->num_words)] = var->word;
	((var->num_words))++;
	var->i += (var->quote - var->str - var->i);
}

void	ft_space(t_command *var)
{
	int	word_length;

	var->quote = ft_strchr(var->str + var->i + 1, ' ');
	if (var->quote != NULL)
	{
		word_length = var->quote - var->str - var->i;
		var->word = malloc(sizeof(char) * (word_length + 1));
		while (*(var->str) + var->i + 1 == ' ')
			var->i++;
		ft_strncpy(var->word, var->str + var->i, word_length);
		var->word[word_length] = '\0';
		var->commands[(var->num_words)] = var->word;
		((var->num_words))++;
		var->i += (var->quote - var->str - var->i);
	}
	else
	{
		word_length = (ft_strlen(var->str) - var->i);
		var->word = malloc(sizeof(char) * (word_length + 1));
		while (*(var->str) + var->i + 1 == ' ')
			var->i++;
		ft_strncpy(var->word, var->str + var->i, word_length);
		var->word[word_length] = '\0';
		var->commands[(var->num_words)] = var->word;
		((var->num_words))++;
		var->brk = 1;
	}
}

void	tokening(t_command *var)
{
	var->i = 0;
	while (var->i < ft_strlen(var->str))
	{
		if (var->brk)
			break ;
		else if ((var->str[var->i] == '\'' || var->str[var->i] == '"') 
			&& (var->str[var->i - 1] == ' '))
		{
			var->quote = ft_strchr(var->str + var->i + 1, var->str[var->i]);
			if (var->quote != NULL)
				ft_quote(var);
		}
		else if (var->str[var->i] == '<' || var->str[var->i] == '>'
			|| var->str[var->i] == '&' || var->str[var->i] == '|')
		{
			if (var->str[var->i] == var->str[var->i + 1])
				ft_double_token(var);
			else
				ft_single_token(var);
		}
		else if (var->str[var->i] == '(')
			ft_parenthese(var);
		else
			ft_space(var);
		var->i++;
	}
}

int	find_dollar(char *s)
{
	int	i;

	i = 0;

	while (s[i])
	{
		if (s[i] == '$' && (s[i] || s[i + 1] != '$'))
		{
			ft_printf("%d\n", i);
			return (i);
		}
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
	copy = data->env;
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

char	**parse(char *s)
{
	t_command	*var;

	var = (t_command *)malloc(sizeof(t_command) + 1);
	var->num_words = 0;
	var->str = s;
	tokening(var);
	return (var->commands);
}

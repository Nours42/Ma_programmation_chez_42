/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:50:42 by sdestann          #+#    #+#             */
/*   Updated: 2023/06/22 12:11:43 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_single_token(t_command *var)
{
	ft_printf("fonction single token a faire avec %s", var->quote);
}

void	ft_double_token(t_command *var)
{
	ft_printf("fonction double token a faire avec %s", var->quote);
}

void	ft_quote(t_command *var)
{
	int	word_length;
	
	word_length = var->quote - var->str - var->i - 1;
	var->word = malloc(sizeof(char) * (word_length + 1));
	ft_strncpy(var->word, var->str + var->i, word_length);
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
		ft_strncpy(var->word, var->str + var->i, word_length);
		var->word[word_length] = '\0';
		var->commands[(var->num_words)] = var->word;
		((var->num_words))++;
		var->brk = 1;
	}
}

void	ft_parenthese(t_command *var)
{
	t_command	*lvl_up;

	var->quote = ft_strchr(var->str + var->i + 1, ')');
	if (var->quote != NULL)
	{
		lvl_up = (t_command *)malloc(sizeof(t_command) + 1);
		lvl_up->num_words = 0;
		lvl_up->str = var->quote;
		tokening(lvl_up);
	}
}

void	tokening(t_command *var)
{
	var->i = 0;
	while (var->i < ft_strlen(var->str))
	{
		if(var->brk)
			break ;
		else if (var->str[var->i] == '\'' || var->str[var->i] == '"')
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
		else if (var->str[var->i] == ' ')
			ft_space(var);
		var->i++;
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

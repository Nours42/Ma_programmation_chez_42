/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:50:42 by sdestann          #+#    #+#             */
/*   Updated: 2023/08/09 18:01:20 by sdestann         ###   ########.fr       */
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
	data->args_end[0] = data->var->num_words - 1;
}

void	tokening(t_data *d)
{
	int	i;

	i = ft_strlen(d->original_prompt) + 1;
	while (d->var->i < ft_strlen(d->original_prompt))
	{
		// ft_printf("%d\n",d->var->i);
		d->var->word = (char *)malloc(sizeof(char) * i);
		ft_bzero(d->var->word, i);
		ft_quote(d);
		if (ft_strcmp(d->var->word, "\0") != 0)
		{
			d->var->commands[(d->var->num_words)] = d->var->word;
			d->var->num_words++;
			d->var->word = NULL;
			free(d->var->word);
		}
		d->var->i++;
		d->var->quote_type = 0;
		d->var->word = NULL;
		free(d->var->word);
	}
}

size_t	ft_find_char(char *s, int start, char c)
{
	size_t	i;

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

void	ft_quote(t_data *d)
{
	size_t	last_index;
	int		j;

	j = 0;
	while (d->original_prompt[d->var->i]
		&& d->original_prompt[d->var->i] != ' ')
	{
		if ((d->original_prompt[d->var->i] != '\''
				&& d->original_prompt[d->var->i] != '"'))
		{
			d->var->word[j] = d->original_prompt[d->var->i];
			d->var->i++;
			j++;
		}
		else
		{
			d->var->quote_type = d->original_prompt[d->var->i];
			d->var->i++;
			last_index
				= ft_find_char(d->original_prompt,
					d->var->i, d->var->quote_type);
			if (last_index > 0)
			{
				d->var->str
					= ft_substr(d->original_prompt, d->var->i, last_index);
				d->var->word = ft_strcat(d->var->word, d->var->str);
				free(d->var->str);
				d->var->str = NULL;
				d->var->i += last_index + 1;
				j += last_index;
			}
			else
			{
				d->var->i--;
				d->var->word[j] = d->original_prompt[d->var->i];
				d->var->i++;
				j++;
			}
		}
	}
}

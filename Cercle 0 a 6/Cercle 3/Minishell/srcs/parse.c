/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:50:42 by sdestann          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/08/10 16:25:38 by sdestann         ###   ########.fr       */
=======
/*   Updated: 2023/08/10 13:11:10 by sdestann         ###   ########.fr       */
>>>>>>> bb6a7fbea488da8d2a8258804339c1d5318b2f78
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
<<<<<<< HEAD
=======
	
>>>>>>> bb6a7fbea488da8d2a8258804339c1d5318b2f78
	while (d->var->i < ft_strlen(d->original_prompt))
	{
		ft_quote(d);
		if (ft_strcmp(d->var->word, "\0") != 0)
		{
			d->var->commands[(d->var->num_words)] = d->var->word;
			d->var->num_words++;
			d->var->word = NULL;
			free(d->var->word);
		}
		else
		{
			d->var->word = NULL;
			free(d->var->word);
		}
		d->var->i++;
		d->var->quote_type = 0;
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
<<<<<<< HEAD
	d->var->word = ft_calloc(sizeof(char),
			(int)ft_strlen(d->original_prompt) + 1);
	while (d->original_prompt[d->var->i]
		&& d->original_prompt[d->var->i] != ' ')
=======
	d->var->word = ft_calloc(sizeof(char), (int)ft_strlen(d->original_prompt) + 1);
	while (d->original_prompt[d->var->i] && d->original_prompt[d->var->i] != ' ')
>>>>>>> bb6a7fbea488da8d2a8258804339c1d5318b2f78
	{
		if ((d->original_prompt[d->var->i] != '\'' && d->original_prompt[d->var->i] != '"'))
		{
			d->var->word[j] = d->original_prompt[d->var->i];
			d->var->i++;
			j++;
		}
		else
		{
			d->var->quote_type = d->original_prompt[d->var->i];
			d->var->i++;
<<<<<<< HEAD
			last_index = ft_find_char(d->original_prompt, d->var->i,
					d->var->quote_type);
			if (last_index > 0)
			{
				d->var->str = ft_substr(d->original_prompt,
						d->var->i, last_index);
=======
			last_index = ft_find_char(d->original_prompt, d->var->i, d->var->quote_type);
			if (last_index > 0)
			{
				d->var->str	= ft_substr(d->original_prompt, d->var->i, last_index);
>>>>>>> bb6a7fbea488da8d2a8258804339c1d5318b2f78
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

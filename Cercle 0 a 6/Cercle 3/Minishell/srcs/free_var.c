/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:44:31 by kaly              #+#    #+#             */
/*   Updated: 2023/08/08 14:43:15 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// pour info
// 
// typedef struct s_var
// {
// 	int		quote_type;
// 	char	*str;
// 	char	*word;
// 	char	*commands[100];
// 	size_t	num_words;
// 	size_t	i;
// 	int		brk;
// }				t_var;

void	free_and_clear_var(t_data *data)
{
	int	i;

	data->var->quote_type = 0;
	if (data->var->str && data->var->str != NULL)
	{
		data->var->str = NULL;
		free(data->var->str);
	}
	if (data->var->word && data->var->word != NULL)
	{
		data->var->word = NULL;
		free(data->var->word);
	}
	i = -1;
	while (++i < (int)data->var->num_words)
	{
		if (data->var->commands[i] && data->var->commands[i] != NULL)
			free(data->var->commands[i]);
	}
	data->var->num_words = 0;
	data->var->i = 0;
	free(data->var);
}

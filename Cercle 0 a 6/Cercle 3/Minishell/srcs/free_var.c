/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:44:31 by kaly              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/08/10 14:42:08 by sdestann         ###   ########.fr       */
=======
/*   Updated: 2023/08/09 15:00:25 by sdestann         ###   ########.fr       */
>>>>>>> bb6a7fbea488da8d2a8258804339c1d5318b2f78
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

// void	init_var(t_data *data)
// {
// 	int		i;

// 	i = 0;
// 	data->var = (t_var *)malloc(sizeof(t_var));
// 	while (i <= 99)
// 		data->var->commands[i++] = NULL;
// 	data->var->i = 0;
// 	data->var->num_words = 0;
// 	data->var->quote_type = 0;
// 	data->var->str = NULL;
// 	data->var->word = NULL;
// }

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
	// ft_print_args(data);
	i = -1;
	while (++i < (int)data->var->num_words)
<<<<<<< HEAD
		free(data->var->commands[i]);
=======
	{
		// ft_printf("%s\n", data->var->commands[i]);
		free(data->var->commands[i]);
	}
	// free(data->var->commands);
	// data->var->num_words = 0;
>>>>>>> bb6a7fbea488da8d2a8258804339c1d5318b2f78
	data->var->i = 0;
	free(data->var);
}

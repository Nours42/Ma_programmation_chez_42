/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:08:40 by sdestann          #+#    #+#             */
/*   Updated: 2023/07/20 11:08:43 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_readline(t_data *data)
{
	data->str_temp = readline("~>$ ");
	if (!data->str_temp)
	{
		ft_printf("game over!\nMinishell is closed.\nThat's the end of your life !\n");
		ft_free_str_temp(1, data);
		ft_free_paths(data);
		exit(EXIT_FAILURE);
	}
	add_history(data->str_temp);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_and_lvl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:50:42 by sdestann          #+#    #+#             */
/*   Updated: 2023/06/23 13:48:22 by sdestann         ###   ########.fr       */
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

void	ft_parenthese(t_command *var)
{
	t_command	*lvl_up;

	var->quote = ft_strchr(var->str + var->i + 1, ')');
	if (var->quote != NULL)
	{
		lvl_up = (t_command *)malloc(sizeof(t_command) + 1);
		lvl_up->num_words = 0;
		lvl_up->str = var->quote;
		lvl_up->lvl = var->lvl + 1;
		tokening(lvl_up);
	}
}

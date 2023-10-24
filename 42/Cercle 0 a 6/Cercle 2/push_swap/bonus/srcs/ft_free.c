/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:49:17 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/02 12:16:28 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_push_swap.h"

void	ft_free(t_lon **list_a, t_lon **list_b, char *line, char *instructions)
{
	ft_free_lon(list_a);
	ft_free_lon(list_b);
	free(line);
	free(instructions);
}

void	ft_free_lon(t_lon **lon)
{
	t_lon	*current;
	t_lon	*temp;

	current = *lon;
	while (current)
	{
		temp = current;
		current = current -> next;
		free(temp);
	}
	free(lon);
}

void	ft_free_tab_of_tab_char(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

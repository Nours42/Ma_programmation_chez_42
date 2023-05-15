/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:00:36 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/28 16:43:54 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Recherche l'index minimum dans un liste */

int	min_index(t_lon **list)
{
	t_lon	*copy;
	int		min_index;

	copy = *list;
	min_index = copy->index;
	while (copy)
	{
		if (copy->index < min_index)
			min_index = copy->index;
		copy = copy->next;
	}
	return (min_index);
}

static t_lon	*get_next_min(t_lon **list)
{
	t_lon	*head;
	t_lon	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *list;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || head->number < min->number))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	index_list(t_lon **list)
{
	t_lon	*head;
	int		index;

	index = 0;
	head = get_next_min(list);
	while (head)
	{
		head->index = index++;
		head = get_next_min(list);
	}
}

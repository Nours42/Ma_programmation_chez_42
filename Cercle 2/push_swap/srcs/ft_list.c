/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:23:32 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/26 10:01:25 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_lon	*add_number(int numb)
{
	t_lon	*new_numbers;

	new_numbers = (t_lon *)malloc(sizeof(t_lon));
	if (!new_numbers)
		return (NULL);
	new_numbers->number = numb;
	new_numbers->index = -1;
	new_numbers->next = NULL;
	return (new_numbers);
}

void	add_numb_at_begin(t_lon **lon, t_lon *new_number)
{
	if (!new_number)
		return ;
	new_number->next = *lon;
	*lon = new_number;
}

void	add_numb_at_end(t_lon **lon, t_lon *new_number)
{
	t_lon	*temp;

	if (!new_number)
		return ;
	if (*lon)
	{
		temp = get_last(*lon);
		temp->next = new_number;
	}
	else
		*lon = new_number;
}

t_lon	*get_last(t_lon *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

size_t	ft_list_size(t_lon *lon)
{
	size_t	lon_size;

	lon_size = 0;
	while (lon)
	{
		lon_size++;
		lon = lon->next;
	}
	return (lon_size);
}

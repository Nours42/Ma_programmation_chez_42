/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:02:00 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/02 12:15:53 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_push_swap.h"

void	push(t_lon **list_from, t_lon **list_dest)
{
	t_lon	*temp;

	if (ft_list_size(*list_from) == 0)
		return ;
	temp = *list_from;
	*list_from = (*list_from)->next;
	add_numb_at_begin(list_dest, temp);
}

void	swap(t_lon **list)
{
	t_lon	*temp;

	if (ft_list_size(*list) < 2)
		return ;
	temp = (*list)->next;
	(*list)->next = temp->next;
	temp->next = *list;
	*list = temp;
}

void	rotate(t_lon **list)
{
	t_lon	*head;
	t_lon	*tail;

	if (ft_list_size(*list) < 2)
		return ;
	tail = get_last(*list);
	head = *list;
	*list = (*list)->next;
	tail->next = head;
	head->next = NULL;
}

void	reverse_rotate(t_lon **list)
{
	t_lon	*prev_tail;
	t_lon	*tail;

	if (ft_list_size(*list) < 2)
		return ;
	prev_tail = *list;
	while (prev_tail->next->next)
		prev_tail = prev_tail->next;
	tail = prev_tail->next;
	prev_tail->next = NULL;
	tail->next = *list;
	*list = tail;
}

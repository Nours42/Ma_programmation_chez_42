/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:50:20 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/29 09:41:30 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_val *val, t_lon **list_a, t_lon **list_b)
{
	if ((*list_a)->index == min_index(list_a))
	{
		ra(val, list_a, list_b);
		sa(val, list_a, list_b);
		rra(val, list_a, list_b);
	}
	else if ((*list_a)->next->index == min_index(list_a))
	{
		if ((*list_a)->index < (*list_a)->next->next->index)
			sa(val, list_a, list_b);
		else
			ra(val, list_a, list_b);
	}
	else
	{
		if ((*list_a)->index < (*list_a)->next->index)
			rra(val, list_a, list_b);
		else
		{
			ra(val, list_a, list_b);
			sa(val, list_a, list_b);
		}
	}
}

static inline void	sort_four(t_val *val, t_lon **list_a, t_lon **list_b)
{
	if (get_distance_of_number(list_a, min_index(list_a)) == 1)
		ra(val, list_a, list_b);
	else if (get_distance_of_number(list_a, min_index(list_a)) == 2)
	{
		ra(val, list_a, list_b);
		ra(val, list_a, list_b);
	}
	else if (get_distance_of_number(list_a, min_index(list_a)) == 3)
		rra(val, list_a, list_b);
	if (list_is_sorted(list_a))
		return ;
	pb(val, list_a, list_b);
	sort_three(val, list_a, list_b);
	pa(val, list_b, list_a);
}

static void	sort_five(t_val *val, t_lon **list_a, t_lon **list_b)
{
	if (get_distance_of_number(list_a, min_index(list_a)) == 1)
		ra(val, list_a, list_b);
	else if (get_distance_of_number(list_a, min_index(list_a)) == 2)
	{
		ra(val, list_a, list_b);
		ra(val, list_a, list_b);
	}
	else if (get_distance_of_number(list_a, min_index(list_a)) == 3)
	{
		rra(val, list_a, list_b);
		rra(val, list_a, list_b);
	}
	else if (get_distance_of_number(list_a, min_index(list_a)) == 4)
		rra(val, list_a, list_b);
	if (list_is_sorted(list_a))
		return ;
	pb(val, list_a, list_b);
	sort_four(val, list_a, list_b);
	pa(val, list_b, list_a);
}

void	simple_sort(t_val *val, t_lon **list_a, t_lon **list_b)
{
	int	size;

	if (list_is_sorted(list_a) || ft_list_size(*list_a) == 0
		|| ft_list_size(*list_a) == 1)
		return ;
	size = ft_list_size(*list_a);
	if (size == 2)
		sa(val, list_a, list_b);
	else if (size == 3)
		sort_three(val, list_a, list_b);
	else if (size == 4)
		sort_four(val, list_a, list_b);
	else if (size == 5)
		sort_five(val, list_a, list_b);
}

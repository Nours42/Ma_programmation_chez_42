/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   russian_doll_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:11:27 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/02 12:17:53 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	val_init(t_val *val, t_lon **list_a, t_lon **list_b)
{
	t_lon	*dup_a;
	t_lon	*dup_b;

	dup_a = *list_a;
	dup_b = *list_b;
	val->size_a = ft_list_size(dup_a);
	val->size_b = ft_list_size(dup_b);
	val->index_max = val->size_a + val->size_b;
}

void	russian_doll_sort(t_val *val, t_lon **list_a, t_lon **list_b)
{
	int	i;

	if (val->rest == 0)
	{
		i = 80;
		val->rest = val->index_max;
	}
	while (val->rest > 0)
	{
		if (i <= 5)
			i = 0;
		val->div = val->rest * i / 100;
		ft_division(val, list_a, list_b);
		val->rest = val->div;
	}
}

void	ft_division(t_val *val, t_lon **list_a, t_lon **list_b)
{
	int		j;
	t_lon	*dup_a;
	t_lon	*dup_b;

	j = val->size_b;
	while (val->size_a > val->div)
	{
		dup_a = *list_a;
		if (dup_a->index <= (val->index_max - (val->div)))
		{
			pb(val, list_a, list_b);
			dup_a = *list_a;
			dup_b = *list_b;
			if ((dup_a && dup_a->index > val->index_max - val->div)
				&& (dup_b->index > ((val->rest - val->div) / 2) + j)
				&& (val->size_a > 0 && val->size_b >= 2))
				rr(val, list_a, list_b);
			else if ((dup_b->index
					> ((val->rest - val->div) / 2) + j) && (val->size_a
					> 0 && val->size_b >= 2))
				rb(val, list_a, list_b);
		}
		else
			ra(val, list_a, list_b);
	}
}

void	return_from_russia(t_val *val, t_lon **list_a, t_lon **list_b)
{
	int		i;
	int		y;
	t_lon	*dup;

	while (val->size_b != 0)
	{
		i = 0;
		y = val->size_b;
		dup = (*list_b);
		while ((val->size_b - 1) != dup->index)
		{
			dup = dup->next;
			i++;
			y--;
		}
		if (i <= y)
		{
			while (i-- != 0)
				rb(val, list_a, list_b);
		}
		else
			while (y-- != 0)
				rrb(val, list_a, list_b);
		pa(val, list_a, list_b);
	}
}

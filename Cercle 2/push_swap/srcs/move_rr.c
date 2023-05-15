/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:28:00 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/28 16:30:57 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_val *val, t_lon **list_a, t_lon **list_b)
{
	reverse_rotate(list_a);
	ft_putendl_fd("rra", 1);
	val_init(val, list_a, list_b);
}

void	rrb(t_val *val, t_lon **list_a, t_lon **list_b)
{
	reverse_rotate(list_b);
	ft_putendl_fd("rrb", 1);
	val_init(val, list_a, list_b);
}

void	rrr(t_val *val, t_lon **list_a, t_lon **list_b)
{
	if (ft_list_size(*list_a) < 2 || ft_list_size(*list_b) < 2)
		return ;
	reverse_rotate(list_a);
	reverse_rotate(list_b);
	ft_putendl_fd("rrr", 1);
	val_init(val, list_a, list_b);
}

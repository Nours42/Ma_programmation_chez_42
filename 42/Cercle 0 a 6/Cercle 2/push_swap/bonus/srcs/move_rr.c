/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:28:00 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/01 16:32:45 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_push_swap.h"

void	rra(t_lon **list_a)
{
	reverse_rotate(list_a);
}

void	rrb(t_lon **list_b)
{
	reverse_rotate(list_b);
}

void	rrr(t_lon **list_a, t_lon **list_b)
{
	if (ft_list_size(*list_a) < 2 || ft_list_size(*list_b) < 2)
		return ;
	reverse_rotate(list_a);
	reverse_rotate(list_b);
}

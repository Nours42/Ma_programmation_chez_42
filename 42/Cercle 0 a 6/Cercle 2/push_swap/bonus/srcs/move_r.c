/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:28:00 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/01 16:32:18 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_push_swap.h"

void	ra(t_lon **list_a)
{
	rotate(list_a);
}

void	rb(t_lon **list_b)
{
	rotate(list_b);
}

void	rr(t_lon **list_a, t_lon **list_b)
{
	if (ft_list_size(*list_a) < 2 || ft_list_size(*list_b) < 2)
		return ;
	rotate(list_a);
	rotate(list_b);
}

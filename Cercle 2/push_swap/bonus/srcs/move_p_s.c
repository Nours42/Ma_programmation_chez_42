/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_p_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:16:27 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/01 17:54:53 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_push_swap.h"

void	sa(t_lon **list_a)
{
	swap(list_a);
}

void	sb(t_lon **list_b)
{
	swap(list_b);
}

void	ss(t_lon **list_a, t_lon **list_b)
{
	if ((ft_list_size(*list_a) < 2) || (ft_list_size(*list_b) < 2))
		return ;
	swap(list_a);
	swap(list_b);
}

void	pa(t_lon **list_a, t_lon **list_b)
{
	push(list_b, list_a);
}

void	pb(t_lon **list_a, t_lon **list_b)
{
	push(list_a, list_b);
}

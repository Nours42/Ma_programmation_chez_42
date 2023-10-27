/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:28:00 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/28 16:30:52 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_val *val, t_lon **list_a, t_lon **list_b)
{
	rotate(list_a);
	ft_putendl_fd("ra", 1);
	val_init(val, list_a, list_b);
}

void	rb(t_val *val, t_lon **list_a, t_lon **list_b)
{
	rotate(list_b);
	ft_putendl_fd("rb", 1);
	val_init(val, list_a, list_b);
}

void	rr(t_val *val, t_lon **list_a, t_lon **list_b)
{
	if (ft_list_size(*list_a) < 2 || ft_list_size(*list_b) < 2)
		return ;
	rotate(list_a);
	rotate(list_b);
	ft_putendl_fd("rr", 1);
	val_init(val, list_a, list_b);
}

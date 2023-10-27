/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_p_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:16:27 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/28 16:30:47 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_val *val, t_lon **list_a, t_lon **list_b)
{
	swap(list_a);
	ft_putendl_fd("sa", 1);
	val_init(val, list_a, list_b);
}

void	sb(t_val *val, t_lon **list_a, t_lon **list_b)
{
	swap(list_b);
	ft_putendl_fd("sb", 1);
	val_init(val, list_a, list_b);
}

void	ss(t_val *val, t_lon **list_a, t_lon **list_b)
{
	if ((ft_list_size(*list_a) < 2) || (ft_list_size(*list_b) < 2))
		return ;
	swap(list_a);
	swap(list_b);
	ft_putendl_fd("ss", 1);
	val_init(val, list_a, list_b);
}

void	pa(t_val *val, t_lon **list_a, t_lon **list_b)
{
	push(list_b, list_a);
	ft_putendl_fd("pa", 1);
	val_init(val, list_a, list_b);
}

void	pb(t_val *val, t_lon **list_a, t_lon **list_b)
{
	push(list_a, list_b);
	ft_putendl_fd("pb", 1);
	val_init(val, list_a, list_b);
}

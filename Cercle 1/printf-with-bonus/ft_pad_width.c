/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:52:33 by sdestann          #+#    #+#             */
/*   Updated: 2023/03/01 17:31:48 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pad_width(int total_width, int size, int zero)
{
	int	count;

	count = 0;
	while (total_width - size > 0)
	{
		if (zero)
			count += ft_print_c('0');
		else
			count += ft_print_c(' ');
		total_width--;
	}
	return (count);
}

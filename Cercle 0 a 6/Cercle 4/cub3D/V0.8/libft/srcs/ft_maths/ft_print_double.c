/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:37:09 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/19 09:37:23 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_print_double(double i)
{
	double	temp;
	int		entier;
	int		decimales;
	int		signe;

	signe = 1;
	if (i < 0)
	{
		i *= -1;
		signe *= -1;
	}
	temp = i;
	entier = (int)temp;
	if (entier == -2147483648)
	{
		ft_printf("-2147483648.0\n");
		return ;
	}
	i -= entier;
	decimales = i * 10000;
	if (signe < 0)
		ft_printf("-");
	ft_printf("%d", entier);
	ft_printf(".");
	ft_printf("%d", decimales);
	ft_printf("\n");
}
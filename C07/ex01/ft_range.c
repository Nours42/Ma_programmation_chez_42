/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 05:45:34 by sdestann          #+#    #+#             */
/*   Updated: 2022/11/15 05:49:21 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*tab;

	i = min;
	if (min >= max)
		return (0);
	tab = malloc ((max - min + 1) * sizeof(int));
	while (i < max)
	{
		tab[i - min] = i;
		i++;
	}
	return (tab);
}

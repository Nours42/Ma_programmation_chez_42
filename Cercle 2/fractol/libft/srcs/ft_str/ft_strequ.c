/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:42:11 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/18 13:47:25 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int	i;

	if (s1 && s2)
	{
		if (ft_strcmp(s1, s2) > 0)
			i = 0;
		else
			i = 1;
		return (i);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 08:02:58 by sdestann          #+#    #+#             */
/*   Updated: 2022/11/05 08:39:53 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern	void	ft_putchar(char a)
{
	write (1, &a, 1);
}

extern	int	ft_wrong_value(int b, int c)
{
	if (b < 0 || c < 0)
	{
		write (1, "Oh grande moulinette, je te prie de bien vouloir", 48);
		write (1, " rentrer une valeur superieure a zero", 37);
		return (0);
	}
	return (0);
}

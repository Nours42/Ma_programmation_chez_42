/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:26:53 by sdestann          #+#    #+#             */
/*   Updated: 2022/11/10 06:30:49 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)
{
	write (1, &a, 1);
}

void	make_it_hexadecimal(char c)
{
	char			*hexaschema;
	unsigned char	h;
	unsigned int	quotient;
	unsigned int	reste;

	h = c;
	quotient = h / 16;
	reste = h % 16;
	hexaschema = "0123456789abcdef";
	ft_putchar('\\');
	ft_putchar(hexaschema[quotient]);
	ft_putchar(hexaschema[reste]);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 32 && str[i] <= 126))
		{
			make_it_hexadecimal(str[i]);
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}
}

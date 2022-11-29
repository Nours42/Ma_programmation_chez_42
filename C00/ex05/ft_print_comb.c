/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:19:22 by sdestann          #+#    #+#             */
/*   Updated: 2022/11/03 19:08:45 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_char(char d)
{
	write(1, &d, 1);
}

void	print_abc(int a, int b, int c)
{
	print_char(a + 48);
	print_char(b + 48);
	print_char(c + 48);
	if (a != 7 || b != 8 || c != 9)
		write (1, ", ", 2);
}

void	ft_print_comb(void)
{
	int	j;
	int	k;
	int	l;

	j = 0;
	while (j <= 7)
	{
		k = j + 1;
		while (k <= 8)
		{
			l = k + 1;
			while (l <= 9)
			{
				print_abc(j, k, l);
				l++;
			}
			k++;
		}
		j++;
	}
}

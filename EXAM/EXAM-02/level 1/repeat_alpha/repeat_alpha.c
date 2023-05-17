/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:59:12 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/16 12:15:56 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	nb;

	i = 0;
	if (ac == 2)
	{
		while(av[1][i])
		{
			nb = 0;
			if (av[1][i] >= 65 && av[1][i] <= 90)
			{
				nb = av[1][i] - 64;
				while (nb > 0)
				{
					write(1, &av[1][i], 1);
					nb--;
				}
			}
			else if (av[1][i] >= 97 && av[1][i] <= 122)
			{
				nb = av[1][i] - 96;
				while (nb > 0)
				{
					write(1, &av[1][i], 1);
					nb--;
				}
			}
			else
				write(1, &av[1][i], 1);
			
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
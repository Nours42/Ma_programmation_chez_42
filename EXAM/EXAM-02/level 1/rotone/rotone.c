/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:35:19 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/24 13:55:18 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	char c;

	i = 0;
	c = 0;
	if (argc == 2)
	{
		while(argv[1][i])
		{
			if ((argv[1][i] >= 65 && argv[1][i] <= 89) || (argv[1][i] >= 97 && argv[1][i] <= 121))
			{
				c = argv[1][i] + 1;
				write(1, &c, 1);
			}
			else if (argv[1][i] == 90 || argv[1][i] == 122)
			{
				c = argv[1][i] -25;
				write(1, &c, 1);
			}
			else
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
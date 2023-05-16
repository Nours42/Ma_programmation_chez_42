/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:17:52 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/16 09:31:45 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int first;
		int second;
		int denom;

		first = atoi(av[1]);
		second = atoi(av[2]);
		if (first < 0)
			first *= -1;
		else if (second < 0)
			second *= -1;
		denom = first;
		if (second < denom)
			denom = second;
		while (denom > 0)
		{
			if (first % denom == 0 && second % denom == 0)
			{
				printf("%d", denom);
				break;
			}
			denom--;
		}
	}
	printf("\n");
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:21:24 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/24 16:29:37 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	    is_power_of_2(unsigned int n)
{
	if (n == 1)
		return (1);
	while(n >= 2)
		if (n == 2)
			return (1);
		else
			n /= 2;
	return (0);
}

/*int	main(void)
{
	printf("4096, %d\n", is_power_of_2(4));
	printf("4097, %d\n", is_power_of_2(7));
	printf("-4, %d\n", is_power_of_2(-4));
	printf("-7, %d\n", is_power_of_2(-7));
}*/
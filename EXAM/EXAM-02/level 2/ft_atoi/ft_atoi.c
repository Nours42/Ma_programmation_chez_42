/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:18:28 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/16 12:33:36 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	i;
	int result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	if (str[0] == '-')
	{
		sign = -sign;
		i++;
	}
	else if (str[0] == '+')
		i++;
	while (str[i] >= 48 && str[i]<=57)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	result *= sign;
	return(result);
}

/*int	main(void)
{
	char *o;
	
	o = "123456!";
	printf("%d", ft_atoi(o));
	return (0);
}*/
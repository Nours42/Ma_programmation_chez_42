/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:11:37 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/24 14:55:36 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
	int i;
	int	sign;
	int	result;
	int	digit;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 7 && str[i] <= 13))
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			digit = (str[i] - '0');
		else if (str[i] >= 65 && str[i] <= 70)
			digit = 10 + (str[i] - 'A');
		else if (str[i] >= 97 && str[i] <= 102)
			digit = 10 + (str[i] - 'a');
		else
			break;
		if (digit > str_base)
			break;
		result = (result * str_base) + digit;
		i++;
	}
	result = result * sign;
	return (result);
}

/*int	main(void)
{
	printf("test de 12345 en base 10 : ");
	printf("%d\n", ft_atoi_base("12345", 10));
	printf("test de 4DD en base 16 : ");
	printf("%d\n", ft_atoi_base("4DD", 16));
	printf("test de 12345 en base 4 : ");
	printf("%d\n", ft_atoi_base("12345", 4));
	printf("test de 1234 en base 10 : ");
	printf("%d\n", ft_atoi_base("1234", 4));
	return (0);
}*/
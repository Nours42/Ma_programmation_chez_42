/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:12:10 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/12 17:26:03 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/colors.h"
#include "../includes/utils.h"

int	err(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	write(2, str, i);
	return (1);
}

int	test_atoi(char *c)
{
	if (ft_atoi(c) == atoi(c))
		return (0);
	else
		return (1);

}

int	test_atoi_gral(void)
{
	int i;

	i = 0;
	i += test_atoi(" \t\v\n\r\f123");
	i += test_atoi("0");
	i += test_atoi("-1000043");
	i += test_atoi("+00000000000000000000000000000000000000000000123");
	i += test_atoi("       123");
	i += test_atoi("--123");
	i += test_atoi("+-1213");
	i += test_atoi("- 1234");
	i += test_atoi("+ 1245");
	i += test_atoi("+\n123");
	i += test_atoi("12589");
	i += test_atoi("12/3");
	i += test_atoi("12.3");
	i += test_atoi("12;6");
	if (i > 0)
		return (1);
	return (0);
}

int	test_itoa(int i)
{
	char *c = ft_itoa(i);
	char *d = ft_itoa(i);
	if (strcmp(c, d) == 0)
		return (0);
	else
		return (1);

}

int	test_itoa_gral(void)
{
	int i;

	i = 0;
	i += test_itoa(1000034);
	i += test_itoa(-100004);
	i += test_itoa(INT_MAX);
	i += test_itoa(INT_MIN);
	i += test_itoa(0);
	if (i > 0)
		return (1);
	return (0);
}

int	main(void)
{
	if (test_atoi_gral())
		return (err("atoi faux"));
	else
		ft_printf("atoi OK\n");
	if (test_itoa_gral())
		return (err("itoa faux"));
	else
		ft_printf("itoa OK\n");
	return (0);
}
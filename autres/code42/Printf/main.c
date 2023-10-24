/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:36:40 by sdestann          #+#    #+#             */
/*   Updated: 2023/03/30 12:48:03 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	c;
	unsigned int d;

	d = 0;
	c = 12;

	printf("test char, %c\n", 'c');
	ft_printf("test char avec ft_printf, %c\n", 'c');
	printf("test int, %d\n", INT_MIN);
	ft_printf("test avec ft_printf, %d\n", INT_MIN);
	printf("test string, %s\n", "");
	ft_printf("test avec ft_printf, %s\n", "");
	printf("test char, %p\n", NULL);
	ft_printf("test avec ft_printf, %p\n", NULL);
	printf("test char, %x\n", c);
	ft_printf("test avec ft_printf, %x\n", c);
	printf("test char, %X\n", c);
	ft_printf("test avec ft_printf, %X\n", c);
	printf("test char, %%c\n");
	ft_printf("test avec ft_printf, %%c\n");
	printf("test char, %u\n", d);
	ft_printf("test avec ft_printf, %u\n", d);
	return (0);
}
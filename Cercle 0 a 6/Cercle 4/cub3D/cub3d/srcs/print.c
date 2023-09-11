/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:00:18 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/11 13:00:15 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	titre(char *str)
{
	int		i;

	i = ft_strlen(str);
	if (!str)
		return ;
	line(1);
	ft_printf("\t*** ");
	titre2(str, i);
	ft_printf(" ***\n");
	line(2);
	ft_printf("\n");
}

void	titre2(char *str, int i)
{
	int		j;

	if (i < 16)
	{
		i = (16 - ft_strlen(str)) / 2;
		j = -1;
		while (++j < i)
			ft_printf(" ");
		ft_printf("%s", str);
		j = -1;
		while (++j < i)
			ft_printf(" ");
	}
	else if (i > 16)
	{
		j = -1;
		while (++j < 15)
			ft_printf("%c", str[j]);
		ft_printf(".");
	}
	else
		ft_printf("%s", str);
}

int	titre_err(char *str)
{
	int		i;

	i = ft_strlen(str);
	if (!str)
		return (1);
	ft_printf("\n");
	line(3);
	ft_printf("\t*** ");
	titre2(str, i);
	ft_printf(" ***\n");
	line(2);
	ft_printf("\n");
	return (1);
}

void	line_up(int i)
{
	int	j;

	j = -1;
	ft_printf("\t***");
	while (++j < i)
		ft_printf("*");
	ft_printf("***\n");
}

void	line(int i)
{
	if (i == 0)
		ft_printf("\t************************\n");
	else if (i == 1)
		ft_printf("\033[34m\t************************\n");
	else if (i == 2)
		ft_printf("\t************************\n\033[0m");
	else if (i == 3)
		ft_printf("\033[31m\t************************\n");
}

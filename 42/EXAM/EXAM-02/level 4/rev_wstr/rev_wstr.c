/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:32:01 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/24 16:58:24 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	free_stock(char **stock)
{
	int	i;

	i = 0;
	while (stock[i])
	{
		free(stock[i]);
		i++;
	}
	free(stock);
}

int	find_the_next_space_or_tab(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] == ' ')
			return (i);
		else
			i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	char **stock;
	int	i;
	int j;
	int	k;
	int space_in_x_lettre;

	i = 0;
	j = 0;
	k = 0;
	if (ac == 2)
	{
		while(str[i])
		{
			space_in_x_lettre = 0;
			if (find_the_next_space_or_tab(av[1]) > 0)
			{
				space_in_x_lettre = find_the_next_space_or_tab(av[1]);
				k = space_in_x_lettre;
				stock[j] = malloc(sizeof(char) * (space_in_x_lettre + 1));
				if (!stock[j])
				{
					free_stock(stock);
					return (0);
				}
				while (space_in_x_lettre > 0)
					stock[j][k] = av[1][i + space_in_x_lettre]
			}
			else
			{
				i = 0;
				while(av[1][i])
					write(1, &av[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
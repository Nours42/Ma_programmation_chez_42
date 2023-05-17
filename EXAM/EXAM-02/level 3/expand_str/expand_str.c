/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:37:00 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/16 13:34:55 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int sp_or_tab_at_end(char *s)
{
	int	j;
	int k;

	k = 0;
	j = ft_strlen(s) - 1;
	while (s[j] == '\t' || s[j] == ' ')
	{
		k++;
		j--;
	}
	return (k);
}

int	main(int ac, char **av)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	if (ac == 2)
	{
		while (av[1][i] == '\t' || av[1][i] == ' ')
			i++;
		while (i < (ft_strlen(av[1]) - sp_or_tab_at_end(av[1])))
		{
			if (l == 0 && (av[1][i] == '\t' || av[1][i] == ' '))
			{
				l = 1;
				write(1, "   ", 3);
				i++;
			}
			else
			{
				while (av[1][i] == '\t' || av[1][i] == ' ')
					i++;
				if (av[1][i] == '\0')
					break;
				write(1, &av[1][i], 1);
				l = 0;
				i++;
			}
		}
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:22:50 by sdestann          #+#    #+#             */
/*   Updated: 2022/11/15 06:21:29 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	res;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
		i++;
	if (s1[i] == '\0' && s2[i] == '\0')
		res = 0;
	else
		res = s1[i] - s2[i];
	return (res);
}

void	ft_sort_int_tab(char **tab, int size)
{
	int		i;
	int		j;

	i = 1;
	j = 1;
	while (i < size)
	{
		while (j < size - 1)
		{
			if (ft_strcmp(tab[j], tab[j + 1]) > 0)
			{
				tab[0] = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = tab[0];
			}
			j++;
		}
		i++;
		j = 1;
	}
}

int	main(int argc, char **argv)
{
	char	**tab;
	int		i;
	int		j;

	tab = argv;
	ft_sort_int_tab(tab, argc);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (tab[i][j])
		{
			write(1, &tab[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

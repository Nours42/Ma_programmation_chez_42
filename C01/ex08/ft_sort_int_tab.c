/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 21:56:30 by sdestann          #+#    #+#             */
/*   Updated: 2022/11/05 21:56:41 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(char **tab, int size)
{
	int	compteur1;
	int	compteur2;
	char	*temp_value;

	compteur1 = 0;
	compteur2 = 0;
	temp_value = 0;
	while (compteur1 < size)
	{
		while (compteur2 < size - 1)
		{
			if (tab[compteur2] > tab[(compteur2 + 1)])
			{
				temp_value = tab[compteur2];
				tab[compteur2] = tab[compteur2 + 1];
				tab[compteur2 + 1] = temp_value;
			}
			compteur2++;
		}
		compteur2 = 0;
		compteur1++;
	}
}

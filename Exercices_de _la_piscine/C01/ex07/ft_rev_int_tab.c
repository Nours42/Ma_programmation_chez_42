/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 21:56:30 by sdestann          #+#    #+#             */
/*   Updated: 2022/11/05 21:56:41 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	compteur;
	int	temp_value;

	compteur = 0;
	temp_value = 0;
	while (compteur < (size / 2))
	{
		temp_value = tab[compteur];
		tab[compteur] = tab[size - 1 - compteur];
		tab[size - 1 - compteur] = temp_value;
		compteur++;
	}
}

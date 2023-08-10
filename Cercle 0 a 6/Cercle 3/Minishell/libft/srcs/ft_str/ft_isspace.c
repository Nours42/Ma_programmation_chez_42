/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:04:44 by sdestann          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/08/10 14:25:36 by sdestann         ###   ########.fr       */
=======
/*   Updated: 2023/08/10 13:19:02 by sdestann         ###   ########.fr       */
>>>>>>> bb6a7fbea488da8d2a8258804339c1d5318b2f78
/*                                                                            */
/* ************************************************************************** */

/*
** la fonction ft_isspaces renvoie 1 si le char * n'est composé que d'espaces
** ou équivalent
*/

int	ft_isspace(char *c)
{
	int	i;

	i = 0;
<<<<<<< HEAD
	while (c[i])
=======
	while(c[i])
>>>>>>> bb6a7fbea488da8d2a8258804339c1d5318b2f78
	{
		if (c[i] == 32 || (c[i] <= 13 && c[i] >= 9))
			i++;
		else
			return (0);
	}
	return (1);
}

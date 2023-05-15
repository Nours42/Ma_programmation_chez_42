/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:10:07 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/18 13:16:24 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	La fonction memalloc cree un pointeur, le malloc et en vide le resultat 
	obtenu avec la fonction	bzero.
*/

#include "../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	else
		ft_bzero(ptr, size);
	return (ptr);
}

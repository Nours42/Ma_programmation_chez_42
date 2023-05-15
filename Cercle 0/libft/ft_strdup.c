/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:57:42 by sdestann          #+#    #+#             */
/*   Updated: 2023/02/06 11:49:45 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* DESCRIPTION :
**
** The strdup function returns a pointer to a new string which is a duplicate
** of the string s. Memory for the new string is obtained with malloc(3), and
** can be freed with free(3).
**
*/

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	length;

	length = ft_strlen(s) + 1;
	dup = malloc(length * sizeof(char));
	if (dup == NULL)
		return (NULL);
	dup = ft_memcpy(dup, s, length);
	return (dup);
}

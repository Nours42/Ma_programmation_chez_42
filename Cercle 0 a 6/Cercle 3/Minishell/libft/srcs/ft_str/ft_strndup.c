/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:57:42 by sdestann          #+#    #+#             */
/*   Updated: 2023/07/04 15:36:27 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* DESCRIPTION :
**
** strncup malloc et copie s a partir de i
**
*/

char	*ft_strndup(const char *s, size_t i)
{
	char	*dup;
	size_t	length;

	length = ft_strlen(s) + 1 - i;
	dup = malloc(length * sizeof(char));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, length);
	return (dup);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:13:34 by sdestann          #+#    #+#             */
/*   Updated: 2023/02/06 10:30:56 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* DESCRIPTION :
**
** These functions check whether c, which must have the value of an unsigned
** char or EOF, falls into a certain character class according to the current
** locale. isalnum checks for an alphanumeric character; it is equivalent to 
** (isalpha(c) || isdigit(c)).
**
*/

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
	{
		return (1);
	}
	return (0);
}

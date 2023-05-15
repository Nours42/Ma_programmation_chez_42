/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:21:38 by sdestann          #+#    #+#             */
/*   Updated: 2023/02/05 18:10:38 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* DESCRIPTION :
**
** lst: The address of a pointer to a node.
** f: The address of the function used to iterate on the list.
** Iterates the list ’lst’ and applies the function ’f’ on the content of each
** node.
**
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

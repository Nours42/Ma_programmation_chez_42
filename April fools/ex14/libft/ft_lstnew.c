/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:19:33 by sdestann          #+#    #+#             */
/*   Updated: 2023/02/05 18:33:25 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* DESCRIPTION :
**
** content: The content to create the node with.
** Allocates (with malloc(3)) and returns a new node. The member variable
** ’content’ is initialized with the value of the parameter ’content’. The
** variable ’next’ is initialized to NULL.
**
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*element;

	element = malloc(sizeof(t_list));
	if (!element)
		return (NULL);
	element->content = content;
	element->next = NULL;
	return (element);
}

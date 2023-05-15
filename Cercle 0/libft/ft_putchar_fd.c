/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:57:14 by sdestann          #+#    #+#             */
/*   Updated: 2023/02/06 11:30:50 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* DESCRIPTION :
**
** Outputs the character ’c’ to the given file descriptor.
**
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:35:25 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/18 13:48:54 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	la fonction ft_close vide la valeur du param cible et sort du programme.
*/
#include "../includes/libft.h"

int	ft_close(void *param)
{
	(void)param;
	exit(0);
}

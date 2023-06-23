/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:04:29 by sdestann          #+#    #+#             */
/*   Updated: 2023/06/23 17:03:41 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_signal(int signal)
{
	if (signal == SIGINT)
		write(1, "\b\b  \b\b\nnotre magnifique minishell >> $ ", 39);
	else if (signal == SIGQUIT)
		ft_printf("\b\b  \b\b");
}

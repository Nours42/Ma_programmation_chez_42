/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:04:29 by sdestann          #+#    #+#             */
/*   Updated: 2023/06/16 15:08:22 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_signal(int signal)
{
	if (signal == SIGINT)
	{
		write(1, "\nSignal SIGINT reçu. Fermeture du shell.\n", 40);
		exit(EXIT_SUCCESS);
	}
}

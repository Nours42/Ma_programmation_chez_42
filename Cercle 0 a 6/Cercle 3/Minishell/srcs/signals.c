/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:04:29 by sdestann          #+#    #+#             */
/*   Updated: 2023/07/06 12:31:21 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_signal(struct sigaction *act, t_data *data)
{
	(void)data;
	act->sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&act->sa_mask);
	act->sa_handler = &handle_signal;
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, handle_signal);
}

void	handle_signal(int signal)
{
	if (signal == SIGINT)
	{
		write(1, "\b\b  \b\b\n", 7);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (signal == SIGQUIT)
		write(1, "\b\b  \b\b", 7);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:04:29 by sdestann          #+#    #+#             */
/*   Updated: 2023/07/11 11:46:55 by nours42          ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <kaly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:04:29 by sdestann          #+#    #+#             */
/*   Updated: 2023/07/17 16:05:23 by kaly             ###   ########.fr       */
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
}

void	handle_signal(int signal)
{
	if (signal == SIGINT)
	{
		write(1, "~>$\n", 4);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

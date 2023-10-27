/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:22:52 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/22 10:53:51 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	decoder_srv(int sig, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bit = -1;

	(void)context;
	if (kill(info->si_pid, 0) < 0)
	{
		ft_printf("ERROR : cant send signal to PID : %d\n", info->si_pid);
		exit(EXIT_FAILURE);
	}
	if (bit < 0 && !c)
		ft_printf("\nClient say : ");
	if (bit < 0)
		bit = __CHAR_BIT__ * sizeof(c) - 1;
	if (sig == SIGUSR1)
		c |= 1 << bit;
	else if (sig == SIGUSR2)
		c &= ~(1 << bit);
	if (!bit && c)
		ft_putchar_fd(c, 1);
	else if (!bit && !c)
		kill(info->si_pid, SIGUSR2);
	bit--;
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa1;
	struct sigaction	sa2;

	ft_printf("Server PID is %d", getpid());
	ft_printf("\n");
	sigemptyset(&sa1.sa_mask);
	sigemptyset(&sa2.sa_mask);
	sa1.sa_sigaction = decoder_srv;
	sa2.sa_sigaction = decoder_srv;
	sa1.sa_flags = SA_SIGINFO | SA_RESTART | SA_NODEFER;
	sa2.sa_flags = SA_SIGINFO | SA_RESTART | SA_NODEFER;
	sigaction(SIGUSR1, &sa1, NULL);
	sigaction(SIGUSR2, &sa2, NULL);
	while (1)
		sleep(1);
	return (0);
}

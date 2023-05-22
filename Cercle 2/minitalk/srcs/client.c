/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:08:30 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/22 10:47:23 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	g_bit_control;

void	reciever(int sig)
{
	if (sig == SIGUSR1)
		g_bit_control = 1;
	else if (sig == SIGUSR2)
	{
		ft_printf("Message received !\n");
		exit(EXIT_SUCCESS);
	}
}

void	decoder_clt(unsigned char c, pid_t pid)
{
	int	bit;

	bit = __CHAR_BIT__ * sizeof(c) - 1;
	while (bit >= 0)
	{
		if (kill(pid, 0) < 0)
		{
			ft_printf("ERROR : cant send sig to pid : %d\n", pid);
			exit(EXIT_FAILURE);
		}
		g_bit_control = 0;
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		while (g_bit_control != 1)
			usleep(10);
	}
}

int	main(int argc, char **argv)
{
	int		counter;
	int		server_pid;

	counter = 0;
	if (argc != 3)
	{
		ft_printf("Usage : ./client <pid> <string to send>\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		signal(SIGUSR1, reciever);
		signal(SIGUSR2, reciever);
		server_pid = ft_atoi(argv[1]);
		while (argv[2][counter])
		{
			decoder_clt(argv[2][counter], server_pid);
			counter++;
		}
		decoder_clt('\0', server_pid);
	}
	pause();
	return (0);
}

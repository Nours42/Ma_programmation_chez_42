/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 07:09:24 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/06 21:31:31 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// exit 127    A utility to be executed was not found.

void	msg_pipe(char *arg, t_data *data)
{
	write(2, "Command not found: ", 21);
	write(2, arg, ft_strlen(arg));
	write(2, "\n", 1);
	child_free(data);
	exit(127);
}

void	msg_error(char *err)
{
	perror(err);
	exit (1);
}

int	some_error(char *str)
{
	if (str)
		free(str);
	return (-1);
}

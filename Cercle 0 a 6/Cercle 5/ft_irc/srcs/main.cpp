/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:27:20 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/24 10:40:39 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ircserv.hpp"

int	print_error(std::string str)
{
	std::cerr << "error : " << str << std::endl;
	return (-1);
}

static int	print_usage(std::string exec)
{
	std::cerr << "usage: " << exec << " <port> <password>\n";
	return (EXIT_FAILURE);
}

int	check_numbers(char *str)
{
	unsigned int	i = 0;
	unsigned int	lenght = 0;

	while (str[lenght])
		lenght++;
	while (i < lenght)
	{
		if (isdigit(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_args(int argc, char **argv)
{
	if (argc != 3)
		return (print_error("not enougth or too many arguments\n"));
	if (!check_numbers(argv[1]))
		return (print_error("<port> must be a numeric value\n"));
	return (1);
}

int	main(int argc, char **argv)
{
	if (!check_args(argc, argv))
		return print_usage(argv[0]);
	// else
	// {
			// lancer le serveur sur le port;
	// }
	return (0);
}

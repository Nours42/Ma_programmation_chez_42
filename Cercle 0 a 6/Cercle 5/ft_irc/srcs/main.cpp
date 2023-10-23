/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:27:20 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/23 17:36:11 by sdestann         ###   ########.fr       */
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

int	check_number(std::string number)
{
	std::string::const_iterator it = number.begin();
    while (it != number.end() && std::isdigit(*it))
		++it;
    return (!number.empty() && it == number.end());
}

int	check_args(int argc, char **argv)
{
	if (argc != 3)
		std::error_runtime("not enougth or too many arguments\n");
	if (!check_numbers(argv[1]))
		std::error_runtime("<port> must be a numeric value\n");
	return (1);
}

int	main(int argc, char **argv)
{
	if (!checkargs(argc, argv))
		return print_usage(argv[0]);
	// else
	// {
			// lancer le serveur sur le port;
	// }
	return (0);
}

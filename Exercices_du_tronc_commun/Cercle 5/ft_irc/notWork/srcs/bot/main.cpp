/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:17:59 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/21 13:18:01 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bot.hpp"

static int print_usage(std::string exec)
{
	std::cerr << "usage: " << exec << " <host> <port: int> <password> <channel>\n";
	return EXIT_FAILURE;
}

static bool print_error(std::string err)
{
	std::cerr << "error: " << err << std::endl;
	return false;
}

static bool check_number(std::string number)
{
	std::string::const_iterator it = number.begin();
    while (it != number.end() && std::isdigit(*it)) ++it;
    return (!number.empty() && it == number.end());
}

static bool check_args(int ac, char **av)
{
	if (ac != 5)
		return print_error("not enough arguments");
	if (!check_number(av[2]))
		return print_error("port must be numeric");
	return true;
}

int main(int ac, char **av)
{
	if (!check_args(ac, av))
		return print_usage(av[0]);

	Bot bot(
		std::string(av[1]),
		std::atoi(av[2]),
		std::string(av[3])
	);
	bot.connect(std::string(av[4]));

	return EXIT_SUCCESS;
}


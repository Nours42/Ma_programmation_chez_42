/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:20:35 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/21 13:20:35 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "ft_irc.hpp"

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cout << "Usage: " << argv[0] << " <port> <password>" << std::endl;
		return (1);
	}
	else if (!containsOnlyDigits(argv[1]))
	{
		std::cout << "Port must be a number" << std::endl;
		return (1);
	}

	Server server = Server(atoi(argv[1]), argv[2]);
	server.listen();
	return (0);
}

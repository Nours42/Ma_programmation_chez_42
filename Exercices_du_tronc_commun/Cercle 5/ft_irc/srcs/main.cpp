/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:27:20 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/28 18:52:21 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ircserv.hpp"
#include "../includes/Channel.hpp"
#include "../includes/ChannelManager.hpp"
#include "../includes/User.hpp"
#include "../includes/UserManager.hpp"
#include "../includes/CmdsManager.hpp"

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

bool check_numbers(const char *chaine)
{
    while(*chaine)
	{
        if (!isdigit(*chaine))
            return false;
		chaine++;
    }
    return true;
}

int	check_args(int argc, const char **argv)
{
	if (argc != 3)
		return (print_error("not enougth or too many arguments\n"));
	if (!check_numbers(argv[1]))
		return (print_error("<port> must be a numeric value\n"));
	return (1);
}

int	main(int argc, const char **argv)
{
	if (!check_args(argc, argv))
		return print_usage(argv[0]);
	// else
	// {
			// lancer le serveur sur le port;
	// }
	return (0);
}

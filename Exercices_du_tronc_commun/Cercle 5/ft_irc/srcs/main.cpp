/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:27:20 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/30 16:01:13 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Server.hpp"

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

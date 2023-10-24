/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:17:10 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/04 13:40:09 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	Harl;

	if (argc != 2)
	{
		std::cout << "Program arguments error" << std::endl;
		return (-1);
	}
	Harl.complain(argv[1]);
	return (0);
}
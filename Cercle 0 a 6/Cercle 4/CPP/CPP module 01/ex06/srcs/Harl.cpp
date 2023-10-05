/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:22:06 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/04 13:36:05 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <cstdio>

Harl::Harl()
{

}

Harl::~Harl()
{

}

// Private

void	Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
	std::cout << std::endl;
}

void	Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
	std::cout << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming here for years and you just started working here last month." << std::endl;
	std::cout << std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

// Public
void	Harl::complain( std::string level )
{
	void	(Harl::*fct[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	std::string	msg[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			index = -1;
	int			i = 0;
	while (i < 4)
	{
		if (level == msg[i])
		{
			index = i;
			break;
		}
		i++;
	}

	switch (index)
	{
		case (0):
			i = index;
			while (i < 4)
			{
				(this->*(fct[i]))();
				i++;
			}
			break ;
		case (1):
			i = index;
			while (i < 4)
			{
				(this->*(fct[i]))();
				i++;
			}
			break ;
		case (2):
			i = index;
			while (i < 4)
			{
				(this->*(fct[i]))();
				i++;
			}
			break ;
		case (3):
			i = index;
			while (i < 4)
			{
				(this->*(fct[i]))();
				i++;
			}
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
	}
}
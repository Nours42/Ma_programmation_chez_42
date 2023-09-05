/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:15:35 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/02 18:41:24 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie		*horde;
	std::string	number;
	int			nb;

	std::cout << "Please enter the number of zombies you want to fight\n";
	std::getline(std::cin, number);
	if (std::cin.eof())
		nb = -1;
	else
		nb = atoi(number.c_str());
	if (nb <= 0)
	{
		std::cout << "None ? are you a coward ? i choose for you... 6 zombies is enough no ?" << std::endl;
		nb = 6;
	}
	else if (nb > 19)
	{
		std::cout << "i think you're to brave... try 19 zombies for now Ok ?"<< std::endl;
		nb = 19;
	}
	std::cout << "My Zombie Horde is commmmmiiiiinnnnngggg !!!!!" << std::endl;
	horde = zombieHorde(nb, "Zombie number ");

	delete [] horde;
	std::cout << "you're a great killer of zombies ! have you make that before ?" << std::endl;
	return (0);
}

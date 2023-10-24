/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:27:54 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/06 05:57:35 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/DiamondTrap.hpp"

int	main(void)
{
	std::string s1 = "Conan";
	std::string s2 = "Sonja";
	std::string s3 = "Brice de Nice";
	std::string s4 = "Hibernatus";

	std::cout << std::endl;
	std::cout << "\t\tCreator call" << std::endl;
	std::cout << std::endl;

	ClapTrap	claptrap(s1);
	ScavTrap	scavtrap(s2);
	FragTrap	fragtrap(s3);
	DiamondTrap	diamondtrap(s4);

	std::cout << std::endl;
	std::cout << "\t\tex00 and ex01" << std::endl;
	std::cout << std::endl;
	claptrap.attack(s2);
	scavtrap.takeDamage(0);
	scavtrap.beRepaired(18);
	std::cout << std::endl;
	scavtrap.attack(s1);
	claptrap.takeDamage(20);
	scavtrap.attack(s1);
	claptrap.takeDamage(20);
	scavtrap.attack(s1);
	claptrap.beRepaired(64);
	std::cout << std::endl;
	std::cout << "\t\tex02" << std::endl;
	std::cout << std::endl;
	scavtrap.guardGate();
	scavtrap.attack(s1);
	std::cout << std::endl;
	scavtrap.takeDamage(100);
	scavtrap.takeDamage(1);
	scavtrap.attack(s2);
	scavtrap.beRepaired(200);
	std::cout << std::endl;
	fragtrap.highFivesGuys();
	std::cout << std::endl;
	std::cout << "\t\tex03" << std::endl;
	std::cout << std::endl;
	diamondtrap.WhoAmI();
	diamondtrap.highFivesGuys();
	diamondtrap.attack(s3);
	diamondtrap.beRepaired(1);
	diamondtrap.guardGate();
	diamondtrap.WhoAmI();
	std::cout << std::endl;
	std::cout << "\t\tdestructor call" << std::endl;
	std::cout << std::endl;
	
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:07:21 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/06 05:53:32 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"
#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) :  ClapTrap(name + "\033[31m_clap_trap\033[0m"), ScavTrap(name + "\033[32m_clap_trap\033[0m"), FragTrap(name + "\033[33m_clap_trap\033[0m")
{
	this->_name = name;
	std::cout << "ridiculous \033[33mDiamondTrap\033[0m "  << name << " begone !" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << this->_class_name << " (DiamondTrap) "  << this->_name << " is now destroyed..." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap & rhs) : ClapTrap(rhs.get_name() + "\033[34m_clap_trap\033[0m"), ScavTrap(rhs.get_name() + "\033[32m_clap_trap\033[0m"), FragTrap(rhs.get_name() + "\033[33m_clap_trap\033[0m")
{
	this->_name = rhs.get_name();
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & rhs)
{
	this->_name = rhs.get_name();
	return (*this);
}

void DiamondTrap::WhoAmI(void)
{
	std::cout << "I don't fell good... Who Am I ? John Doooo ? or " << this->_class_name << " " << this->_name << std::endl << "and why so many dead here ? Am I a serial killer ?" << std::endl;
}

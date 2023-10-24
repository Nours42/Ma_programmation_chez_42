/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:07:21 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/05 16:52:38 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

void	FragTrap::attack(std::string const & target)
{
	std::string		class_name = "FragTrap";
	std::string		name = this->_name;
	unsigned int	current_energy_points = this->_energy_points;
	unsigned int	dmg = this->_attack_damage;
	unsigned int	attack_energy_cost = this->_class_attack_energy_cost;

	if (this->_hitpoints == 0)
	{
		std::cout << class_name << " " << name << " cannot attack because he's dead" << std::endl;
		return ;
	}
	if (current_energy_points >= attack_energy_cost)
	{
		std::cout << class_name << " " << name << " use a FragTrap attack on " << target << " causing " << dmg << " points of damage!" << std::endl;
		std::cout << "This attack use " << class_name << " " << name << " " << attack_energy_cost << " energy points" << std::endl;
		this->_energy_points -= attack_energy_cost;
	}
	else
		std::cout << class_name << " " << name << " tries to attack " << target << " but doesn't have enough energy points" << std::endl;
	std::cout << class_name << " " << name << " now has " << this->_energy_points << " energy points left" << std::endl;
}

FragTrap::FragTrap(std::string name) :  ClapTrap(name, "\033[32mFragTrap\033[0m", 100, 100, 30)
{
	this->set_name(name);
	std::cout << "\033[32mFragTrap\033[0m "  << name << " appears !" << std::endl;
}

FragTrap::~FragTrap()
{
	std::string		class_name = this->_class_name;

	std::cout << class_name << " (FragTrap) "  << this->_name << " is now destroyed..." << std::endl;
}

FragTrap::FragTrap(const FragTrap & rhs) : ClapTrap(rhs.get_name())
{
	this->set_name(get_name());
	this->set_attack_damage(rhs.get_attack_damage());
	this->set_energy_points(rhs.get_energy_points());
	this->set_hitpoints(rhs.get_hitpoints());
}

FragTrap & FragTrap::operator=(FragTrap const & rhs)
{
	this->set_name(rhs.get_name());
	this->set_attack_damage(rhs.get_attack_damage());
	this->set_energy_points(rhs.get_energy_points());
	this->set_hitpoints(rhs.get_hitpoints());
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "High Five to your buddy " << this->_class_name << " " << this->_name << std::endl << "\"Whazzzup broooo ???\" ... \'Oh you're dead...\'" << std::endl <<"~~~slowly take away...~~~\n";
}

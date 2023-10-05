/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:07:21 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/05 15:21:08 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

const unsigned int	ScavTrap::_class_hp = 100;
const unsigned int	ScavTrap::_class_energy_points = 50;
const unsigned int	ScavTrap::_class_attack_energy_cost = 25;
const unsigned int	ScavTrap::_class_attack_damage = 20;

void	ScavTrap::attack(std::string const & target)
{
	std::string		class_name = this->_class_name;
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
		std::cout << class_name << " " << name << " use a ScavTrap attack on " << target << " causing " << dmg << " points of damage!" << std::endl;
		std::cout << "This attack use " << class_name << " " << name << " " << attack_energy_cost << " energy points" << std::endl;
		this->_energy_points -= attack_energy_cost;
	}
	else
		std::cout << class_name << " " << name << " tries to attack " << target << " but doesn't have enough energy points" << std::endl;
	std::cout << class_name << " " << name << " now has " << this->_energy_points << " energy points left" << std::endl;
}

void	ScavTrap::guardGate( void )
{
	std::string		class_name = this->_class_name;
	std::string		name = this->_name;

	std::cout << class_name << " " << name << " has entered in Gate Keeper mode" << std::endl;
	this->set_energy_points(this->_class_energy_points);
	std::cout <<class_name << " " << name << " has fully recovered his energy points !" << std::endl;
}

ScavTrap::ScavTrap(std::string name) :  ClapTrap(name, "\033[31mScavTrap\033[0m")
{
	std::string		class_name = this->_class_name;

	this->_class_name = "\033[31mScavTrap\033[0m";
	this->_name = name;
	this->_attack_damage = this->_class_attack_damage;
	this->_energy_points = this->_class_energy_points;
	this->_hitpoints = this->_class_hp;
	std::cout << class_name << " "  << this->_name << " has been created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap & src) : ClapTrap(src.get_name())
{
	this->_name = src.get_name();
	this->_attack_damage = src.get_attack_damage();
	this->_energy_points = src.get_energy_points();
	this->_hitpoints = src.get_hitpoints();
}

ScavTrap::~ScavTrap()
{
	std::string		class_name = this->_class_name;

	std::cout << class_name << " (ScavTrap) "  << this->_name << " is now destroyed..." << std::endl;
}

ScavTrap & ScavTrap::operator=(const ScavTrap & rhs)
{
	this->_name = rhs.get_name();
	this->_attack_damage = rhs.get_attack_damage();
	this->_energy_points = rhs.get_energy_points();
	this->_hitpoints = rhs.get_hitpoints();
	return (*this);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:06:10 by nours42           #+#    #+#             */
/*   Updated: 2023/10/10 14:13:08 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character(){}

Character::Character(std::string const & name)
{
	this->_name = name;
	this->_indexFloor = -1;
	for (int i = 0; i < 4; i++)
	{
		this->_slot[i] = NULL;
		this->_floor[i] = NULL;
	}
	if (0)
		std::cout << YELLOW << "[Character] name constructor called name= " << name << std::endl << NO_COLOR;
}

Character::Character(Character const & input)
{
	*this = input;
	this->_name = input._name + "_copy";
	if (0)
		std::cout << YELLOW << "[Character] copy constructor called name= " << input._name << std::endl << NO_COLOR;
}

Character const & Character::operator=(Character const & input)
{
	this->_name = input._name + "_assigned";
	for (int i = 0; i < 4; i++)
	{
		if (input._slot[i] != NULL)
			this->_slot[i] = input._slot[i]->clone();
		else
			this->_slot[i] = NULL;
		this->_floor[i] = NULL;
	}
	this->_indexFloor = -1;
	if (0)
		std::cout << YELLOW << "[Character] assignement constructor called name= " << input._name << std::endl << NO_COLOR;
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i] != NULL)
		{
			delete this->_slot[i];
			if (0)
				std::cout << YELLOW << "[Character] destructor deleted element at slot[" << i << "]" << std::endl << std::endl << NO_COLOR;
		}
		if (this->_floor[i] != NULL)
		{
			delete this->_floor[i];
			if (0)
				std::cout << YELLOW << "[Character] destructor deleted element at floor[" << i << "]" << std::endl << std::endl << NO_COLOR;
		}
	}
	if (0)
		std::cout << YELLOW << "[Character] destructor called name= " << this->_name << std::endl << NO_COLOR;
}

std::string const & Character::getName(void) const
{
	return (this->_name);
}

void	Character::equip(AMateria * m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i] == NULL)
		{
			this->_slot[i] = m;
			std::cout << YELLOW << this->_name << " equiped " << m->getType() << " at slot[" << i << "]" << std::endl << NO_COLOR;
			m = NULL;
			break ;
		}
	}
	if (m != NULL)
	{
		std::cout	<< YELLOW << this->_name << " tried to equiped " << m->getType() << " at a slot, but all are full! "
					<< m->getType() << "" << std::endl << NO_COLOR;
		this->drop(m);
	}
}

void	Character::unequip(int idx)
{
	if (this->_slot[idx] != NULL)
	{
		std::cout << YELLOW << this->_name << " unquiped " << this->_slot[idx]->getType() << " from slot[" << idx << "]" << std::endl << NO_COLOR;
		this->drop(this->_slot[idx]);
		this->_slot[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter & target)
{
	
	if (this->_slot[idx] != NULL)
	{
		std::cout << YELLOW << this->_name << " " << NO_COLOR;
		this->_slot[idx]->use(target);
	}
	else
		std::cout << YELLOW << this->_name << " tried to use slot[" << idx << "] but its empty!" << std::endl << NO_COLOR;
}

void	Character::drop(AMateria * m)
{
	this->_indexFloor++;
	if (this->_indexFloor == 4)
	{
		this->_indexFloor = 0;
		delete this->_floor[0];
	}
	this->_floor[this->_indexFloor] = m;
	std::cout << YELLOW << m->getType() << " dropped on the floor[" << this->_indexFloor << "]" << std::endl << NO_COLOR;
}
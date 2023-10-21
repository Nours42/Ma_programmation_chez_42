/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:05:06 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/20 09:28:20 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

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
	if (DEBUG)
		std::cout << COLOR_YELLOW << "[Character] name constructor called name= " << name << std::endl << COLOR_DEFAULT;
}

Character::Character(Character const & input)
{
	*this = input;
	this->_name = input._name + "_copy";
	if (DEBUG)
		std::cout << COLOR_YELLOW << "[Character] copy constructor called name= " << input._name << std::endl << COLOR_DEFAULT;
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
	if (DEBUG)
		std::cout << COLOR_YELLOW << "[Character] assignement constructor called name= " << input._name << std::endl << COLOR_DEFAULT;
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i] != NULL)
		{
			delete this->_slot[i];
			if (DEBUG)
				std::cout << COLOR_YELLOW << "[Character] destructor deleted element at slot[" << i << "]\n" << std::endl << COLOR_DEFAULT;
		}
		if (this->_floor[i] != NULL)
		{
			delete this->_floor[i];
			if (DEBUG)
				std::cout << COLOR_YELLOW << "[Character] destructor deleted element at floor[" << i << "]\n" << std::endl << COLOR_DEFAULT;
		}
	}
	if (DEBUG)
		std::cout << COLOR_YELLOW << "[Character] destructor called name= " << this->_name << std::endl << COLOR_DEFAULT;
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
			std::cout << COLOR_YELLOW << this->_name << " equiped " << m->getType() << " at slot[" << i << "]\n" << COLOR_DEFAULT;
			m = NULL;
			break ;
		}
	}
	if (m != NULL)
	{
		std::cout	<< COLOR_YELLOW << this->_name << " tried to equiped " << m->getType() << " at a slot, but all are full! "
					<< m->getType() << "\n" << COLOR_DEFAULT;
		this->drop(m);
	}
}

void	Character::unequip(int idx)
{
	if (this->_slot[idx] != NULL)
	{
		std::cout << COLOR_YELLOW << this->_name << " unquiped " << this->_slot[idx]->getType() << " from slot[" << idx << "]\n" << COLOR_DEFAULT;
		this->drop(this->_slot[idx]);
		this->_slot[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter & target)
{
	
	if (this->_slot[idx] != NULL)
	{
		std::cout << COLOR_YELLOW << this->_name << " " << COLOR_DEFAULT;
		this->_slot[idx]->use(target);
	}
	else
		std::cout << COLOR_YELLOW << this->_name << " tried to use slot[" << idx << "] but its empty!\n" << COLOR_DEFAULT;
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
	std::cout << COLOR_YELLOW << m->getType() << " dropped on the floor[" << this->_indexFloor << "]\n" << COLOR_DEFAULT;
}

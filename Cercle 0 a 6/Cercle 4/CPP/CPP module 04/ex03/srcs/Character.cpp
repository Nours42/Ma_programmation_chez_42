/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:06:10 by nours42           #+#    #+#             */
/*   Updated: 2023/10/09 23:00:02 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

////////////////////////////////////// CANONICAL FORM ////////////////////////////////////////////////////////	
//																											// 
// Character::Character()																					//
// {																										//	
// 	std::cout << "Character constructor called" << std::endl;												//
// }																										//
																											//
Character::~Character()																						//
{																											//
	int	i;																									//
																											//
	i = -1;																									//
	while (++i < 4)																							//
	{																										//
		if (this->_inventory[i])																			//
			delete this->_inventory[i];																		//
	}																										//
	std::cout << "Character named " << this->_name << " has been destroyed" << std::endl;					//
}																											//
																											//
Character::Character(Character const & ref) : _name(ref.getName() + "_copy")								//
{																											//
	int	i;																									//
																											//
	i = -1;																									//
	while (++i < 4)																							//
	{																										//
		if (ref._inventory[i])																				//
			this->_inventory[i] = (ref._inventory[i])->clone();												//
	}																										//
	std::cout << "A character named " << _name << " was created from copy of " << ref._name << std::endl;	//
}																											//
																											//
Character & Character::operator=(const Character & ref)														//
{																											//
	int	i;																									//
																											//
	i = -1;																									//
	while (++i < 4)																							//
	{																										//
		if (this->_inventory[i])																			//
			delete this->_inventory[i];																		//
		if (ref._inventory[i])																				//
			this->_inventory[i] = (ref._inventory[i])->clone();												//
	}																										//
	return (*this);																							//
}																											//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void	Character::equip(AMateria *m)
{
	int	i = 0;
	if (!m)
	{
		std::cout << this->_name << " tried to equip nothing and it did nothing" << std::endl;
		return ;
	}
	while (this->_inventory[i] !=0 && i < 4)
		i++;
	if (i >= 4)
	{
		std::cout << this->_name << " can't equip more than 4 Materia" << std::endl;
		return ;
	}
	this->_inventory[i] = m;
	std::cout << this->_name << " equipped materia " << m->getType() << " in slot " << i << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		std::cout << this->_name << " tried to unequip nothing at slot " << idx << " and it did nothing" << std::endl;
	else if (!this->_inventory[idx])
		std::cout << this->_name << " has nothing equipped at slot " << idx << " so he can't unequip it" << std::endl;
	else
	{
		AMateria *ptr = this->_inventory[idx];
		std::cout << this->_name << " unequipped " << ptr->getType() << " at slot "<< idx << "\n";
		this->_inventory[idx] = 0;
	}
}

void Character::use(int idx, ICharacter& target)
{
	std::string	name;

	name = this->getName();
	if (idx < 0 || idx > 4 || !this->_inventory[idx])
	{
		std::cout << "Nothing found to use at index " << idx << std::endl;
		return ;
	}
	std::cout << name;
	((this->_inventory)[idx])->use(target);
}

AMateria	*Character::getMateriaFromInventory(int idx)
{
	return (this->_inventory[idx]);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:06:10 by nours42           #+#    #+#             */
/*   Updated: 2023/10/09 22:49:39 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"
#include "../includes/AMateria.hpp"

////////////////////////////////////// CANONICAL FORM ////////////////////////////////////////
																							//
MateriaSource::MateriaSource()																//
{																							//
	int	i;																					//
																							//
	i = -1;																					//
	while (++i < 4)																			//	
	{																						//
		this->_inventory[i] = 0;															//
	}																						//
	std::cout << "Materia source was created" << std::endl;									//
}																							//
																							//
MateriaSource::~MateriaSource()																//
{																							//
	int i;																					//
																							//
	i = -1;																					//
	while (++i < 4)																			//
	{																						//
		if (this->_inventory[i])															//
			delete this->_inventory[i];														//
	}																						//
	std::cout << "Materia source was destroyed" << std::endl;								//
}																							//
																							//
MateriaSource::MateriaSource(MateriaSource const & ref)	: IMateriaSource()					//
{																							//
	int i;																					//
																							//
	i = -1;																					//
	while (++i < 4)																			//
	{																						//
		if (ref._inventory[i])																//
			this->_inventory[i] = ref._inventory[i]->clone();								//
	}																						//
	std::cout << "Materia source was created from copy" << std::endl;						//
}																							//
																							//
MateriaSource & MateriaSource::operator=(const MateriaSource & ref)							//
{																							//
	int i;																					//
																							//
	i = -1;																					//
	while (++i < 4)																			//
	{																						//	
		if (this->_inventory[i])															//
			delete this->_inventory[i];														//
		if (ref._inventory[i])																//
			this->_inventory[i] = (ref._inventory[i])->clone();								//
	}																						//
	return (*this);																			//
}																							//
//////////////////////////////////////////////////////////////////////////////////////////////

void	MateriaSource::learnMateria(AMateria *m)
{
	int i = 0;

	while ((this->_inventory)[i] != 0 && i < 4)
		i++;
	if (i >= 4)
	{
		std::cout << "Can't learn more than 4 Materia" << std::endl;
		return ;
	}
	(this->_inventory)[i] = m;
	std::cout << "Materia " << m->getType() << " learned" << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	int i = 0;

	while ((this->_inventory)[i] && ((this->_inventory)[i])->getType() != type && i < 4)
		i++;
	if (i >= 4 || !(this->_inventory)[i])
	{
		std::cout << type << " materia does not exit" << std::endl;
		return (NULL);
	}
	std::cout << "Materia " << type << " created" << std::endl;
	return (((this->_inventory)[i])->clone());
}

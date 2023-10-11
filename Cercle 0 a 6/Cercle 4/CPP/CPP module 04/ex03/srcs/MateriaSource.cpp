/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:06:10 by nours42           #+#    #+#             */
/*   Updated: 2023/10/10 13:47:24 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		this->_slot[i] = NULL;
	}
	if (0)
		std::cout << MAGENTA << "[MateriaSource] default constructor called" << std::endl << NO_COLOR;
}

MateriaSource::MateriaSource(MateriaSource const & input)
{
	*this = input;
	if (0)
		std::cout << MAGENTA << "[MateriaSource] copy constructor called" << std::endl;
}

MateriaSource const & MateriaSource::operator=(MateriaSource const & input)
{
	for (int i = 0; i < 4; i++)
	{
		if (input._slot[i] != NULL)
		{
			this->_slot[i] = input._slot[i]->clone();
			if (0)
				std::cout << MAGENTA << "[MateriaSource] copied " << input._slot[i]->getType() << "" << std::endl << NO_COLOR;
		}
		else
			this->_slot[i] = NULL;
	}
	if (0)
		std::cout << MAGENTA << "[MateriaSource] assignement constructor called" << std::endl << NO_COLOR;
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i] != NULL)
			delete _slot[i];
	}
	if (0)
		std::cout << MAGENTA << "[MateriaSource] destructor called" << std::endl << NO_COLOR;
}

void MateriaSource::learnMateria(AMateria * m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i] == NULL)
		{
			this->_slot[i] = m;
			std::cout << MAGENTA << "MateriaSource just learnt " << m->getType() << " at slot[" << i << "]" << std::endl << NO_COLOR;
			m = NULL;
			break ;
		}
	}
	if (m != NULL)
	{
		std::cout	<< MAGENTA << "MateriaSource tried to learn " << m->getType() << " at a slot, but all are full! "
					<< m->getType() << " is lost forever!" << std::endl << NO_COLOR;
		delete m;
	}
}

AMateria * MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i] != NULL && this->_slot[i]->getType() == type)
		{
			return (this->_slot[i]->clone());
		}
	}
	return (0);
}

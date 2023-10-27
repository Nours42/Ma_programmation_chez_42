/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:38:05 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/20 09:26:14 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		this->_slot[i] = NULL;
	}
	if (DEBUG)
		std::cout << COLOR_MAGENTA << "[MateriaSource] default constructor called" << std::endl << COLOR_DEFAULT;
}

MateriaSource::MateriaSource(MateriaSource const & input)
{
	*this = input;
	if (DEBUG)
		std::cout << COLOR_MAGENTA << "[MateriaSource] copy constructor called\n";
}

MateriaSource const & MateriaSource::operator=(MateriaSource const & input)
{
	for (int i = 0; i < 4; i++)
	{
		if (input._slot[i] != NULL)
		{
			this->_slot[i] = input._slot[i]->clone();
			if (DEBUG)
				std::cout << COLOR_MAGENTA << "[MateriaSource] copied " << input._slot[i]->getType() << "\n" << COLOR_DEFAULT;
		}
		else
			this->_slot[i] = NULL;
	}
	if (DEBUG)
		std::cout << COLOR_MAGENTA << "[MateriaSource] assignement constructor called\n" << COLOR_DEFAULT;
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i] != NULL)
			delete _slot[i];
	}
	if (DEBUG)
		std::cout << COLOR_MAGENTA << "[MateriaSource] destructor called\n" << COLOR_DEFAULT;
}

void MateriaSource::learnMateria(AMateria * m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i] == NULL)
		{
			this->_slot[i] = m;
			std::cout << COLOR_MAGENTA << "MateriaSource just learnt " << m->getType() << " at slot[" << i << "]\n" << COLOR_DEFAULT;
			m = NULL;
			break ;
		}
	}
	if (m != NULL)
	{
		std::cout	<< COLOR_MAGENTA << "MateriaSource tried to learn " << m->getType() << " at a slot, but all are full! "
					<< m->getType() << " is lost forever!\n" << COLOR_DEFAULT;
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

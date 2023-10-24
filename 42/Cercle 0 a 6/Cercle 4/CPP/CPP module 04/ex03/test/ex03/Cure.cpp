/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:40:17 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/20 07:41:21 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	if (DEBUG)
		std::cout << COLOR_GREEN << "[Cure] default constructor called\n" << COLOR_DEFAULT;
}

Cure::Cure(std::string const & type) : AMateria(type)
{
	if (DEBUG)
		std::cout << COLOR_GREEN << "[Cure] default constructor called\n" << COLOR_DEFAULT;
}

Cure::Cure(Cure const & input) : AMateria("Cure_copy")
{
	*this = input;
	if (DEBUG)
		std::cout << COLOR_GREEN << "[Cure] copy constructor called\n";
}

Cure const & Cure::operator=(Cure const & input)
{
	this->_type = input._type;
	if (DEBUG)
		std::cout << COLOR_GREEN << "[Cure] assignement constructor called\n" << COLOR_DEFAULT;
	return (*this);
}

Cure::~Cure(void)
{
	if (DEBUG)
		std::cout << COLOR_GREEN << "[Cure] destructor called\n" << COLOR_DEFAULT;
}

std::string const & Cure::getType(void) const
{
	return (this->_type);
}

AMateria *	Cure::clone(void) const
{
	return (new Cure("cure"));
}

void	Cure::use(ICharacter & target)
{
	std::cout << COLOR_GREEN << "* heals " << target.getName() << "'s wounds *\n" << COLOR_DEFAULT;
}

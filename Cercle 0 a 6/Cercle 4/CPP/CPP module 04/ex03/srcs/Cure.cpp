/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:06:10 by nours42           #+#    #+#             */
/*   Updated: 2023/10/10 14:07:39 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	if (0)
		std::cout << GREEN << "[Cure] default constructor called" << std::endl << NO_COLOR;
}

Cure::Cure(std::string const & type) : AMateria(type)
{
	if (0)
		std::cout << GREEN << "[Cure] default constructor called" << std::endl << NO_COLOR;
}

Cure::Cure(Cure const & input) : AMateria("Cure_copy")
{
	*this = input;
	if (0)
		std::cout << GREEN << "[Cure] copy constructor called" << std::endl;
}

Cure const & Cure::operator=(Cure const & input)
{
	this->_type = input._type;
	if (0)
		std::cout << GREEN << "[Cure] assignement constructor called" << std::endl << NO_COLOR;
	return (*this);
}

Cure::~Cure(void)
{
	if (0)
		std::cout << GREEN << "[Cure] destructor called" << std::endl << NO_COLOR;
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
	std::cout << GREEN << "* heals " << target.getName() << "'s wounds *" << std::endl << NO_COLOR;
}

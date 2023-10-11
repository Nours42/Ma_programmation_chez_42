/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:06:10 by nours42           #+#    #+#             */
/*   Updated: 2023/10/10 14:07:40 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	if (0)
		std::cout << BLUE << "[Ice] default constructor called" << std::endl << NO_COLOR;
}

Ice::Ice(std::string const & type) : AMateria(type)
{
	if (0)
		std::cout << BLUE << "[Ice] default constructor called" << std::endl << NO_COLOR;
}

Ice::Ice(Ice const & input) : AMateria("ice_copy")
{
	*this = input;
	if (0)
		std::cout << BLUE << "[Ice] copy constructor called" << std::endl;
}

Ice const & Ice::operator=(Ice const & input)
{
	this->_type = input._type;
	if (0)
		std::cout << BLUE << "[Ice] assignement constructor called" << std::endl << NO_COLOR;
	return (*this);
}

Ice::~Ice(void)
{
	if (0)
		std::cout << BLUE << "[Ice] destructor called" << std::endl << NO_COLOR;
}

std::string const & Ice::getType(void) const
{
	return (this->_type);
}

AMateria *	Ice::clone(void) const
{
	return (new Ice("ice"));
}

void	Ice::use(ICharacter & target)
{
	std::cout << BLUE << "* shoots an ice bolt at " << target.getName() << " *" << std::endl << NO_COLOR;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:35:42 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/20 07:06:11 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	if (DEBUG)
		std::cout << COLOR_BLUE << "[Ice] default constructor called\n" << COLOR_DEFAULT;
}

Ice::Ice(std::string const & type) : AMateria(type)
{
	if (DEBUG)
		std::cout << COLOR_BLUE << "[Ice] default constructor called\n" << COLOR_DEFAULT;
}

Ice::Ice(Ice const & input) : AMateria("ice_copy")
{
	*this = input;
	if (DEBUG)
		std::cout << COLOR_BLUE << "[Ice] copy constructor called\n";
}

Ice const & Ice::operator=(Ice const & input)
{
	this->_type = input._type;
	if (DEBUG)
		std::cout << COLOR_BLUE << "[Ice] assignement constructor called\n" << COLOR_DEFAULT;
	return (*this);
}

Ice::~Ice(void)
{
	if (DEBUG)
		std::cout << COLOR_BLUE << "[Ice] destructor called\n" << COLOR_DEFAULT;
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
	std::cout << COLOR_BLUE << "* shoots an ice bolt at " << target.getName() << " *\n" << COLOR_DEFAULT;
}

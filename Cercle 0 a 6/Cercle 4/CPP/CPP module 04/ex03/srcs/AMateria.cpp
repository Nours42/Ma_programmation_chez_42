/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:06:10 by nours42           #+#    #+#             */
/*   Updated: 2023/10/10 13:46:38 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
	this->_type = type;
	if (0)
		std::cout << WHITE << "[AMateria] type constructor called type= " << type << std::endl << NO_COLOR;
}

AMateria::AMateria(AMateria const & input)
{
	*this = input;
	if (0)
		std::cout << WHITE << "[AMateria] copy constructor called" << std::endl;
}

AMateria const & AMateria::operator=(AMateria const & input)
{
	this->_type = input._type;
	if (0)
		std::cout << WHITE << "[AMateria] assignement constructor called" << std::endl << NO_COLOR;
	return (*this);
}

AMateria::~AMateria(void)
{
	if (0)
		std::cout << WHITE << "[AMateria] destructor called" << std::endl << NO_COLOR;
}

std::string	const & AMateria::getType(void) const
{
	return (this->_type);
}

void	AMateria::use(ICharacter & target)
{
	(void) target;
}

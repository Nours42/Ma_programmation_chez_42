/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:06:10 by nours42           #+#    #+#             */
/*   Updated: 2023/10/09 22:46:50 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ICharacter.hpp"
#include "../includes/Ice.hpp"
#include "../includes/IMateriaSource.hpp"

////////////////////////////////////// CANONICAL FORM ////////////////////////////////////////
																							//
Ice::Ice() : _type("ice")																	//
{																							//	
	std::cout << this->_type << " created" << std::endl;									//
}																							//
																							//
Ice::~Ice()																					//
{																							//
	std::cout << this->_type << " destroyed\n";												//
}																							//
																							//
Ice::Ice(Ice const & ref) : AMateria(ref), _type(ref.getType() + "_copy")					//
{																							//
	std::cout << this->_type << " was created by copy" << std::endl;						//
}																							//
																							//
Ice & Ice::operator=(const Ice & ref)														//
{																							//
	std::cout << "Assigned from " << ref.getType() << std::endl;							//
	return (*this);																			//
}																							//
//////////////////////////////////////////////////////////////////////////////////////////////

std::string const & Ice::getType( void ) const
{
	return (this->_type);
}

Ice *Ice::clone() const
{
	Ice	*ret = new Ice;
	return (ret);
}

void Ice::use(ICharacter& target)
{
	std::string	target_name;

	target_name = target.getName();
	std::cout << " shoot an ice bolt at " << target_name << std::endl;
}

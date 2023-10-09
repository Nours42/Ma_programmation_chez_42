/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:06:10 by nours42           #+#    #+#             */
/*   Updated: 2023/10/09 22:46:16 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ICharacter.hpp"
#include "../includes/Cure.hpp"
#include "../includes/IMateriaSource.hpp"

////////////////////////////////////// CANONICAL FORM ////////////////////////////////////////
																							//
Cure::Cure() : _type("cure")																//
{																							//	
	std::cout << this->_type << " created" << std::endl;									//
}																							//
																							//
Cure::~Cure()																				//
{																							//
	std::cout << this->_type << " destroyed\n";												//
}																							//
																							//
Cure::Cure(Cure const & ref) : AMateria(ref), _type(ref.getType() + "_copy")								//
{																							//
	std::cout << ref._type << " was created by copy" << std::endl;							//
}																							//
																							//
Cure & Cure::operator=(const Cure & ref)													//
{																							//
	std::cout << "Assigned from " << ref.getType() << std::endl;							//
	return (*this);																			//
}																							//
//////////////////////////////////////////////////////////////////////////////////////////////

std::string const & Cure::getType( void ) const
{
	return (this->_type);
}

Cure *Cure::clone() const
{
	Cure	*ret = new Cure;
	return (ret);
}

void Cure::use(ICharacter& target)
{
	std::string	target_name;

	target_name = target.getName();
	std::cout << " heal " << target_name << "\'s wounds" << std::endl;
}

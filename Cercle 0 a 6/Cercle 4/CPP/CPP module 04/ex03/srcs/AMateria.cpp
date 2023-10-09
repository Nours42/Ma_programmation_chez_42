/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:06:10 by nours42           #+#    #+#             */
/*   Updated: 2023/10/09 22:29:36 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

////////////////////////////////////// CANONICAL FORM ////////////////////////////////////////
																							//
AMateria::AMateria()																		//
{																							//	
	std::cout << "Abstract Materia constructor called" << std::endl;						//
}																							//
																							//
AMateria::~AMateria()																		//
{																							//
	std::cout << "Abstract Materia destructor called" << std::endl;							//
}																							//
																							//
AMateria::AMateria(AMateria const & ref) : _type(ref._type)		 							//
{																							//
	std::cout << "Abstract Materia copy constructor called" << std::endl;					//																//
}																							//
																							//
// AMateria & AMateria::operator=(const AMateria & ref)										//
// {																						//
// 	std::cout << "Abstract Materia constructor by operator = called" << std::endl;			//
// 	this->_type = ref.type;																	//
// 	return (*this);																			//
// }																						//
//////////////////////////////////////////////////////////////////////////////////////////////

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Abstract Materia used on " << target.getName() << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "Abstract materia has been constructed" << std::endl;
}
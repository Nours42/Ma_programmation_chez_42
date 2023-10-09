/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:06:10 by nours42           #+#    #+#             */
/*   Updated: 2023/10/09 22:57:38 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ICharacter.hpp"

////////////////////////////////////// CANONICAL FORM ////////////////////////////////////////
																							//
ICharacter::ICharacter()																		//
{																							//	
	std::cout << "Abstract Materia constructor called" << std::endl;						//
}																							//
																							//
ICharacter::~ICharacter()																		//
{																							//
	std::cout << "Abstract Materia destructor called" << std::endl;							//
}																							//
																							//
// IMateriaSource::IMateriaSource(IMateriaSource const & ref)		 							//
// {																							//
// 	std::cout << "Abstract Materia copy constructor called" << std::endl;					//																//
// }																							//
																							//
// IMateriaSource & IMateriaSource::operator=(const IMateriaSource & ref)										//
// {																						//
// 	std::cout << "Abstract Materia constructor by operator = called" << std::endl;			//
// 	this->_type = ref.type;																	//
// 	return (*this);																			//
// }																						//
//////////////////////////////////////////////////////////////////////////////////////////////

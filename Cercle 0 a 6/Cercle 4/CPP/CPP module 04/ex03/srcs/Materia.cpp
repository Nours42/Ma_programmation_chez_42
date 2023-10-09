/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:07:21 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/06 11:34:21 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Materia.hpp"

AMateria::AMateria()
{
	std::cout << "\033[31mAMateria\033[0m constructor called" << std::endl;
	this->type = "\033[31mAMateria\033[0m";
}

AMateria::~AMateria()
{
	std::cout << "\033[31mAMateria\033[0m destructor called" << std::endl;
}

AMateria::AMateria(AMateria & ref)
{
	std::cout << "\033[31mAMateria\033[0m copy constructor called" << std::endl;
	this->type = ref.type;
}

AMateria & AMateria::operator=(const AMateria & rhs)
{
	std::cout << "\033[31mAMateria\033[0m constructor by operator = called" << std::endl;
	this->type = rhs.type;
	return (*this);
}

std::string AMateria::getType( void ) const
{
	return ("My type is " + this->type);
}

AMateria::AMateria clone()
{
	std::cout << "\033[31mAMateria\033[0m is cloned" << std::endl;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "\033[31mAMateria\033[0m make something" << std::endl;
}
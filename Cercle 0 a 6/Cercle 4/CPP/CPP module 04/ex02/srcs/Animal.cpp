/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:07:21 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/06 11:34:21 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

AAnimal::AAnimal()
{
	std::cout << "\033[31mAAnimal\033[0m constructor called" << std::endl;
	this->type = "\033[31mAAnimal\033[0m";
}

AAnimal::~AAnimal()
{
	std::cout << "\033[31mAAnimal\033[0m destructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal & ref)
{
	std::cout << "\033[31mAAnimal\033[0m copy constructor called" << std::endl;
	this->type = ref.type;
}

AAnimal & AAnimal::operator=(const AAnimal & rhs)
{
	std::cout << "\033[31mAAnimal\033[0m constructor by operator = called" << std::endl;
	this->type = rhs.type;
	return (*this);
}

void AAnimal::makeSound( void ) const
{
	std::cout << this->type << " say : What's is the generic Aanimal sound ? birds maybe ?" << std::endl;
}

std::string AAnimal::getType( void ) const
{
	return ("My type is " + this->type);
}
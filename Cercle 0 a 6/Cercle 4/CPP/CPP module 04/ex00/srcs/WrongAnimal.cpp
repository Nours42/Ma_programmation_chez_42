/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:07:21 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/06 07:35:10 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal constructor called" << std::endl;
	this->type = "\033[34mWrongAnimal\033[0m";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal & ref)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	this->type = ref.type;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal & rhs)
{
	std::cout << "WrongAnimal constructor by operator = called" << std::endl;
	this->type = rhs.type;
	return (*this);
}

void WrongAnimal::makeSound( void ) const
{
	std::cout << this->type << " say : i don't know what is the typical animal sound, it's the same for the non animal or the wrong animal sound..." << std::endl;
}

std::string WrongAnimal::getType( void ) const
{
	return ("My type is " + this->type);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:07:21 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/06 11:16:24 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal()
{
	std::cout << "\033[31mAnimal\033[0m constructor called" << std::endl;
	this->type = "\033[31mAnimal\033[0m";
}

Animal::~Animal()
{
	std::cout << "\033[31mAnimal\033[0m destructor called" << std::endl;
}

Animal::Animal(Animal & ref)
{
	std::cout << "\033[31mAnimal\033[0m copy constructor called" << std::endl;
	this->type = ref.type;
}

Animal & Animal::operator=(const Animal & rhs)
{
	std::cout << "\033[31mAnimal\033[0m constructor by operator = called" << std::endl;
	this->type = rhs.type;
	return (*this);
}

void Animal::makeSound( void ) const
{
	std::cout << this->type << " say : What's is the generic animal sound ? birds maybe ?" << std::endl;
}

std::string Animal::getType( void ) const
{
	return ("My type is " + this->type);
}
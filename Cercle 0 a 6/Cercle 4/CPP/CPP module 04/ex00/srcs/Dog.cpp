/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:07:21 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/06 07:35:10 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
	this->type = "\033[33mDog\033[0m";
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(Dog & ref)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = ref.type;
}

Dog & Dog::operator=(const Dog & rhs)
{
	std::cout << "Dog constructor by operator = called" << std::endl;
	this->type = rhs.type;
	return (*this);
}

void Dog::makeSound( void ) const
{
	std::cout << this->type << " say : Meow ... ho... i would say Waf waf waf waf waf ... no i can speak human this is your imagination... Waf" << std::endl;
}

std::string Dog::getType( void ) const
{
	return ("My type is " + this->type);
}
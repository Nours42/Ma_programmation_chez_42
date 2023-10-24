/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:07:21 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/06 11:15:53 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Brain.hpp"

Dog::Dog()
{
	std::cout << "\033[33mDog\033[0m constructor called, now with a brain" << std::endl;
	this->type = "\033[33mDog\033[0m";
	this->brain = new Brain;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "\033[33mDog\033[0m destructor called" << std::endl;
}

Dog::Dog(Dog const & ref)
{
	std::cout << "\033[33mDog\033[0m copy constructor called, now with a brain" << std::endl;
	this->type = ref.getType();
	this->brain = new Brain(*(ref.getBrain()));
}

Dog & Dog::operator=(const Dog & rhs)
{
	std::cout << "\033[33mDog\033[0m constructor by operator = called, now with a brain" << std::endl;
	this->type = rhs.type;
	if (this->brain)
		delete this->brain;
	this->brain = new Brain(*(rhs.getBrain()));
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

Brain	*Dog::getBrain( void ) const
{
	return (this->brain);
}

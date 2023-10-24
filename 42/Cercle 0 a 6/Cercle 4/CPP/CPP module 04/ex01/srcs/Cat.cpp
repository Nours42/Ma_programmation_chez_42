/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:07:21 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/06 11:17:30 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Brain.hpp"

Cat::Cat()
{
	std::cout << "\033[32mCat\033[0m constructor called, now with a brain" << std::endl;
	this->type = "\033[32mCat\033[0m";
	this->brain = new Brain;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "\033[32mCat\033[0m destructor called" << std::endl;
}

Cat::Cat(Cat & ref)
{
	std::cout << "\033[32mCat\033[0m copy constructor called, now with a brain" << std::endl;
	this->type = ref.type;
	this->brain = new Brain(*(ref.getBrain()));
}

Cat & Cat::operator=(const Cat & rhs)
{
	std::cout << "\033[32mCat\033[0m constructor by operator = called, now with a brain" << std::endl;
	this->type = rhs.type;
	if (this->brain)
		delete (this->brain);
	this->brain = new Brain(*(rhs.getBrain()));
	return (*this);
}

void Cat::makeSound( void ) const
{
	std::cout << this->type << " say : Meow meow meooooooooow Meow rrrRRRrrrRRRrrr" << std::endl;
}

std::string Cat::getType( void ) const
{
	return ("My type is " + this->type);
}

Brain	*Cat::getBrain( void ) const
{
	return (this->brain);
}

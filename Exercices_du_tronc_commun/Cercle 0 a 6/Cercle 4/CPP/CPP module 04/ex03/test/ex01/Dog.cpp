/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 09:51:01 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/19 18:41:27 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	_myBrain = new Brain();
	std::cout << COLOR_BLUE << "[Dog] default constructor called\n" << COLOR_DEFAULT;
}

Dog::Dog(Dog const & input) : Animal("Dog_copy")
{
	*this = input;
	this->_type = input._type + "_copy";
	std::cout << COLOR_BLUE << "[Dog] copy constructor called\n" << COLOR_DEFAULT;
}

Dog const & Dog::operator=(Dog const & input)
{
	this->_type = input._type + "assgined";
	this->_myBrain = new Brain(*input._myBrain);
	std::cout << COLOR_BLUE << "[Dog] assignement constructor called\n" << COLOR_DEFAULT;
	return (*this);
}

Dog::~Dog(void)
{
	delete _myBrain;
	std::cout << COLOR_BLUE << "[Dog] destructor called\n" << COLOR_DEFAULT;
}

void	Dog::makeSound(void) const
{
	std::cout << COLOR_BLUE << "[Dog] Woof! Woof!\n" << COLOR_DEFAULT;
}

void	Dog::setIdea(unsigned int index, std::string idea) const
{
	this->_myBrain->setIdea(index, idea);
}

std::string	Dog::getIdea(unsigned int index) const
{
	return (this->_myBrain->getIdea(index));
}

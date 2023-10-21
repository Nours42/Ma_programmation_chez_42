/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 09:51:01 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/19 12:39:40 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << COLOR_BLUE << "[Dog] default constructor called\n" << COLOR_DEFAULT;
}

Dog::Dog(Dog const & input) : Animal("Dog")
{
	*this = input;
	std::cout << COLOR_BLUE << "[Dog] copy constructor called\n";
}

Dog const & Dog::operator=(Dog const & input)
{
	this->_type = input._type;
	std::cout << COLOR_BLUE << "[Dog] assignement constructor called\n" << COLOR_DEFAULT;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << COLOR_BLUE << "[Dog] destructor called\n" << COLOR_DEFAULT;
}

void	Dog::makeSound(void) const
{
	std::cout << COLOR_BLUE << "[Dog] Woof! Woof!\n" << COLOR_DEFAULT;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 09:35:39 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/19 12:51:56 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	this->_type = "Animal";
	std::cout << COLOR_GREEN << "[Animal] default constructor called\n" << COLOR_DEFAULT;
}

Animal::Animal(std::string type)
{
	this->_type = type;
	std::cout << COLOR_GREEN << "[Animal] type constructor called type= " << type << std::endl << COLOR_DEFAULT;
}

Animal::Animal(Animal const & input)
{
	*this = input;
	std::cout << COLOR_GREEN << "[Animal] copy constructor called\n";
}

Animal const & Animal::operator=(Animal const & input)
{
	this->_type = input._type;
	std::cout << COLOR_GREEN << "[Animal] assignement constructor called\n" << COLOR_DEFAULT;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << COLOR_GREEN << "[Animal] destructor called\n" << COLOR_DEFAULT;
}

void	Animal::makeSound(void) const
{
	std::cout << COLOR_GREEN << "[Animal] makeSound default member function called\n" << COLOR_DEFAULT;
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

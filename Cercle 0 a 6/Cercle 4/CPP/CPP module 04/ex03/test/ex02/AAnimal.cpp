/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 09:35:39 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/19 12:51:56 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
	this->_type = "AAnimal";
	std::cout << COLOR_GREEN << "[AAnimal] default constructor called\n" << COLOR_DEFAULT;
}

AAnimal::AAnimal(std::string type)
{
	this->_type = type;
	std::cout << COLOR_GREEN << "[AAnimal] type constructor called type= " << type << std::endl << COLOR_DEFAULT;
}

AAnimal::AAnimal(AAnimal const & input)
{
	*this = input;
	std::cout << COLOR_GREEN << "[AAnimal] copy constructor called\n";
}

AAnimal const & AAnimal::operator=(AAnimal const & input)
{
	this->_type = input._type;
	std::cout << COLOR_GREEN << "[AAnimal] assignement constructor called\n" << COLOR_DEFAULT;
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << COLOR_GREEN << "[AAnimal] destructor called\n" << COLOR_DEFAULT;
}

std::string	AAnimal::getType(void) const
{
	return (this->_type);
}

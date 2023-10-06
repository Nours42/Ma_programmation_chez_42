/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:07:21 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/06 07:35:10 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat constructor called" << std::endl;
	this->type = "\033[35mWrongCat\033[0m";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat & ref)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	this->type = ref.type;
}

WrongCat & WrongCat::operator=(const WrongCat & rhs)
{
	std::cout << "WrongCat constructor by operator = called" << std::endl;
	this->type = rhs.type;
	return (*this);
}

void WrongCat::makeSound( void ) const
{
	std::cout << this->type << " say : Mi a ouuuuuuuuu i'm a werecat... like a werewolf but with furrrRRRrrrr moreee !" << std::endl;
}

std::string WrongCat::getType( void ) const
{
	return ("My type is " + this->type);
}
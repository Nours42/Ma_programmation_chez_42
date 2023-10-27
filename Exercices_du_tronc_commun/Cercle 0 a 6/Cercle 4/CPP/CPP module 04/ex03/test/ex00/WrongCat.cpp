/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 09:56:21 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/19 09:56:25 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << COLOR_MAGENTA << "[WrongCat] default constructor called\n" << COLOR_DEFAULT;
}

WrongCat::WrongCat(WrongCat const & input) : WrongAnimal("Cat")
{
	*this = input;
	std::cout << COLOR_MAGENTA << "[WrongCat] copy constructor called\n";
}

WrongCat const & WrongCat::operator=(WrongCat const & input)
{
	this->_type = input._type;
	std::cout << COLOR_MAGENTA << "[WrongCat] assignement constructor called\n" << COLOR_DEFAULT;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << COLOR_MAGENTA << "[WrongCat] destructor called\n" << COLOR_DEFAULT;
}

void	WrongCat::makeSound(void) const
{
	std::cout << COLOR_MAGENTA << "[WrongCat] Moew Moew\n" << COLOR_DEFAULT;
}

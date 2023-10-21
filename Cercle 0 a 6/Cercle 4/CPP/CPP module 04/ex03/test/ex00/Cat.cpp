/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 09:47:02 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/19 12:39:23 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << COLOR_YELLOW << "[Cat] default constructor called\n" << COLOR_DEFAULT;
}

Cat::Cat(Cat const & input) : Animal("Cat")
{
	*this = input;
	std::cout << COLOR_YELLOW << "[Cat] copy constructor called\n";
}

Cat const & Cat::operator=(Cat const & input)
{
	this->_type = input._type;
	std::cout << COLOR_YELLOW << "[Cat] assignement constructor called\n" << COLOR_DEFAULT;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << COLOR_YELLOW << "[Cat] destructor called\n" << COLOR_DEFAULT;
}

void	Cat::makeSound(void) const
{
	std::cout << COLOR_YELLOW << "[Cat] Moew Moew\n" << COLOR_DEFAULT;
}

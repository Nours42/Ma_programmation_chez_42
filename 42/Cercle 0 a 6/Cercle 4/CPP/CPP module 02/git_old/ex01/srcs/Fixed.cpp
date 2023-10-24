/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:22:06 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/03 17:09:37 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

// copie du log du sujet :

// Default constructor called
// Copy constructor called
// Copy assignment operator called // <-- This line may be missing depending on your implementation
// getRawBits member function called
// Default constructor called
// Copy assignment operator called
// getRawBits member function called
// getRawBits member function called
// 0
// getRawBits member function called
// 0
// getRawBits member function called
// 0
// Destructor called
// Destructor called
// Destructor called

int	Fixed::getRawBits( void) const
{
	return (this->fixed_point_value);
}

void	Fixed::setRawBits( int const raw )
{
	this->fixed_point_value = raw;
}

Fixed::Fixed()
{
	this->fixed_point_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed & Fixed::operator=( Fixed const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	setRawBits(rhs.getRawBits());
	return (*this);
}

// ex01

Fixed::Fixed(int int_arg)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(int_arg << this->n_fract_bits);
}

Fixed::Fixed(float float_arg)
{
	std::cout << "Float constructor called" << std::endl;
	setRawBits((int)roundf(float_arg * (1 << this->n_fract_bits)));
}

float	Fixed::toFloat(void) const
{
	float	f;

	f = (float)this->getRawBits() / (1 << this->n_fract_bits);
	return (f);
}

int		Fixed::toInt(void) const
{
	return (this->getRawBits() >> this->n_fract_bits);
}

std::ostream & operator<<( std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();

	return (o);
}

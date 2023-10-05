/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:18:09 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/03 17:16:53 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

// CANONIC FORM
// Class containing at least:
// 1) Constructor default
// 2) Copy constructor
// 3) '=' Operator overload
// 4) Destructor (virtual!)

class	Fixed
{
	public:
		Fixed();
		~Fixed();
		
		// A copy constructor
		// A constructor which allows to create a copy of a different instance
		Fixed(Fixed const & src);

		// Operator '=' overload
		// rhs = right hand side, a constant reference to our oject instance
		// not a const function because our instance will be modified (ex: a = 14)
		// Returns a reference to allow us to do "a = b = c = d"
		Fixed & operator=( Fixed const & rhs);
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		

		// ex01
		Fixed(int const int_arg);
		Fixed(float const float_arg);

		float toFloat(void) const;
		int toInt(void) const;

	private:
		int	fixed_point_value;
		static const int n_fract_bits = 8;
};

std::ostream & operator<<( std::ostream & o, Fixed const & rhs);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:14:36 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/16 13:54:08 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <ctype.h>
# include <stdlib.h>
# include <exception>
# include <iostream>
# include <string>
# include <limits>

# include "OutputConverter.hpp"

enum e_type { NAN, POS_INF, NEG_INF, CHAR, INT, FLOAT, DOUBLE };

class ScalarConverter
{
	private:

		char	_toChar(std::string const& literal);
		int		_toInt(std::string const& literal);
		float	_toFloat(std::string const& literal);
		double	_toDouble(std::string const& literal);
		ScalarConverter& operator=(ScalarConverter const& rhs);
		

	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter const& src);
		~ScalarConverter();
		void convert(std::string const& literal);
		void displayError(int errCode);

		// Exceptions
		class ImpossibleConversionException : public std::exception
		{
			virtual const char* what() const throw() { return "impossible"; }
		};

		class NonDisplayableException : public std::exception
		{
			virtual const char* what() const throw() { return "Non displayable"; }
		};

		// Validation class
		struct Validation
		{
			public:
				static int	_getInputType(std::string const& literal);
				static bool	_isNaN(std::string const& literal);
				static bool	_isNegInf(std::string const& literal);
				static bool	_isPosInf(std::string const& literal);
				static bool	_isChar(std::string const& literal);
				static bool	_isInt(std::string const& literal);
				static bool	_isFloat(std::string const& literal);
				static bool	_isDouble(std::string const& literal);

			// Exceptions
			class InvalidInputException : public std::exception
			{
				virtual const char* what() const throw() {return "Invalid input. It must be a char, int, float or double.";}
			};
		};
};

#endif
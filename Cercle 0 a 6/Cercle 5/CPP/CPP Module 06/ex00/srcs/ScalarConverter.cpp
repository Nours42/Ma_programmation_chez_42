/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:14:41 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/16 09:44:55 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

char	ScalarConverter::_toChar(std::string const& literal) 
{
	char c;

	try
	{
		c = static_cast<char>(literal[0]);
	}
	catch (std::exception& e)
	{
		throw ImpossibleConversionException();
	}
	if (isdigit(c) || c <= 32 || c > 126)
	{
		throw NonDisplayableException();
	}
	return (c);
}

int ScalarConverter::_toInt(std::string const& literal)
{
	int nbr;

	if (literal.length() == 1 && !std::isdigit(literal[0]))
	{
		return static_cast<int>(literal[0]);
	}
	try
	{
		nbr = std::atoi(literal.c_str());
	}

	catch (std::exception& e)
	{
		throw ImpossibleConversionException();
	}
	return (nbr);
}

float ScalarConverter::_toFloat(std::string const& literal)
{
	if (Validation::_isNaN(literal))
	{
		return std::numeric_limits<float>::quiet_NaN();
	}
	if (Validation::_isNegInf(literal))
	{
		return std::numeric_limits<float>::infinity();
	}
	try
	{
		return std::atof(literal.c_str());
	}
	catch (std::exception& e)
	{
		throw ImpossibleConversionException();
	}
}

double ScalarConverter::_toDouble(std::string const& literal)
{
	if (Validation::_isNaN(literal))
	{
		return std::numeric_limits<double>::quiet_NaN();
	}
	if (Validation::_isNegInf(literal))
	{
		return std::numeric_limits<double>::infinity();
	}
	try
	{
		return std::strtod(literal.c_str(), NULL);
	}
	catch (std::exception& e)
	{
		throw ImpossibleConversionException();
	}
}

bool	ScalarConverter::Validation::_isNegInf(std::string const& literal)
{
	if (literal == "-inf" || literal == "-inff")
	{
		return true;
	}
	return false;
}

bool	ScalarConverter::Validation::_isPosInf(std::string const& literal)
{
	if (literal == "+inf" || literal == "+inff")
	{
		return true;
	}
	return false;
}

bool	ScalarConverter::Validation::_isNaN(std::string const& literal)
{
	if (literal == "nan" || literal == "nanf")
	{
		return true;
	}
	return false;
}

int ScalarConverter::Validation::_getInputType(std::string const& literal)
{
	int type = -1;

	if (_isNaN(literal))
	{
		return (NAN);
	}
	else if (_isNegInf(literal))
	{
		return (POS_INF);
	}
	else if (_isPosInf(literal))
	{
		return (NEG_INF);
	}
	else if (_isDouble(literal))
	{
		return (DOUBLE);
	}
	else if (_isFloat(literal))
	{
		return (FLOAT);
	}
	else if (_isInt(literal))
	{
		return (INT);
	}
	else if (_isChar(literal))
	{
		return (CHAR);
	}
	return (type);
}

bool	ScalarConverter::Validation::_isChar(std::string const& literal)
{
	if (_isNaN(literal) || _isNegInf(literal))
	{
		return true;
	}
	if (literal.length() == 1 && !isdigit(literal[0]))
	{
		return true;
	}
	return false;
}

bool	ScalarConverter::Validation::_isInt(std::string const& literal)
{
	for (size_t i = 0; i < literal.length(); i++)
	{
		if (!isdigit(literal[i]))
		{
		return false;
		}
	}
	return true;
}

bool	ScalarConverter::Validation::_isFloat(std::string const& literal)
{
	size_t idx = 0;
	size_t len = literal.length();
	size_t manyDots = 0;

	if (literal[len - 1] != 'f')
	{
		return false;
	}
	if (literal[idx] == '+' || literal[idx] == '-')
	{
		idx++;
	}
	while (idx < len - 1)
	{
		if (literal[idx] == '.')
		{
		manyDots++;
		}
		else if (!isdigit(literal[idx]) || manyDots > 1)
		{
		return false;
		}
		idx++;
	}
	return true;
}

bool	ScalarConverter::Validation::_isDouble(std::string const& literal)
{
	size_t idx = 0;
	size_t len = literal.length();
	size_t manyDots = 0;

	if (literal[idx] == '+' || literal[idx] == '-')
	{
		idx++;
	}
	while (idx < len)
	{
		if (literal[idx] == '.')
		{
		manyDots++;
		}
		else if (!isdigit(literal[idx]) || manyDots > 1)
		{
		return false;
		}
		idx++;
	}
	return true;
}

void ScalarConverter::convert(std::string const& literal)
{
	int type = Validation::_getInputType(literal);

	switch (type)
	{
		case NAN:
		displayError(NAN);
		break;
		case POS_INF:
		displayError(POS_INF);
		break;
		case NEG_INF:
		displayError(NEG_INF);
		break;
		case CHAR:
		OutputConverter(_toChar(literal));
		break;
		case INT:
		OutputConverter(_toInt(literal));
		break;
		case FLOAT:
		OutputConverter(_toFloat(literal));
		break;
		case DOUBLE:
		OutputConverter(_toDouble(literal));
		break;
		default:
		throw Validation::InvalidInputException();
		break;
	}
}

void ScalarConverter::displayError(int errCode)
{
	if (errCode == NAN)
	{
		std::cerr << "char: impossible" << std::endl;
		std::cerr << "int: impossible" << std::endl;
		std::cerr << "float: nanf" << std::endl;
		std::cerr << "double: nan" << std::endl;
		return;
	}
	else if (errCode == POS_INF)
	{
		std::cerr << "char: impossible" << std::endl;
		std::cerr << "int: impossible" << std::endl;
		std::cerr << "float: inff" << std::endl;
		std::cerr << "double: inf" << std::endl;
		return;
	}
	else if (errCode == NEG_INF)
	{
		std::cerr << "char: impossible" << std::endl;
		std::cerr << "int: impossible" << std::endl;
		std::cerr << "float: -inff" << std::endl;
		std::cerr << "double: -inf" << std::endl;
		return;
	}
}
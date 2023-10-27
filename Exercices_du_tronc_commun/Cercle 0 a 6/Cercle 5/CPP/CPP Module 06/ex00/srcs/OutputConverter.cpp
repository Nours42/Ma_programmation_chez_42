/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OutputConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:56:28 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/16 13:54:18 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OutputConverter.hpp"

OutputConverter::OutputConverter(char const& conversion)
{
	try
	{
		std::cout << "char: '" << static_cast<char>(conversion) << "'" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "char: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "int: " << static_cast<int>(conversion) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "int: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "float: " << std::fixed << std::setprecision(1)
				<< static_cast<float>(conversion) << "f" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "float: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "double: " << std::fixed << std::setprecision(1)
				<< static_cast<double>(conversion) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "double: " << e.what() << std::endl;
	}
}

OutputConverter::OutputConverter(int const& conversion)
{
	try
	{
		if (conversion >=0 && conversion <= 9)
		{
		throw ScalarConverter::NonDisplayableException();
		}
		std::cout << "char: '" << static_cast<char>(conversion) << "'" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "char: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "int: " << static_cast<int>(conversion) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "int: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "float: " << std::fixed << std::setprecision(1)
				<< static_cast<float>(conversion) << "f" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "float: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "double: " << std::fixed << std::setprecision(1)
				<< static_cast<double>(conversion) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "double: " << e.what() << std::endl;
	}
}

OutputConverter::OutputConverter(float const& conversion)
{
	try
	{
		if (conversion == 0)
		{
		throw ScalarConverter::NonDisplayableException();
		}
		std::cout << "char: '" << static_cast<char>(conversion) << "'" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "char: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "int: " << static_cast<int>(conversion) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "int: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "float: " << std::fixed << std::setprecision(1)
				<< static_cast<float>(conversion) << "f" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "float: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "double: " << std::fixed << std::setprecision(1)
				<< static_cast<double>(conversion) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "double: " << e.what() << std::endl;
	}
}

OutputConverter::OutputConverter(double const& conversion)
{
	try
	{
		if (conversion == 0)
		{
		throw ScalarConverter::NonDisplayableException();
		}
		std::cout << "char: '" << static_cast<char>(conversion) << "'" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "char: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "int: " << static_cast<int>(conversion) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "int: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "float: " << std::fixed << std::setprecision(1)
				<< static_cast<float>(conversion) << "f" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "float: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "double: " << std::fixed << std::setprecision(1)
				<< static_cast<double>(conversion) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "double: " << e.what() << std::endl;
	}
}

OutputConverter::~OutputConverter() {}

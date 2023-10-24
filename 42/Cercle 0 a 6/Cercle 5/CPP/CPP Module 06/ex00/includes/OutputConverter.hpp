/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OutputConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:44:39 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/16 13:54:11 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUTCONVERTER_HPP
#define OUTPUTCONVERTER_HPP

#include <iomanip>
#include <iostream>
#include <string>

#include "ScalarConverter.hpp"

class OutputConverter
{
	private:

		OutputConverter();
		OutputConverter(OutputConverter const& src);

	public:
		
		OutputConverter(char const& c);
		OutputConverter(int const& c);
		OutputConverter(float const& c);
		OutputConverter(double const& c);
		~OutputConverter();

		OutputConverter& operator=(OutputConverter const& rhs);
};

#endif
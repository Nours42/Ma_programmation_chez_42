/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:15:44 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/21 13:15:46 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <vector>
#include <sstream>
#include "User.hpp"

namespace Utils
{
	std::vector<std::string> str_split(std::string str, std::string delimiters);

	std::vector<std::string> str_parse(std::string str);

	std::string str_ltrim(std::string str, const char* charset);
	std::string str_rtrim(std::string str, const char* charset);
	std::string str_trim(std::string str, const char* charset);

	std::string str_toupper(std::string str);
	std::string str_tolower(std::string str);
	int			stoi( std::string & s );

	template<typename T>
	std::string to_string(const T & value);
}


#endif

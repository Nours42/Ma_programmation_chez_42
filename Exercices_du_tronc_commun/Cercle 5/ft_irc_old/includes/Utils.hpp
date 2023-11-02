/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:38:07 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/02 11:45:33 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <vector>
# include <sstream>
# include "User.hpp"

namespace Utils
{
		std::vector<std::string> str_split(std::string str, std::string delimiters);
		std::vector<std::string> str_parse(std::string str);
		std::string str_ltrim(std::string str, const char* charset);
		std::string str_rtrim(std::string str, const char* charset);
		std::string str_trim(std::string str, const char* charset);
		std::string str_toupper(std::string str);
		std::string str_tolower(std::string str);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:38:07 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/07 11:36:41 by sdestann         ###   ########.fr       */
=======
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:36:34 by nours42          #+#    #+#             */
/*   Updated: 2023/11/18 18:31:28 by nours42          ###   ########.fr       */
>>>>>>> 80cc973 (ft_irc)
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

<<<<<<< HEAD
=======
#include <iostream>
#include <vector>
#include <sstream>
#include "User.hpp"

>>>>>>> 80cc973 (ft_irc)
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

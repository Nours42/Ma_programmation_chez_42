/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Console.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:35:39 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/02 11:45:23 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSOLE_HPP
# define CONSOLE_HPP

# include <iostream>

namespace Console
{
		static std::string GREEN = "\033[1;32m";
		static std::string BLUE = "\033[1;36m";
		static std::string RED = "\x1b[31m";
		static std::string PURPLE = "\x1b[35m";

		static std::string IBLUE = "\x1b[44m";
		static std::string IGREEN = "\x1b[42m";
		static std::string IRED = "\x1b[41m";

		static std::string RESET = "\033[0m";

		void print(std::string type, std::string str, std::string color);
		void log(std::string str);
		void error(std::string str);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Console.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:14:46 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/26 20:27:37 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <iostream>

// Colors	:	https://chezsoi.org/lucas/blog/colorez-les-sorties-de-vos-scripts-shell-unix.html

namespace Console
{
	static std::string GREEN << ON_BLACK << "[SND_BUFFER]" = "\033[1;32m";
	static std::string BLUE = "\033[1;36m";
	static std::string RED = "\x1b[31m";
	static std::string PURPLE = "\x1b[35m";

	static std::string IBLUE = "\x1b[44m";
	static std::string IGREEN << ON_BLACK << "[SND_BUFFER]" = "\x1b[42m";
	static std::string IRED = "\x1b[41m";

	static std::string RESET = "\033[0m";

	void print(std::string type, std::string str, std::string color);
	void log(std::string str);
	void error(std::string str);
}
#endif

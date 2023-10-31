/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:32:01 by nours42           #+#    #+#             */
/*   Updated: 2023/10/31 15:20:01 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP

# include <iostream>
# include <vector>
# include "Console.hpp"
# include "Utils.hpp"
# include "User.hpp"
# include "Message.hpp"

class	Command
{
	private:
		
		// Command(Command const &ref);					//no used
		// Command &operator=(Command const &ref);		//no used
		
	protected:
	public:

		// Command();									//no used
		virtual ~Command(void) {}
		virtual bool onCommand(User* sender, std::vector<std::string> args) = 0;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrivmsgCommand.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:16:53 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/21 13:16:54 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVMSGCOMMAND_HPP
#define PRIVMSGCOMMAND_HPP

#include "Command.hpp"
#include "Server.hpp"

class PrivmsgCommand : public Command
{
	protected:
		Server* _server;
	public:
		PrivmsgCommand(Server* _server);
		~PrivmsgCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QuitCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:17:10 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/21 13:17:11 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUITCOMMAND_HPP
#define QUITCOMMAND_HPP

#include "Command.hpp"
#include "Server.hpp"
#include <map>

class QuitCommand : public Command
{
	private:
		Server* _server;
	public:
		QuitCommand(Server* server);
		~QuitCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
};

#endif


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModeCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:16:10 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/21 13:16:12 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODECOMMAND_HPP
#define MODECOMMAND_HPP

#include "Command.hpp"
#include "Server.hpp"
#include "Channel.hpp"

class ModeCommand : public Command
{
	protected:
		Server		*_server;

	public:
		ModeCommand(Server *server);
		~ModeCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
};

#endif

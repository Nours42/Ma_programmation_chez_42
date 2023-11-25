/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InviteCommand.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:15:58 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/21 13:16:00 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INVITECOMMAND_HPP
#define INVITECOMMAND_HPP

#include "Command.hpp"
#include "Server.hpp"
#include "Channel.hpp"

class InviteCommand : public Command
{
	protected:
		Server		*_server;

	public:
		InviteCommand(Server *sever);
		~InviteCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
};

#endif

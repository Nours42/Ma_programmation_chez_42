/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MotdCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:16:32 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/21 13:16:34 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOTDCOMMAND_HPP
#define MOTDCOMMAND_HPP

#include "Command.hpp"
#include "Server.hpp"
#include "Channel.hpp"

class MotdCommand : public Command
{
	protected:
		Server		*_server;

	public:
		MotdCommand(Server* sever);
		~MotdCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
};

#endif

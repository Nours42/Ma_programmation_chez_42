/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PingCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:18:57 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/21 13:18:58 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "Console.hpp"
#include "cmds/PingCommand.hpp"

PingCommand::PingCommand(void) {}
PingCommand::~PingCommand(void) {}

bool PingCommand::onCommand(User* sender, std::vector<std::string> args)
{
	(void) args;
	return sender->sendRawMessage("PONG :ft_irc");
}

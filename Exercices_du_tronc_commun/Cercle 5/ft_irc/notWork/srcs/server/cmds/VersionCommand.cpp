/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VersionCommand.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:13:05 by nours42          #+#    #+#             */
/*   Updated: 2023/11/18 18:29:53 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "cmds/VersionCommand.hpp"
#include "Console.hpp"
#include "Message.hpp"

VersionCommand::VersionCommand(Server *server) : _server(server) {};
VersionCommand::~VersionCommand(void) {}

bool	VersionCommand::onCommand(User *sender, std::vector<std::string> args)
{
	(void) args;

	if (!sender->isConnected())
		return !sender->sendMessage(ERR_NOTREGISTERED, ":You have not registered");

	sender->sendMessage(RPL_VERSION, _server->getVersion() + " ft_irc :" + _server->getVersionComments());
	return (true);
}

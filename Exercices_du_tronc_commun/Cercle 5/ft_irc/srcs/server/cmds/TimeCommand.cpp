/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:56:59 by nours42           #+#    #+#             */
/*   Updated: 2023/11/01 14:57:00 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "cmds/TimeCommand.hpp"
#include "Console.hpp"
#include "Message.hpp"

#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>

TimeCommand::TimeCommand(Server *server) : _server(server) {};
TimeCommand::~TimeCommand(void) {}

bool	TimeCommand::onCommand(User *sender, std::vector<std::string> args)
{
	(void) args;

	if (!sender->isConnected())
		return !sender->sendMessage(ERR_NOTREGISTERED, ":You have not registered");

	time_t t = std::time(nullptr);
	std::stringstream ss;
	ss << std::put_time(std::localtime(&t), "%A %d %B of %Y at %H:%M:%S");

	sender->sendMessage(RPL_TIME, "ft_irc :" + ss.str());
	return (true);
}

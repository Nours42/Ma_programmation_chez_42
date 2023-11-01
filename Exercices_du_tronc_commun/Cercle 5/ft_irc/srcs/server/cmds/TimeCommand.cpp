/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:56:59 by nours42           #+#    #+#             */
/*   Updated: 2023/11/01 16:46:09 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../../includes/cmds/TimeCommand.hpp"
#include "Console.hpp"
#include "Message.hpp"

#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <vector>

TimeCommand::TimeCommand(Server *server) : _server(server) {};
TimeCommand::~TimeCommand(void) {}

bool TimeCommand::onCommand(User *sender, std::vector<std::string> args)
{
    (void) args;

    if (!sender->isConnected())
    {
        sender->sendMessage(ERR_NOTREGISTERED, ":You have not registered");
        return false;
    }

    time_t rawTime;
    struct tm *timeInfo;
    char buffer[80];

    time(&rawTime);
    timeInfo = localtime(&rawTime);

    strftime(buffer, sizeof(buffer), "%A %d %B of %Y at %H:%M:%S", timeInfo);

    std::string response = "ft_irc: ";
    response += buffer;

    sender->sendMessage(RPL_TIME, response);
    return true;
}


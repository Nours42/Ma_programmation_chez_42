/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:12:55 by nours42          #+#    #+#             */
/*   Updated: 2023/11/18 18:29:57 by nours42          ###   ########.fr       */
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

// bool	TimeCommand::onCommand(User *sender, std::vector<std::string> args)
// {
// 	(void) args;

// 	if (!sender->isConnected())
// 		return !sender->sendMessage(ERR_NOTREGISTERED, ":You have not registered");

// 	time_t t = std::time(NULL);
// 	std::stringstream ss;
// 	ss << std::put_time(std::localtime(&t), "%A %d %B of %Y at %H:%M:%S");

// 	sender->sendMessage(RPL_TIME, "ft_irc :" + ss.str());
// 	return (true);
// }

bool TimeCommand::onCommand(User *sender, std::vector<std::string> args)
{
        (void)args;

        if (!sender->isConnected())
            return !sender->sendMessage(ERR_NOTREGISTERED, ":You have not registered");

        time_t currentTime = std::time(NULL);
        struct tm *localTime = std::localtime(&currentTime);
        char formattedTime[100]; // Taille arbitraire pour le buffer

        // Formater le temps avec strftime
        std::strftime(formattedTime, sizeof(formattedTime), "%A %d %B of %Y at %H:%M:%S", localTime);

        sender->sendMessage(RPL_TIME, "ft_irc :" + std::string(formattedTime));
        return true;
    }

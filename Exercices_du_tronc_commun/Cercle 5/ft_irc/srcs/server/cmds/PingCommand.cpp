/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PingCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:58:05 by nours42          #+#    #+#             */
/*   Updated: 2023/11/18 18:30:00 by nours42          ###   ########.fr       */
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

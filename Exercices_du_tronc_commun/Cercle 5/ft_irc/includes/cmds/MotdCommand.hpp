/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MotdCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:57:51 by nours42          #+#    #+#             */
/*   Updated: 2023/11/18 18:32:20 by nours42          ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InviteCommand.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:57:42 by nours42          #+#    #+#             */
/*   Updated: 2023/11/18 18:32:26 by nours42          ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModeCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:34:42 by nours42          #+#    #+#             */
/*   Updated: 2023/11/18 18:32:21 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODECOMMAND_HPP
#define MODECOMMAND_HPP

#include "Command.hpp"
#include "Server.hpp"
#include "Channel.hpp"

class ModeCommand : public Command
{
	protected:
		Server		*_server;

	public:
		ModeCommand(Server *server);
		~ModeCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
};

#endif

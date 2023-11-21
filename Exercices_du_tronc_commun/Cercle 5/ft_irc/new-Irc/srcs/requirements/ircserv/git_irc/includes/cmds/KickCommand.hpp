/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KickCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:32:49 by nours42           #+#    #+#             */
/*   Updated: 2023/11/18 18:32:50 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KICKCOMMAND_HPP
#define KICKCOMMAND_HPP

#include "Command.hpp"
#include "Server.hpp"
#include "Utils.hpp"

class KickCommand : public Command
{
	protected:
		Server*	_server;
	
	public:
		KickCommand(Server* sever);
		~KickCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PassCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:52:54 by nours42          #+#    #+#             */
/*   Updated: 2023/11/18 18:32:14 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PASSCOMMAND_HPP
#define PASSCOMMAND_HPP

#include "Command.hpp"

class Server;

class PassCommand : public Command
{
	protected:
		Server*	_server;
	public:
		PassCommand(Server* server);
		~PassCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
};

#endif

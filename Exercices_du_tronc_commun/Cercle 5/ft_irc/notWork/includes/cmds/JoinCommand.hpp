/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JoinCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:23:56 by nours42          #+#    #+#             */
/*   Updated: 2023/11/18 18:32:25 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOINCOMMAND_HPP
#define JOINCOMMAND_HPP

#include "Command.hpp"
#include "Server.hpp"

class JoinCommand : public Command
{
	protected:
		Server*	_server;
	public:
		JoinCommand(Server* sever);
		~JoinCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
};

#endif

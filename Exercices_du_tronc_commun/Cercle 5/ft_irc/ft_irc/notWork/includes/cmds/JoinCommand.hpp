/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JoinCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:16:17 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/21 13:21:06 by sdestann         ###   ########.fr       */
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

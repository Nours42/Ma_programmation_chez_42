/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PassCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:16:39 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/21 13:16:41 by sdestann         ###   ########.fr       */
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

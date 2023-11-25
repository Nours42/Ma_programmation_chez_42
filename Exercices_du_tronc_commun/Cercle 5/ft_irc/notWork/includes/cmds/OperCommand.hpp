/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:16:46 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/21 13:16:48 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERCOMMAND_HPP
#define OPERCOMMAND_HPP

#include "Command.hpp"
#include "Server.hpp"
#include "Channel.hpp"

class OperCommand : public Command
{
	protected:
		Server		*_server;

	public:
		OperCommand(Server* sever);
		~OperCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
};

#endif

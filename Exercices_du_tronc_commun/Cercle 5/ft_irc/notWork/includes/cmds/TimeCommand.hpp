/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:17:04 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/21 13:17:06 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMECOMMAND_HPP
#define TIMECOMMAND_HPP

#include "Command.hpp"
#include "Server.hpp"
#include "Channel.hpp"

class TimeCommand : public Command
{
	protected:
		Server		*_server;

	public:
		TimeCommand(Server* sever);
		~TimeCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
};

#endif

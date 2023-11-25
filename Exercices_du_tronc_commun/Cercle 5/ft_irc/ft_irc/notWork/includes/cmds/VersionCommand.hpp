/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VersionCommand.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:17:48 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/21 13:17:50 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERSIONCOMMAND_HPP
#define VERSIONCOMMAND_HPP

#include "Command.hpp"
#include "Server.hpp"
#include "Channel.hpp"

class VersionCommand : public Command
{
	protected:
		Server		*_server;

	public:
		VersionCommand(Server* sever);
		~VersionCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
};

#endif

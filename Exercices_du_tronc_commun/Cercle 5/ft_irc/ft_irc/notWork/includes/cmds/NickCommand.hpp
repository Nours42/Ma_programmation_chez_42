/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NickCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:16:25 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/21 13:16:27 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NICKCOMMAND_HPP
#define NICKCOMMAND_HPP

#include "Command.hpp"
#include "Server.hpp"
#include "Channel.hpp"

class NickCommand : public Command
{
	protected:
		Server		*_server;
		
	public:
		NickCommand(Server* server);
		~NickCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
};

#endif


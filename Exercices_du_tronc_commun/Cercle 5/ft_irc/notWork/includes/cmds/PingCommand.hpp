/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PingCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:16:58 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/21 13:17:00 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PINGCOMMAND_HPP
#define PINGCOMMAND_HPP

#include "Command.hpp"
#include "Server.hpp"
#include "Channel.hpp"

class PingCommand : public Command
{
	public:
		PingCommand(void);
		~PingCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
};

#endif

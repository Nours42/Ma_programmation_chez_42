/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TopicCommand.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:17:24 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/21 13:17:26 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOPICCOMMAND_HPP
#define TOPICCOMMAND_HPP

#include "Command.hpp"
#include "Server.hpp"
#include "Channel.hpp"

class TopicCommand : public Command
{
	protected:
		Server		*_server;

	public:
		TopicCommand(Server* sever);
		~TopicCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
};

#endif

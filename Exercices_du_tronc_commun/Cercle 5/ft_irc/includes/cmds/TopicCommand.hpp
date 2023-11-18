/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TopicCommand.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:58:14 by nours42          #+#    #+#             */
/*   Updated: 2023/11/18 18:32:08 by nours42          ###   ########.fr       */
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

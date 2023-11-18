/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:58:08 by nours42          #+#    #+#             */
/*   Updated: 2023/11/18 18:32:09 by nours42          ###   ########.fr       */
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

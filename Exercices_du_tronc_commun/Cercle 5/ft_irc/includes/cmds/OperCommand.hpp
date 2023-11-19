/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:57:21 by nours42          #+#    #+#             */
/*   Updated: 2023/11/18 18:32:16 by nours42          ###   ########.fr       */
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

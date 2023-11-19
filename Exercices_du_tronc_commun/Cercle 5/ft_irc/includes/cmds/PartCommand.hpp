/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PartCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:23:56 by nours42          #+#    #+#             */
/*   Updated: 2023/11/18 18:32:15 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARTCOMMAND_HPP
#define PARTCOMMAND_HPP

#include "Command.hpp"
#include "Server.hpp"

class PartCommand : public Command
{
	private:
		Server* _server;
	public:
		PartCommand(Server* server);
		~PartCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
};

#endif


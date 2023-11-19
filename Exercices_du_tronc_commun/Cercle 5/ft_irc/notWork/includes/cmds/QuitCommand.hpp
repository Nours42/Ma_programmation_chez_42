/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QuitCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:23:56 by nours42          #+#    #+#             */
/*   Updated: 2023/11/18 18:32:10 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUITCOMMAND_HPP
#define QUITCOMMAND_HPP

#include "Command.hpp"
#include "Server.hpp"
#include <map>

class QuitCommand : public Command
{
	private:
		Server* _server;
	public:
		QuitCommand(Server* server);
		~QuitCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
};

#endif


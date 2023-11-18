/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NamesCommand.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:32:32 by nours42           #+#    #+#             */
/*   Updated: 2023/11/18 18:32:38 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAMESCOMMAND_HPP
#define NAMESCOMMAND_HPP

#include "Command.hpp"

class Server;

class NamesCommand : public Command
{
	protected:
		Server*	_server;
	public:
		NamesCommand(Server* server);
		~NamesCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
};

#endif

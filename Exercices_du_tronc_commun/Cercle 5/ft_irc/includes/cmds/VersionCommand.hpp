/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VersionCommand.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:58:21 by nours42          #+#    #+#             */
/*   Updated: 2023/11/18 18:32:02 by nours42          ###   ########.fr       */
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

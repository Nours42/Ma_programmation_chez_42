/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:32:41 by nours42           #+#    #+#             */
/*   Updated: 2023/11/18 18:32:46 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTCOMMAND_HPP
#define LISTCOMMAND_HPP

#include "Command.hpp"
#include "Server.hpp"
#include "Channel.hpp"

class ListCommand : public Command
{
	protected:
		Server		*_server;

	public:
		ListCommand(Server *sever);
		~ListCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
};

#endif

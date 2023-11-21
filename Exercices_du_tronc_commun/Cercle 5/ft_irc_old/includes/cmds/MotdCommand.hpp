/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MotdCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:44:00 by nours42           #+#    #+#             */
/*   Updated: 2023/11/15 18:06:27 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOTDCOMMAND_HPP
# define MOTDCOMMAND_HPP

# include "Command.hpp"
# include "../Server.hpp"
# include "../Channel.hpp"

class Server;

class MotdCommand : public Command
{
	private :

		// MotdCommand(MotdCommand const &ref);				//no used
		// MotdCommand &operator=(MotdCommand const &ref);		//no used

	protected:

		Server		*_server;

	public:

		MotdCommand(Server* server);
		~MotdCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
		
};

#endif
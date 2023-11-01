/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PingCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:48:17 by nours42           #+#    #+#             */
/*   Updated: 2023/11/01 14:48:34 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PINGCOMMAND_HPP
# define PINGCOMMAND_HPP

# include "Command.hpp"
# include "Server.hpp"
# include "Channel.hpp"

class PingCommand : public Command
{
	private :

		// PingCommand(PingCommand const &ref);				//no used
		// PingCommand &operator=(PingCommand const &ref);		//no used

	protected:

		Server		*_server;

	public:

		PingCommand(Server* server);
		~PingCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
		
};

#endif
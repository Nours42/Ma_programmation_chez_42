/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrivmsgCommand.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:49:00 by nours42           #+#    #+#             */
/*   Updated: 2023/11/01 16:45:33 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVMSGCOMMAND_HPP
# define PRIVMSGCOMMAND_HPP

# include "Command.hpp"
# include "../Server.hpp"
# include "../Channel.hpp"

class PrivmsgCommand : public Command
{
	private :

		// PrivmsgCommand(PrivmsgCommand const &ref);				//no used
		// PrivmsgCommand &operator=(PrivmsgCommand const &ref);		//no used

	protected:

		Server		*_server;

	public:

		PrivmsgCommand(Server* server);
		~PrivmsgCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
		
};

#endif
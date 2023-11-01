/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InviteCommand.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:27:29 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/01 16:46:10 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INVITECOMMAND_HPP
# define INVITECOMMAND_HPP

# include "Command.hpp"
# include "../Server.hpp"
# include "../Channel.hpp"

class InviteCommand : public Command
{
	private :

		InviteCommand(InviteCommand const &ref);				//no used
		InviteCommand &operator=(InviteCommand const &ref);		//no used

	protected:

		Server		*_server;

	public:

		InviteCommand(Server* server);
		~InviteCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
		
};

#endif
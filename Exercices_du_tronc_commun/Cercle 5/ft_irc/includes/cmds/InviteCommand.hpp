/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InviteCommand.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:27:29 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/30 15:36:27 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INVITECOMMAND_HPP
# define INVITECOMMAND_HPP

# include "../Server.hpp"

class InviteCommand : public Command
{
	private :

		InviteCommand(InviteCommand const &ref);				//no used
		InviteCommand &operator=(InviteCommand const &ref);		//no used

	protected:

		Server		*_server;

	public:

		InviteCommand(Server* sever);
		~InviteCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
		
};

#endif
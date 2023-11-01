/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JoinCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:41:04 by nours42           #+#    #+#             */
/*   Updated: 2023/11/01 16:46:11 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOINCOMMAND_HPP
# define JOINCOMMAND_HPP

# include "Command.hpp"
# include "../Server.hpp"
# include "../Channel.hpp"

class JoinCommand : public Command
{
	private :

		// JoinCommand(JoinCommand const &ref);				//no used
		// JoinCommand &operator=(JoinCommand const &ref);		//no used

	protected:

		Server		*_server;

	public:

		JoinCommand(Server* server);
		~JoinCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
		
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NickCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:45:43 by nours42           #+#    #+#             */
/*   Updated: 2023/11/01 16:45:09 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NICKCOMMAND_HPP
# define NICKCOMMAND_HPP

# include "Command.hpp"
# include "../Server.hpp"
# include "../Channel.hpp"

class NickCommand : public Command
{
	private :

		// NickCommand(NickCommand const &ref);				//no used
		// NickCommand &operator=(NickCommand const &ref);		//no used

	protected:

		Server		*_server;

	public:

		NickCommand(Server* server);
		~NickCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
		
};

#endif
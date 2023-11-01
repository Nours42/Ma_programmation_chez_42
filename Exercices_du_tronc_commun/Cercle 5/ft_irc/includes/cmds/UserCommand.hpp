/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:50:44 by nours42           #+#    #+#             */
/*   Updated: 2023/11/01 14:50:59 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USERCOMMAND_HPP
# define USERCOMMAND_HPP

# include "Command.hpp"
# include "Server.hpp"
# include "Channel.hpp"

class UserCommand : public Command
{
	private :

		// UserCommand(UserCommand const &ref);				//no used
		// UserCommand &operator=(UserCommand const &ref);		//no used

	protected:

		Server		*_server;

	public:

		UserCommand(Server* server);
		~UserCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
		
};

#endif
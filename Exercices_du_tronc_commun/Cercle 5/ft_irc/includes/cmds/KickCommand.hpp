/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KickCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:26:09 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/01 16:44:39 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KICKCOMMAND_HPP
# define KICKCOMMAND_HPP

# include "Command.hpp"
# include "../Server.hpp"
# include "../Channel.hpp"
# include "../Utils.hpp"

class KickCommand : public Command
{
	private :

		// KickCommand(KickCommand const &ref);				//no used
		// KickCommand &operator=(KickCommand const &ref);		//no used

	protected:

		Server		*_server;

	public:

		KickCommand(Server* sever);
		~KickCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
		
};

#endif
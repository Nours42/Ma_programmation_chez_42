/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VersionCommand.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:51:20 by nours42           #+#    #+#             */
/*   Updated: 2023/11/01 16:45:59 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERSIONCOMMAND_HPP
# define VERSIONCOMMAND_HPP

# include "Command.hpp"
# include "../Server.hpp"
# include "../Channel.hpp"

class VersionCommand : public Command
{
	private :

		// VersionCommand(VersionCommand const &ref);				//no used
		// VersionCommand &operator=(VersionCommand const &ref);		//no used

	protected:

		Server		*_server;

	public:

		VersionCommand(Server* server);
		~VersionCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
		
};

#endif
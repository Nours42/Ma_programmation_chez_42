/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PartCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:47:15 by nours42           #+#    #+#             */
/*   Updated: 2023/11/01 16:45:19 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARTCOMMAND_HPP
# define PARTCOMMAND_HPP

# include "Command.hpp"
# include "../Server.hpp"
# include "../Channel.hpp"

class PartCommand : public Command
{
	private :

		// PartCommand(PartCommand const &ref);				//no used
		// PartCommand &operator=(PartCommand const &ref);		//no used

	protected:

		Server		*_server;

	public:

		PartCommand(Server* server);
		~PartCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
		
};

#endif
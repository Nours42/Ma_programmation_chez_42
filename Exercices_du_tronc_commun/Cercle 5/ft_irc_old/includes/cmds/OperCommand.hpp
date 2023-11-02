/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:46:18 by nours42           #+#    #+#             */
/*   Updated: 2023/11/01 16:45:13 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERCOMMAND_HPP
# define OPERCOMMAND_HPP

# include "Command.hpp"
# include "../Server.hpp"
# include "../Channel.hpp"

class OperCommand : public Command
{
	private :

		// OperCommand(OperCommand const &ref);				//no used
		// OperCommand &operator=(OperCommand const &ref);		//no used

	protected:

		Server		*_server;

	public:

		OperCommand(Server* server);
		~OperCommand(void);

		bool onCommand(User* sender, std::vector<std::string> args);
		
};

#endif